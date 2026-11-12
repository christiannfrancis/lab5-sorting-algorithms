#ifndef MYHEADERS_H
#define MYHEADERS_H

#include <string>

#define MAXSIZE 2100000

void printmenu();
int readfile(std::string filename, long data[]);
int writefile(long data[], long size, std::string filename);

#endif
