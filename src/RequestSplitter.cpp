#include<RequestSplitter.h>
RequestSplitter::RequestSplitter(string data)
{
this->data=data;
this->request="";
this->requestType="";
this->requestData="";
this->extension="";
doProcessing();
}

void RequestSplitter::doProcessing()
{
int e=0;
int qFound=0;
while(this->data[e]!=' ')
{
this->requestType+=this->data[e];
e++;
}
e++;
while(this->data[e]!=' ')
{
if(this->data[e]=='?')
{
e++;
while(this->data[e]!=' ')
{
this->requestData+=this->data[e];
e++;
}
break;
}
this->request+=this->data[e];
e++;
}
e=0;
while(this->request[e]!='.') {e++;}
e++;
while(e<this->request.size())
{
this->extension+=this->request[e];
e++;
}
e=1;
while(e<this->request.size()) { fileName+=this->request[e]; e++; }
}

string RequestSplitter::getRequest()
{
return this->request;
}

string RequestSplitter::getRequestType()
{
return this->requestType;
}

string RequestSplitter::getRequestData()
{
return this->requestData;
}

string RequestSplitter::getExtension()
{
return this->extension;
}

string RequestSplitter::getFileName()
{
return this->fileName;
}
