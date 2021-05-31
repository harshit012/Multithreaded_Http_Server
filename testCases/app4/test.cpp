#include<hcwp.h>
#include<iostream>
#include<Request.h>
#include<Response.h>
#include<string>
#include"sct.h"
using namespace std;

void doSomething(Request &request,Response &response)
{
cout<<"############doSomething got invoked"<<endl;
request.setString("heading","Student details form");
request.setString("firstAttribute","Name");
request.setString("secondAttribute","City");
request.setString("thirdAttribute","Gender");
request.forward("/pqr.sct");
}


int main()
{
HCWebProjector server(5050);
server.onRequest("getForm",doSomething);
registerSCTs(&server);
server.start();
return 0;
}
