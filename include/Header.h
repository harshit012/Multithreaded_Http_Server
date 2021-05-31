#ifndef __Header__ 
#define __Header__ 12345
#include<string>
#include<stdio.h>
using namespace std;
class Header
{
private:
string header;
string contentType;
string contentLength;
string timeout;
string max;
int isKeepAlive;
public:
Header();
void setContentType(string contentType);
void setContentLength(int length);
void keepAlive(int timeout,int max);
string getHeader();
};
#endif
