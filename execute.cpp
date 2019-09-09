#include<sys/wait.h>
#include <string.h>
#include<unistd.h>
#include<iostream>
//#include "pc2.h"
using namespace std;

void execute(int *argc,char **argv)
{
  int i;
    int pid= fork();
    if(pid==0)
    {

       execvp(argv[0],argv);
    }
    else
    {
       wait(NULL);
    }
}
