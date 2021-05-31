#include<iostream>
#include<hcwp.h>
#include<ctime>
using namespace std;
void dispatchTime(Request &request,Response &response)
{
time_t t=time(0);
char *now=ctime(&t);
response.write("<!DOCTYPE html>");
response.write("<html lang='en'>");
response.write("<head>");
response.write("<meta charset='utf-8'>");
response.write("<title>The Clock</title>");
response.write("</head>");
response.write("<body>");
response.write("<h1>");
response.write(now);
response.write("</h1>");
response.write("<a href='now'>Refresh</a>");
response.write("<a href='index.html'>Home</a>");
response.write("</body>");
response.write("</html>");
response.close();
}
int main()
{
HCWebProjector server(5050);
server.onRequest("now",dispatchTime);
server.start();
return 0;
}