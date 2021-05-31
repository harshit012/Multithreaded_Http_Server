#ifndef __Model__
#define __Model__ 12345
#include<list>
#include<map>
#include<string>
#include<stdio.h>
#include<Request.h>
#include<ServletInfo.h>
using namespace std;

class Model
{
private:
list<string> files;
map<int,string> error;
map<string,string> mimeTypes;
map<string,ServletInfo> servlets;
public:
Model();
void populateDS();
string getErrorHeading(int errorCode);
string getErrorDetails(int errorCode);
string getErrorResponse(int errorCode);
string getMimeType(string extension);
void setServlet(string request,ServletInfo servletInfo);
int servletExists(string request);
ServletInfo getServlet(string request);
};
#endif