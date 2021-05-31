#ifndef __Response__
#define __Response__ 12345
#include<string>
#include<windows.h>
#include<Header.h>
using namespace std;
class Response
{
private:
string buffer;
string contentType;
int clientSocketDescriptor;
Header header;
public:
Response(int);
void setContentType(string);
void write(string);
void close();
};
#endif