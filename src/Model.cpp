#include<Model.h>
#include<string>
using namespace std;
Model::Model()
{
populateDS();
}

void Model::populateDS()
{
this->mimeTypes.insert(pair<string,string>("aac","audio/aac"));
this->mimeTypes.insert(pair<string,string>("abw","application/x-abiword"));
this->mimeTypes.insert(pair<string,string>("arc","application/x-freearc"));
this->mimeTypes.insert(pair<string,string>("avi","video/x-msvideo"));
this->mimeTypes.insert(pair<string,string>("azw","application/vnd.amazon.ebook"));
this->mimeTypes.insert(pair<string,string>("bin","application/octet-stream"));
this->mimeTypes.insert(pair<string,string>("bmp","image/bmp"));
this->mimeTypes.insert(pair<string,string>("bz","application/x-bzip"));
this->mimeTypes.insert(pair<string,string>("bz2","application/x-bzip2"));
this->mimeTypes.insert(pair<string,string>("csh","application/x-csh"));
this->mimeTypes.insert(pair<string,string>("css","text/css"));
this->mimeTypes.insert(pair<string,string>("csv","text/csv"));
this->mimeTypes.insert(pair<string,string>("doc","application/msword"));
this->mimeTypes.insert(pair<string,string>("docx","application/vnd.openxmlformats-officedocument.wordprocessingml.document"));
this->mimeTypes.insert(pair<string,string>("eot","application/vnd.ms-fontobject"));
this->mimeTypes.insert(pair<string,string>("epub","application/epub+zip"));
this->mimeTypes.insert(pair<string,string>("gz","application/gzip"));
this->mimeTypes.insert(pair<string,string>("gif","image/gif"));
this->mimeTypes.insert(pair<string,string>("htm","text/html"));
this->mimeTypes.insert(pair<string,string>("html","text/html"));
this->mimeTypes.insert(pair<string,string>("ico","image/vnd.microsoft.icon"));
this->mimeTypes.insert(pair<string,string>("ics","text/calendar"));
this->mimeTypes.insert(pair<string,string>("jar","application/java-archive"));
this->mimeTypes.insert(pair<string,string>("jpeg","image/jpeg"));
this->mimeTypes.insert(pair<string,string>("jpg","image/jpeg"));
this->mimeTypes.insert(pair<string,string>("js","text/javascript"));
this->mimeTypes.insert(pair<string,string>("json","application/json"));
this->mimeTypes.insert(pair<string,string>("jsonld","application/ld+json"));
this->mimeTypes.insert(pair<string,string>("mid","audio/midi audio/x-midi"));
this->mimeTypes.insert(pair<string,string>("midi","audio/midi audio/x-midi"));
this->mimeTypes.insert(pair<string,string>("mjs","text/javascript"));
this->mimeTypes.insert(pair<string,string>("mp3","audio/mpeg"));
this->mimeTypes.insert(pair<string,string>("mpeg","video/mpeg"));
this->mimeTypes.insert(pair<string,string>("mpkg","application/vnd.apple.installer+xml"));
this->mimeTypes.insert(pair<string,string>("odp","application/vnd.oasis.opendocument.presentation"));
this->mimeTypes.insert(pair<string,string>("ods","application/vnd.oasis.opendocument.spreadsheet"));
this->mimeTypes.insert(pair<string,string>("odt","application/vnd.oasis.opendocument.text"));
this->mimeTypes.insert(pair<string,string>("oga","audio/ogg"));
this->mimeTypes.insert(pair<string,string>("ogv","video/ogg"));
this->mimeTypes.insert(pair<string,string>("ogx","application/ogg"));
this->mimeTypes.insert(pair<string,string>("opus","audio/opus"));
this->mimeTypes.insert(pair<string,string>("otf","font/otf"));
this->mimeTypes.insert(pair<string,string>("png","image/png"));
this->mimeTypes.insert(pair<string,string>("pdf","application/pdf"));
this->mimeTypes.insert(pair<string,string>("php","application/x-httpd-php"));
this->mimeTypes.insert(pair<string,string>("ppt","application/vnd.ms-powerpoint"));
this->mimeTypes.insert(pair<string,string>("pptx","application/vnd.openxmlformats-officedocument.presentationml.presentation"));
this->mimeTypes.insert(pair<string,string>("rar","application/vnd.rar"));
this->mimeTypes.insert(pair<string,string>("rtf","application/rtf"));
this->mimeTypes.insert(pair<string,string>("sh","application/x-sh"));
this->mimeTypes.insert(pair<string,string>("svg","image/svg+xml"));
this->mimeTypes.insert(pair<string,string>("swf","application/x-shockwave-flash"));
this->mimeTypes.insert(pair<string,string>("tar","application/x-tar"));
this->mimeTypes.insert(pair<string,string>("tif","image/tiff"));
this->mimeTypes.insert(pair<string,string>("tiff","image/tiff"));
this->mimeTypes.insert(pair<string,string>("ts","video/mp2t"));
this->mimeTypes.insert(pair<string,string>("ttf","font/ttf"));
this->mimeTypes.insert(pair<string,string>("txt","text/plain"));
this->mimeTypes.insert(pair<string,string>("vsd","application/vnd.visio"));
this->mimeTypes.insert(pair<string,string>("wav","audio/wav"));
this->mimeTypes.insert(pair<string,string>("weba","audio/webm"));
this->mimeTypes.insert(pair<string,string>("webm","video/webm"));
this->mimeTypes.insert(pair<string,string>("webp","image/webp"));
this->mimeTypes.insert(pair<string,string>("woff","font/woff"));
this->mimeTypes.insert(pair<string,string>("woff2","font/woff2"));
this->mimeTypes.insert(pair<string,string>("xhtml","application/xhtml+xml"));
this->mimeTypes.insert(pair<string,string>("xls","application/vnd.ms-excel"));
this->mimeTypes.insert(pair<string,string>("xlsx","application/vnd.openxmlformats-officedocument.spreadsheetml.sheet"));
this->mimeTypes.insert(pair<string,string>("xml","application/xml"));
this->mimeTypes.insert(pair<string,string>("xul","application/vnd.mozilla.xul+xml"));
this->mimeTypes.insert(pair<string,string>("zip","application/zip"));
this->mimeTypes.insert(pair<string,string>("3gp","video/3gpp"));
this->mimeTypes.insert(pair<string,string>("3g2","video/3gpp2"));
this->mimeTypes.insert(pair<string,string>("7z","application/x-7z-compressed"));


this->error.insert(pair<int,string>(400,"Bad Request*The server could not understand the request due to invalid syntax."));
this->error.insert(pair<int,string>(401,"Unauthorized*Although the HTTP standard specifies \"unauthorized\", semantically this response means \"unauthenticated\". That is, the client must authenticate itself to get the requested response."));
this->error.insert(pair<int,string>(402,"Payment Required *This response code is reserved for future use. The initial aim for creating this code was using it for digital payment systems, however this status code is used very rarely and no standard convention exists."));
this->error.insert(pair<int,string>(403,"Forbidden*The client does not have access rights to the content; that is, it is unauthorized, so the server is refusing to give the requested resource. Unlike 401, the client's identity is known to the server."));
this->error.insert(pair<int,string>(404,"Not Found*The server can not find the requested resource. In the browser, this means the URL is not recognized. In an API, this can also mean that the endpoint is valid but the resource itself does not exist. Servers may also send this response instead of 403 to hide the existence of a resource from an unauthorized client. This response code is probably the most famous one due to its frequent occurrence on the web."));
this->error.insert(pair<int,string>(405,"Method Not Allowed*The request method is known by the server but has been disabled and cannot be used. For example, an API may forbid DELETE-ing a resource. The two mandatory methods, GET and HEAD, must never be disabled and should not return this error code."));
this->error.insert(pair<int,string>(406,"Not Acceptable*This response is sent when the web server, after performing server-driven content negotiation, doesn't find any content that conforms to the criteria given by the user agent."));
this->error.insert(pair<int,string>(407,"Proxy Authentication Required*This is similar to 401 but authentication is needed to be done by a proxy."));
this->error.insert(pair<int,string>(408,"Request Timeout*This response is sent on an idle connection by some servers, even without any previous request by the client. It means that the server would like to shut down this unused connection. This response is used much more since some browsers, like Chrome, Firefox 27+, or IE9, use HTTP pre-connection mechanisms to speed up surfing. Also note that some servers merely shut down the connection without sending this message."));
this->error.insert(pair<int,string>(409,"Conflict*This response is sent when a request conflicts with the current state of the server."));
this->error.insert(pair<int,string>(410,"Gone*This response is sent when the requested content has been permanently deleted from server, with no forwarding address. Clients are expected to remove their caches and links to the resource. The HTTP specification intends this status code to be used for \"limited-time, promotional services\". APIs should not feel compelled to indicate resources that have been deleted with this status code."));
this->error.insert(pair<int,string>(411,"Length Required*Server rejected the request because the Content-Length header field is not defined and the server requires it."));
this->error.insert(pair<int,string>(412,"Precondition Failed*The client has indicated preconditions in its headers which the server does not meet."));
this->error.insert(pair<int,string>(413,"Payload Too Large*Request entity is larger than limits defined by server; the server might close the connection or return an Retry-After header field."));
this->error.insert(pair<int,string>(414,"URI Too Long*The URI requested by the client is longer than the server is willing to interpret."));
this->error.insert(pair<int,string>(415,"Unsupported Media Type*The media format of the requested data is not supported by the server, so the server is rejecting the request."));
this->error.insert(pair<int,string>(416,"Range Not Satisfiable*The range specified by the Range header field in the request can't be fulfilled; it's possible that the range is outside the size of the target URI's data."));
this->error.insert(pair<int,string>(417,"Expectation Failed*This response code means the expectation indicated by the Expect request header field can't be met by the server."));
this->error.insert(pair<int,string>(418,"I'm a teapot*The server refuses the attempt to brew coffee with a teapot."));
this->error.insert(pair<int,string>(421,"Misdirected Request*The request was directed at a server that is not able to produce a response. This can be sent by a server that is not configured to produce responses for the combination of scheme and authority that are included in the request URI."));
this->error.insert(pair<int,string>(422,"Unprocessable Entity (WebDAV)*The request was well-formed but was unable to be followed due to semantic error."));
this->error.insert(pair<int,string>(423,"Locked (WebDAV)*The resource that is being accessed is locked."));
this->error.insert(pair<int,string>(424,"Failed Dependency (WebDAV)*The request failed due to failure of a previous request."));
this->error.insert(pair<int,string>(425,"Too Early *Indicates that the server is unwilling to risk processing a request that might be replayed."));
this->error.insert(pair<int,string>(426,"Upgrade Required*The server refuses to perform the request using the current protocol but might be willing to do so after the client upgrades to a different protocol. The server sends an Upgrade header in a 426 response to indicate the required protocol(s)."));
this->error.insert(pair<int,string>(428,"Precondition Required*The origin server requires the request to be conditional. This response is intended to prevent the 'lost update' problem, where a client GETs a resource's state, modifies it, and PUTs it back to the server, when meanwhile a third party has modified the state on the server, leading to a conflict."));
this->error.insert(pair<int,string>(429,"Too Many Requests*The user has sent too many requests in a given amount of time (\"rate limiting\")."));
this->error.insert(pair<int,string>(431,"Request Header Fields Too Large*The server is unwilling to process the request because its header fields are too large. The request may be resubmitted after reducing the size of the request header fields."));
this->error.insert(pair<int,string>(451,"Unavailable For Legal Reasons*The user-agent requested a resource that cannot legally be provided, such as a web page censored by a government."));
this->error.insert(pair<int,string>(500,"Internal Server Error*The Server encountered an internal error that prevented it from fulfilling this request."));
}

