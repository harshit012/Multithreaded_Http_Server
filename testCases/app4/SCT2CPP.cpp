#include<iostream>
#include<dirent.h>
#include<string>
#include<algorithm>
#include<string.h>
#include<vector>
#include<stdio.h>
using namespace std;

void createHeaderFile(vector<string> listOfFiles)
{
int pos;
string buffer("");
string header("#ifndef __SCT\r\n#define __SCT\r\n#include<hcwp.h>\r\n\r\n");
string methodPrototype="";
FILE *f=fopen("sct.h","w");
fputs(header.c_str(),f);
methodPrototype="";


char preSyntax[20],prev;
char postSyntax[10];
strcpy(preSyntax,"response.write(\"");
strcpy(postSyntax,"\");\r\n");
string footer("\r\nresponse.close();\r\n}\r\n");
FILE *fr;
string fwName("");
int flag1=0,flag2=0;
char c;



for(string fileName:listOfFiles)
{
fwName+=fileName;
fwName+=".cpp";
methodPrototype="void get";
pos=fileName.find('.');
if(fileName[0]>=97 && fileName[0]<=122) methodPrototype+=fileName[0]-32;
else methodPrototype+=fileName[0];
methodPrototype+=fileName.substr(1,pos-1);
methodPrototype+="_SCT(Request &request,Response &response)\r\n{\r\n";
fr=fopen(fileName.c_str(),"r");
fputs(methodPrototype.c_str(),f);
while(1)
{
c=fgetc(fr);
if(feof(fr))
{
break;
}
if(c=='$')
{
prev=c;
continue;
}

if(prev=='$' && c=='{')
{
flag1=1;
if(flag2==1)
{
fputs(postSyntax,f);
flag2=0;
}
prev=c;
continue;
}
if(flag1==1)
{
if(c!='}') buffer+=c;
else
{
fputs("response.write(request.getValue(\"",f);
if(buffer[0]!='\n') fputs(buffer.c_str(),f);
else fputs(buffer.substr(1).c_str(),f);
fputs("\"));\r\n",f);
flag1=0;
buffer="";
}
prev=c;
continue;
}
if(flag1==0)
{
if(prev=='\n' && c=='\n') continue;
if(flag2==1 && c=='\n')
{
fputs(postSyntax,f);
flag2=0;
prev=c;
continue;
}
if(flag2==0)
{
fputs(preSyntax,f);
flag2=1;
}
if(c==34)
{
c=92;
fputc(c,f);
c=34;
fputc(c,f);
continue;
}
if(c!='\n') fputc(c,f);
prev=c;
}
}
if(flag2==1)
{
fputs(postSyntax,f);
flag2=0;
}
fputs(footer.c_str(),f);
fclose(fr);
header="";
fwName="";
methodPrototype="";
flag1=0;
}



methodPrototype="";
buffer="\r\nvoid registerSCTs(HCWebProjector *server)\r\n{\r\n";
footer="#endif";
fputs(buffer.c_str(),f);
buffer="server->onRequest(\"/";
methodPrototype="";
for(string fileName:listOfFiles)
{
fputs(buffer.c_str(),f);
fputs(fileName.c_str(),f);
fputc(34,f);
fputc(',',f);
methodPrototype="get";
pos=fileName.find('.');
if(fileName[0]>=97 && fileName[0]<=122) methodPrototype+=fileName[0]-32;
else methodPrototype+=fileName[0];
methodPrototype+=fileName.substr(1,pos-1);
methodPrototype+="_SCT);\r\n";
fputs(methodPrototype.c_str(),f);
methodPrototype="";
}
buffer="\r\n}\r\n";
fputs(buffer.c_str(),f);


fputs(footer.c_str(),f);
fclose(f);
}


int main()
{
vector<string> listOfFiles;
char path[100];
struct dirent *entry;
DIR *dir=opendir(getcwd(path,100));
if(dir==NULL)
{
cout<<"Invalid directory:"<<endl;
return 0;
}
while((entry=readdir(dir))!=NULL)
{
string name(entry->d_name);
if(name.find(".sct")!=-1 && name.find(".cpp")==-1) listOfFiles.push_back(name);
}
closedir(dir);
cout<<"_____________________________"<<endl;
cout<<"Generating 'sct.h' file for:"<<endl;
cout<<"_____________________________"<<endl;
for(string name:listOfFiles) cout<<name<<endl;
createHeaderFile(listOfFiles);
cout<<"_____________________________"<<endl;
cout<<"sct.h file generated"<<endl;
cout<<"_____________________________"<<endl;

return 0;
}