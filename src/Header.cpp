#include<Header.h>
#include<string>
Header::Header()
{
this->isKeepAlive=0;
}

void Header::setContentType(string contentType)
{
this->contentType=contentType;
}

void Header::setContentLength(int length)
{
char temp[10];
sprintf(temp,"%d",length);
this->contentLength=temp;
}

void Header::keepAlive(int timeout,int max)
{
this->isKeepAlive=1;
char temp[10];
sprintf(temp,"%d",timeout);
this->timeout=temp;
sprintf(temp,"%d",max);
this->max=temp;
}

string Header::getHeader()
{
this->header="";
this->header+="HTTP/1.1 200 OK\n";
this->header+="Content-Type: ";
this->header+=this->contentType+"\n";
this->header+="Content-Length: ";
this->header+=this->contentLength+"\n";
if(this->isKeepAlive==1)
{
this->header+="Keep-Alive: timeout=";
this->header+=this->timeout;
this->header+=", max=";
this->header+=this->max+"\n";
}
this->header+="\n";
return this->header;
}



