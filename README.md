# Multithreaded_Http_Server
This is a multithreaded web server that works on HTTP protocol. Now the user can create the web application in the c++ programming language.

## Features
* Process multiple requests simultaneously.
* Feature of S.C.T.(Server-side c++ template).
* Sharing of extremely large files.
* Easy to use and configure.
* Handling of AJAX request.

## Steps to create the web application in c++
1) Download the library file "hcwplib.lib" & header files.
2) Place the library files in the lib folder and header files to the folder named include.
3) Now create the working folder for your application on your machine.
4) Write the basic c++ code to start the server as shown below:
```
#include<hcwp.h>
#include<iostream>
using namespace std;
int main()
{
HCWebProjector server(5050);
server.start();
return 0;
}
```
5) Compile the above code with including all header files and give the appropriate path of the "hcwplib.lib" library file.
6) The executable file is generated now. To start the server just simply run that executable file.
7) Now the server has been started and is listening on the port number 5050.
8) Now create a file name as index.html in the same working folder where the server runs as shown below.
```
<!DOCTYPE html>
<html lang='en'>
<head>
<meta charset='utf-8'>
<title>My first web application in c++</title>
</head>
<body>
<center>
<h1>Cool</h1>
</center>
</body>
</html>
```
9) Open any Web browser and type the URL "localhost:5050/index.html"
10) If the index.html file is present then the web page will be displayed otherwise it will show error 404.

_______________________________________________________________________________________________________________________
 
 ## Description about the methods:
 
 * **onRequest**
 
 Prototype : void onRequest(char \* url,void(\*ptr)(Request&,Response&));

 Syntax:
 ```
 #include<hcwp.h>
#include<iostream>
#include"sct.h"
using namespace std;
void doSomething(Request &request,Response &response)
{
cout<<"doSomething got invoked"<<endl;
}
int main()
{
HCWebProjector server(5050);
server.onRequest("kkk",doSomething);
server.start();
return 0;
}
 ```
 Here, whenever the request is arrived for "/kkk" then this doSomething method will be invoked.
 ________________________________________________________________________________________________________________________________________________________
 * **forward**
 
 Prototype : void forward(char\* url);
 
 Syntax:
 ```
 #include<hcwp.h>
#include<iostream>
#include"sct.h"
using namespace std;
void doSomething(Request &request,Response &response)
{
cout<<"doSomething got invoked"<<endl;
request.forward("/pqr");
}
void justDoIt(Request &request,Response &response)
{
cout<<"Just do it got invoked"<<endl;
request.forward("/abc.html");
}
int main()
{
HCWebProjector server(5050);
server.onRequest("kkk",doSomething);
server.onRequest("pqr",justDoIt);
server.start();
return 0;
}
 ```
Whenever the request has arrived for "/kkk" then this doSomething method will be invoked. Then the request has been forwarded to /kkk which is mapped to the justDoIt function so the justDoIt function will be invoked. Then from the body of justDoIt, the request has been forwarded to abc.html, so the contents of abc.html are served to the client-side.
 ________________________________________________________________________________________________________________________________________________________
 
 * **setString** ,  **setInt** , **getString** , **getInt** , **getValue**
 
 Prototype : void setString(char* key,char\* value);
 
 Prototype : void setInt(char* key,int value);
 
 Prototype : string getString(char* key);
 
 Prototype : int getInt(char* key);
 
 Prototype : string getValue(char* key);
 
 Syntax:
 ```
  #include<hcwp.h>
#include<iostream>
#include"sct.h"
using namespace std;
void doSomething(Request &request,Response &response)
{
cout<<"doSomething got invoked"<<endl;
request.setString("title","Covid-19 Vaccination");
request.forward("/pqr");
}
void justDoIt(Request &request,Response &response)
{
cout<<"title : "<<request.get("title")<<endl;
request.forward("/abc.html");
}
int main()
{
HCWebProjector server(5050);
server.onRequest("kkk",doSomething);
server.onRequest("pqr",justDoIt);
server.start();
return 0;
}
 ```
You can put some data in request scope as key value map with the help of this setters and getters. For dealing with string you can use setString/getString for int datatype you can use setInt/getInt. getValue method will first check for the existence of key in intMap then for the stringMap.

 _________________________________________________________________________________________________________________________________________________________________
 
 * **write**

Prototype : void write(char* data);

Syntax:

Program from my first example app1 in test folder:
```
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
```

When the request arrives for this function then it will return this HTML page as a response.

**NOTE: close method must be invoked at the end if you have used the write method.**
 _________________________________________________________________________________________________________________________________________________________________
 
 ## Working with Templates (Server-side c++ template)
Why use the templates?

Let's take a scenario If you are creating an application where the result of students can be displayed. If you do hard-code in the HTML file, then you have to create a separate HTML file for each student. To avoid this we can use the concept of template, We can simply create only one file whose extension should be "sct" & the file contains the necessary HTML code. Now some fields in that file are dynamic like the name of the students his marks, etc. Instead of doing hard-code for such values, we will use ${key_name} 

The below code is from app4. Where I've created a generic form template.
```
<!DOCTYPE html>
<html lang='en'>
<head>
<meta charset='utf-8'>
<title>My first web application</title>
</head>
<body>
<h1>${heading}</h1>
<form action='/one/saveData'>
${firstAttribute}
<input type='text' id='nm' name='nm'><br>
${secondAttribute}
<input type='text' id='ct' name='ct'>
<span id='ctErrorSection'></span>
<br>
${thirdAttribute}
<input type='radio' id='ml' name='gdr' value="M"> Male
&nbsp;&nbsp;&nbsp;&nbsp;
<input type='radio' id='fe' name='gdr' value="F">Female<br>
<button type='submit'>Save</button>
</form>
</body>
</html>
```
This is the file "pqr.sct". After creating the templates, you need to execute the SCT2CPP.exe file before starting the server. Then the tool SCT2CPP will generate "sct.h" file. 

Then you have to do some changes in you main cpp file, as shown below :
```
#include<hcwp.h>
#include<iostream>
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

```
**Explanation : **

You need to include "sct.h" file. Before starting the server just invoke the method registerSCTs & pass it the reference of the server as shown above. when the request has arrived for "/getForm" the doSomething method will be invoked. from doSomething I will put some values in the request scope through setString method & then I forwarded the request to that pqr.sct template now all those key in the template will replace with my given values.
