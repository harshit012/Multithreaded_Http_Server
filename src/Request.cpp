#include<Request.h>

Request::Request(int clientSocketDescriptor,map<string,string> requestData)
{
this->requestData=requestData;
this->clientSocketDescriptor=clientSocketDescriptor;
}

string Request::get(string key)
{
return this->requestData[key];
}

int Request::getNumberOfAttributes()
{
return this->requestData.size();
}

void Request::forward(string request)
{
this->forwardedRequest=request;
}

string Request::getForwardedRequest()
{
return this->forwardedRequest;
}


void Request::setInt(string key,int value)
{
this->intData.insert(pair<string,int>(key,value));
}

int Request::getInt(string key)
{
if(this->intData.find(key)==this->intData.end()) return 0;
return this->intData[key];
}

void Request::setString(string key,string value)
{
this->stringData.insert(pair<string,string>(key,value));
}

string Request::getString(string key)
{
if(this->stringData.find(key)==this->stringData.end()) return "";
return this->stringData[key];
}

string Request::getValue(string key)
{
char value[10];
if(this->stringData.find(key)!=this->stringData.end()) return this->stringData[key];
else if(this->intData.find(key)!=this->intData.end())
{
sprintf(value,"%d",this->intData[key]);
return value;
}
else return "";
}
