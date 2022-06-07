#include<ThreadManager.h>


ThreadManager::ThreadManager(void(*ptr)(int,struct sockaddr_in,int,int,char *,char*,Model *),int clientSocketDescriptor,struct sockaddr_in clientSocketInformation,int serverSocketDescriptor,int portNumber,char *requestBuffer,char* responseBuffer,Model *model)
{
this->ptr=ptr;
this->clientSocketDescriptor=clientSocketDescriptor;
this->clientSocketInformation=clientSocketInformation;
this->serverSocketDescriptor=serverSocketDescriptor;
this->portNumber=portNumber;
strcpy(this->requestBuffer,requestBuffer);
strcpy(this->responseBuffer,responseBuffer);
this->model=model;
this->t=NULL;
}

void ThreadManager::start()
{
thread tt(this->ptr,this->clientSocketDescriptor,clientSocketInformation,this->serverSocketDescriptor,this->portNumber,this->requestBuffer,this->responseBuffer,this->model);
tt.detach();
}

ThreadManager::~ThreadManager()
{

}
