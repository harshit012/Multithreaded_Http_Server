#include<iostream>
#include<thread>
#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include<thread>
#include<model.h>
using namespace  std;

class ThreadManager
{
private:
int portNumber;
int clientSocketDescriptor;
struct sockaddr_in clientSocketInformation;
int serverSocketDescriptor;
char responseBuffer[1025];
char requestBuffer[8193];
Model *model;
thread *t;
void(*ptr)(int,struct sockaddr_in,int,int,char *,char*,Model *);

public:
ThreadManager(void(*ptr)(int,struct sockaddr_in,int,int,char *,char*,Model *),int clientSocketDescriptor,struct sockaddr_in clientSocketInformation,int serverSocketDescriptor,int portNumber,char *requestBuffer,char* responseBuffer,Model *model);
void start();
~ThreadManager();
};
