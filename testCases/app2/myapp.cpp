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
void getCityView(Request &request,Response &response)
{
cout<<"getCityView being processed"<<endl;
string cityCodeString=request.get("cityCode");
cout<<"("<<cityCodeString<<")"<<endl;
int cityCode=atoi(cityCodeString.c_str());
cout<<"city code: "<<cityCode<<endl;
if(cityCode==1) request.forward("Ujjain.html");
else if(cityCode==2) request.forward("Indore1234.html");
else if(cityCode==3) request.forward("Dewas.html");
else 
{
request.setString("error","Invalid choice");
request.forward("errorPage");
}
}

void createErrorPage(Request &request,Response &response)
{
string errorMessage=request.getValue("error");
response.write("<!DOCTYPE html>");
response.write("<html lang='en'>");
response.write("<head>");
response.write("<meta charset='utf-8'>");
response.write("<title>The Clock</title>");
response.write("</head>");
response.write("<body>");
response.write("<h1>");
response.write(errorMessage);
response.write("</h1>");
response.write("</body>");
response.write("</html>");
response.close();
}

int main()
{
HCWebProjector server(5050);
server.onRequest("now",dispatchTime);
server.onRequest("getCity",getCityView);
//server.onRequest("errorPage",createErrorPage);
server.start();
return 0;
}