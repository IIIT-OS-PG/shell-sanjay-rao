#include <string.h>
#include<iostream>
#include<string>
//#include "pc2.h"
using namespace std;
void tokenization(int *argc,char *line,char **argv,string sep)
{
      char *token;
      const char* s = sep.c_str();
      token = strtok(line,s);
      int i=0;
      while(token!=NULL)
      {
        argv[i]=token;
        token = strtok(NULL,s);
        i++;
      }
      argv[i]=NULL;

      *argc=i;
}
