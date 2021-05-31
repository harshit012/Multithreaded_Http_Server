#include<URLEncoder.h>

URLEncoder::URLEncoder()
{
}

map<string,string> URLEncoder::decode(string url)
{
map<string,string> resultMap;
char c;
string key("");
string value("");
int flag=0;
for(int i=0;i<url.size();i++)
{
c=url[i];
if(flag==0)
{
if(c=='=')
{
flag=1;
continue;
}
if(c=='+')
{
key+=' ';
continue;
}
key+=c;
}else
{
if(c=='&')
{
flag=0;
resultMap.insert(pair<string,string>(key,value));
key="";
value="";
continue;
}
if(c=='+')
{
value+=' ';
continue;
}
value+=c;
}
}//for loop braces
resultMap.insert(pair<string,string>(key,value));
return resultMap;
}


string URLEncoder::encode(map<string,string> data)
{
string resultString;
map<string,string>::iterator iter;
string key;
string value;
char c;
int count=0;
for(iter = data.begin();iter!=data.end();++iter)
{
if(count!=0) resultString+='&';
key=iter->first;
value=iter->second;
for(int e=0;e<key.size();e++)
{
c=key[e];
if(c==' ') resultString+='+';
else resultString+=c;
}
resultString+='=';
for(int f=0;f<value.size();f++)
{
c=value[f];
if(c==' ') resultString+='+';
else resultString+=c;
}
count++;
}
return resultString;
}
