#ifndef MYHEADERS_H
#define MYHEADERS_H

#include <string>
#include <unistd.h>
#define MAXSIZE 2100000

using namespace std;

void printmenu();
void printarray(long data[], long size);
int readfile(string infilename, long data[]);
int writefile(long data[], long size, string outfilename);
void swap(long& x, long& y);

#endif
