#ifndef __Utility__
#define __Utility__ 12345
#include<string>
using namespace std;
class Utility
{
private:
Utility();
public:
static int getRequestType(string);
static string getExtension(string);
};
#endif