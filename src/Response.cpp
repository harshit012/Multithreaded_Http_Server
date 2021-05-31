#include<Response.h>
#include<iostream>
Response::Response(int clientSocketDescriptor)
{
this->clientSocketDescriptor=clientSocketDescriptor;
this->contentType="";
this->buffer="";
}
void Response::setContentType(string contentType)
{
this->contentType=contentType;
}
void Response::write(string text)
{
this->buffer+=text;
}
void Response::close()
{
if(this->contentType.size()==0) this->contentType="text/html";
this->header.setContentLength(this->buffer.size());
this->header.setContentType("text/html");
string header=this->header.getHeader();
string content=this->buffer;
send(clientSocketDescriptor,header.c_str(),header.size(),0);
send(clientSocketDescriptor,content.c_str(),content.size(),0);
}