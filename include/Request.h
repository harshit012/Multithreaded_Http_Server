#ifndef __Request__ 
#define __Request__ 12345
#include<map>
#include<string>
#include<windows.h>
using namespace std;
class Request
{
private:
map<string,int> intData;
map<string,string> stringData;
map<string,string> requestData;
int clientSocketDescriptor;
string forwardedRequest;
public:
Request(int,map<string,string>);
string get(string key);
int getNumberOfAttributes();
void forward(string request);
string getForwardedRequest();
void setInt(string key,int value);
int getInt(string key);
void setString(string key,string value);
string getString(string key);
string getValue(string key);
};

#endif