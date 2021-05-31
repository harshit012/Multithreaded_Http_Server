#include<FileReader.h>
#include<string>
FileReader::FileReader(string fileName,int chunkSize)
{
file=fopen((const char *)(fileName.c_str()),"rb");
if(file==NULL)
{
this->exists='N';
}else
{
this->exists='Y';
fseek(file,0,SEEK_END);
this->length=ftell(file);
fseek(file,0,SEEK_SET);
this->currentPosition=0;
}
this->chunkSize=chunkSize;
}

int FileReader::fileExists()
{
return this->exists=='Y';
}

int FileReader::getSize()
{
return this->length;
}

int FileReader::hasNext()
{
if(this->currentPosition!=this->length) return 1;
return 0;
}

int FileReader::next(char *response)
{
int toRead=this->chunkSize;
if((this->length)-(this->currentPosition)<this->chunkSize) toRead=(this->length)-(this->currentPosition);
fread(response,toRead,1,file);
this->currentPosition=ftell(this->file);
return toRead;
}

FileReader::~FileReader()
{
fclose(this->file);
}

