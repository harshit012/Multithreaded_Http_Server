#include<hcwp.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<FileReader.h>
#include<Header.h>
#include<Model.h>
#include<RequestSplitter.h>
#include<URLEncoder.h>
#include<Request.h>
#include<Response.h>
#include<ServletInfo.h>
#include<string>
#include<utility.h>
#include<thread>
#include<list>
#include<ThreadManager.h>
using namespace std;

HCWebProjector::HCWebProjector(int portNumber)
{
this->model=new Model();
this->portNumber=portNumber;
}

HCWebProjector::~HCWebProjector()
{
delete this->model;
}

void HCWebProjector::onRequest(string onRequest,void (*pr)(Request&,Response&))
{
ServletInfo servletInfo;
servletInfo.request=onRequest;
servletInfo.fn=pr;
this->model->setServlet(onRequest,servletInfo);
}





void requestProcessor(int clientSocketDescriptor,struct sockaddr_in clientSocketInformation,int serverSocketDescriptor,int portNumber,char *requestBuffer,char* responseBuffer,Model *model)
{
int len;
RequestSplitter rs(requestBuffer);
string requestFor=rs.getFileName();
int requestType=Utility::getRequestType(requestFor);
if(requestType==1)
{
HCWebProjector::sendFile(requestFor,clientSocketDescriptor,model,responseBuffer);
}
if(requestType==2)
{
Request request(clientSocketDescriptor,URLEncoder::decode(rs.getRequestData()));
Response response(clientSocketDescriptor);
while(1)
{
HCWebProjector::forwardRequestToServlet(requestFor,request,response,clientSocketDescriptor,model,responseBuffer);
if(request.getForwardedRequest().size()==0) break;
else
{
requestFor=request.getForwardedRequest();
requestType=Utility::getRequestType(requestFor);
if(requestType==1)
{
HCWebProjector::sendFile(requestFor,clientSocketDescriptor,model,responseBuffer);
break;
}
if(requestType==3)
{
HCWebProjector::sendSCT(requestFor,request,response,clientSocketDescriptor,model,responseBuffer);
break;
}
request.forward("");
}
}
}
closesocket(clientSocketDescriptor);
}





void HCWebProjector::sendError(int errorCode,int clientSocketDescriptor,Model *model,char* responseBuffer)
{
int len;
Header header;
string error=model->getErrorResponse(errorCode);
len=error.size();
header.setContentLength(len);
header.setContentType("text/html");
strcpy(responseBuffer,header.getHeader().c_str());
send(clientSocketDescriptor,responseBuffer,strlen(responseBuffer),0);
strcpy(responseBuffer,error.c_str());
send(clientSocketDescriptor,responseBuffer,len,0);
}

void HCWebProjector::sendFile(string fileName,int clientSocketDescriptor,Model *model,char* responseBuffer)
{
Header header;
int len;
FileReader fr(fileName,1024);
if(fr.fileExists())
{
header.setContentLength(fr.getSize());
header.setContentType(model->getMimeType(Utility::getExtension(fileName)));
send(clientSocketDescriptor,header.getHeader().c_str(),strlen(header.getHeader().c_str()),0);
while(fr.hasNext())
{
len=fr.next(responseBuffer);
send(clientSocketDescriptor,responseBuffer,len,0);
}
}
else
{
if(fileName=="favicon.ico")
{
return;
}
cout<<"File :"<<fileName<<" not found"<<endl;
sendError(404,clientSocketDescriptor,model,responseBuffer);
}
}


void HCWebProjector::forwardRequestToServlet(string servlet,Request& request,Response& response,int clientSocketDescriptor,Model *model,char* responseBuffer)
{
if(model->servletExists(servlet))
{
model->getServlet(servlet).fn(request,response);
}
else
{
cout<<"Invalid servlet"<<servlet<<endl;
sendError(500,clientSocketDescriptor,model,responseBuffer);
}
}


void HCWebProjector::sendSCT(string servlet,Request& request,Response& response,int clientSocketDescriptor,Model *model,char* responseBuffer)
{
if(model->servletExists(servlet))
{
model->getServlet(servlet).fn(request,response);
}
else
{
cout<<"Invalid servlet"<<servlet<<endl;
sendError(500,clientSocketDescriptor,model,responseBuffer);
}
}





void HCWebProjector::start()
{
list<ThreadManager> threadList;
int len;
int bytesReceived;
WORD      ver;
WSADATA wsaData;
int serverSocketDescriptor;
int clientSocketDescriptor;
int successCode;
struct sockaddr_in serverSocketInformation;
struct sockaddr_in clientSocketInformation;
ver=MAKEWORD(1,1);
WSAStartup(ver,&wsaData); //   socket library initialized
serverSocketDescriptor=socket(AF_INET,SOCK_STREAM,0);
if(serverSocketDescriptor<0)
{
return;
}
serverSocketInformation.sin_family=AF_INET;
serverSocketInformation.sin_port=htons(this->portNumber);
serverSocketInformation.sin_addr.s_addr=htonl(INADDR_ANY);
successCode=bind(serverSocketDescriptor,(struct sockaddr *)&serverSocketInformation,sizeof(serverSocketInformation));
if(successCode<0)
{
WSACleanup();
return;
}

while(1)
{
cout<<"***********************************************************************************************"<<endl;
listen(serverSocketDescriptor,10);
cout<<"Server is ready, and is listening at port number "<<this->portNumber<<endl;
len=sizeof(clientSocketInformation);
clientSocketDescriptor=accept(serverSocketDescriptor,(struct sockaddr *)&clientSocketInformation,&len);
if(clientSocketDescriptor<0)
{
cout<<"Unable to accept client connection"<<endl;
closesocket(serverSocketDescriptor);
WSACleanup();
return;
}
bytesReceived=recv(clientSocketDescriptor,this->requestBuffer,8192,0);
if(bytesReceived>0)
{
this->requestBuffer[bytesReceived]='\0';
cout<<this->requestBuffer<<endl;
}

ThreadManager threadManager(requestProcessor,clientSocketDescriptor,clientSocketInformation,serverSocketDescriptor,this->portNumber,requestBuffer,responseBuffer,this->model);
threadManager.start();
//requestProcessor(clientSocketDescriptor,clientSocketInformation,serverSocketDescriptor,portNumber,requestBuffer,responseBuffer,model);
}
closesocket(serverSocketDescriptor);
WSACleanup();
return;
}