string Model::getErrorHeading(int errorCode)
{
string errorHeading;
string data=this->error[errorCode];
for(int e=0;e<data.size();e++)
{
if(data[e]=='*') break;
errorHeading+=data[e];
}
return errorHeading;
}

string Model::getErrorDetails(int errorCode)
{
int e;
string errorDetails;
string data=this->error[errorCode];
for(e=0;e<data.size();e++)
{
if(data[e]=='*') break;
}
e++;
while(e<data.size())
{
errorDetails+=data[e];
e++;
}
return errorDetails;
}

string Model::getErrorResponse(int errorCode)
{
char errorCodeString[10];
string errorHeading;
string errorDetails;
sprintf(errorCodeString,"%d",errorCode);
errorHeading=getErrorHeading(errorCode);
errorDetails=getErrorDetails(errorCode);
string response="<!doctype html><html lang='en'><head><title>HTTP Status ";
response+=errorCodeString;
response+=" – ";
response+=errorHeading;
response+="</title><style type='text/css'>body {font-family:Tahoma,Arial,sans-serif;} h1, h2, h3, b {color:white;background-color:#525D76;} h1 {font-size:22px;} h2 {font-size:16px;} h3 {font-size:14px;} p {font-size:12px;} a {color:black;} .line {height:1px;background-color:#525D76;border:none;}</style></head><body>";
response+="<h1>HTTP Status ";
response+=errorCodeString;
response+=" : ";
response+=errorHeading;
response+="</h1><hr class='line' /><p><b>&nbsp;Description&nbsp;</b>";
response+=errorDetails;
response+="</p><hr class='line' /><h3>HCServer</h3></body></html>";
return response;
}

string Model::getMimeType(string extension)
{
return this->mimeTypes[extension];
}

void Model::setServlet(string request,ServletInfo servletInfo)
{
this->servlets.insert(pair<string,ServletInfo>(request,servletInfo));
}
ServletInfo Model::getServlet(string request)
{
return this->servlets[request];
}
int Model::servletExists(string request)
{
if(this->servlets.find(request)==this->servlets.end()) return 0;
return 1;
}

