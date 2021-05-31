#ifndef __hcwp__
#define __hcwp__ 12345
#include<windows.h>
#include<string>
#include<Request.h>
#include<Model.h>
using namespace std;
class HCWebProjector
{
private:
Model *model;
int portNumber;
char responseBuffer[1025];
char requestBuffer[8193];
public:
HCWebProjector(int portNumber);
~HCWebProjector();
void onRequest(string,void (*pr)(Request&,Response&));
void start();
static void sendError(int errorCode,int clientSocketDescriptor,Model *model,char* responseBuffer);
static void sendFile(string fileName,int clientSocketDescriptor,Model *model,char* responseBuffer);
static void forwardRequestToServlet(string servlet,Request& request,Response& response,int clientSocketDescriptor,Model *model,char* responseBuffer);
static void sendSCT(string servlet,Request& request,Response& response,int clientSocketDescriptor,Model *model,char* responseBuffer);
};
#endif