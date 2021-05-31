#include<Utility.h>
Utility::Utility()
{
}
int Utility::getRequestType(string request)
{
int e=request.find(".");
if(e>=0 && e<request.size())
{
e=request.find(".sct");
if(e>=0 && e<request.size()) return 3;
return 1;
}
return 2;
}

string Utility::getExtension(string fileName)
{
int e=fileName.find(".");
string extension;
for(e=e+1;e<fileName.size();e++)
{
extension+=fileName[e];
}
return extension;
}