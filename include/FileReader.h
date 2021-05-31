#ifndef __FileReader__
#define __FileReader__ 12345
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
class FileReader
{
private:
FILE *file;
int length;
char exists;
int currentPosition;
int chunkSize;

public:
FileReader(string fileName,int chunkSize);
int fileExists();
int getSize();
int hasNext();
int next(char *response);
~FileReader();
};
#endif
