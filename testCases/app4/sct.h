#ifndef __SCT
#define __SCT
#include<hcwp.h>

void getPqr_SCT(Request &request,Response &response)
{
response.write("<!DOCTYPE html>");
response.write("<html lang='en'>");
response.write("<head>");
response.write("<meta charset='utf-8'>");
response.write("<title>My first web application</title>");
response.write("</head>");
response.write("<body>");
response.write("<h1>");
response.write(request.getValue("heading"));
response.write("</h1>");
response.write("<form action='/one/saveData'>");
response.write(request.getValue("firstAttribute"));
response.write("<input type='text' id='nm' name='nm'><br>");
response.write(request.getValue("secondAttribute"));
response.write("<input type='text' id='ct' name='ct'>");
response.write("<span id='ctErrorSection'></span>");
response.write("<br>");
response.write(request.getValue("thirdAttribute"));
response.write("<input type='radio' id='ml' name='gdr' value=\"M\"> Male");
response.write("&nbsp;&nbsp;&nbsp;&nbsp;");
response.write("<input type='radio' id='fe' name='gdr' value=\"F\">Female<br>");
response.write("<button type='submit'>Save</button>");
response.write("</form>");
response.write("</body>");
response.write("</html>");

response.close();
}

void registerSCTs(HCWebProjector *server)
{
server->onRequest("/pqr.sct",getPqr_SCT);

}
#endif