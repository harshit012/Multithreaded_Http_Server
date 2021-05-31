#ifndef __ServletInfo__
#define __ServletInfo__ 12345
#include<Request.h>
#include<Response.h>
#include<string>
using namespace std;
class ServletInfo
{
public:
string request;
void (*fn)(Request&,Response&);
};
#endif