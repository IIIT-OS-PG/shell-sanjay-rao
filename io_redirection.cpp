#include<string>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<iostream>
//#include "pc2.h"
using namespace std;
void io_redirection(int *argc,int *argc1,char * line,char **argv,char **argv1,string sep)
{
  int fd,i,j;
  tokenization(argc,line,argv,sep);
  tokenization(argc1,argv[0],argv1," ");

  int store=dup(1);
  if(sep == ">")
  {
    argv[1] = removeSpaces(argv[1]);

    fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0644);

  if(fd != -1)
  {
    dup2(fd,1);

    execute(argc,argv1);
    close(fd);
  }
  dup2(store,1);
  }
  if(sep == ">>")
  {
    argv[1] = removeSpaces(argv[1]);
  if((fd = open(argv[1], O_WRONLY | O_APPEND | O_CREAT, 0644)) != -1);
  {
    dup2(fd,1);
    execute(argc,argv1);
    close(fd);
  }
  dup2(store,1);
  }
}
