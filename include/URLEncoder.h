#ifndef __URLEncoder__
#define __URLEncoder__ 12345
#include<string>
#include<map>
using namespace std;
class URLEncoder
{
private:
URLEncoder();
public:
static map<string,string> decode(string url);
static string encode(map<string,string> data);
};
#endif