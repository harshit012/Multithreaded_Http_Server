#ifndef __RequestSplitter__
#define __RequestSplitter__ 12345
#include<string>
#include<stdio.h>
using namespace std;

class RequestSplitter
{
private:
string data;
string fileName;
string request;
string requestType;
string extension;
string requestData;

public:
RequestSplitter(string data);
void doProcessing();
string getRequest();
string getRequestType();
string getExtension();
string getFileName();
string getRequestData();
};
#endif

