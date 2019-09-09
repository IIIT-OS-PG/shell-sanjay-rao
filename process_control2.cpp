#include <stdlib.h>
#include<limits.h>
#include "pc2.h"

#define MAXLINE 4096

int main(){
    char line[_POSIX_MAX_INPUT];
    char* argv[_POSIX_MAX_INPUT];
    int argc,argc1;
    char* argv1[_POSIX_MAX_INPUT];
    char buf[_POSIX_MAX_INPUT];
    while(1)
    {
      cout << "%";

      if(!fgets(line, _POSIX_MAX_INPUT, stdin))
      {
        exit(0);
      }

      if(!strcmp(line,"\n"))
        continue;

      size_t length = strlen(line);

      if (line[length - 1] == '\n')
        line[length - 1] = '\0';

      if(!strcmp(line, "exit\0"))
      {
        exit(0);
      }
      if((is_find(line,">",strlen(line),strlen(">"))) == 1)
      {
        io_redirection(&argc,&argc1,line,argv,argv1,">");
        continue;
      }

      if((is_find(line,">>",strlen(line),strlen(">>"))) == 1)
      {
        io_redirection(&argc,&argc1,line,argv,argv1,">>");
        continue;
      }

      if((is_find(line,"|",strlen(line),strlen("|"))) == 1)
      {
         tokenization(&argc,line,argv,"|");
         for(int i=0;i<argc;i++)
         {
             int j=0,k=1,l;
             if(argv[i][0] == ' ')
             {
               while(argv[i][k])
               {
                 argv[i][j++]=argv[i][k++];
               }
               argv[i][j]='\0';
             }
             for(i=0;i<argc;i++)
             {
               tokenization(&argc1,argv[i],argv1," ");
               //pipe1(&argc,&argc1,argv1);
             }
         }
         continue;
      }

      tokenization(&argc,line,argv," ");

      if(!strcmp(argv[0],"cd"))
      {
        if(!strcmp(argv[1],"~"))
        {
          if(chdir("/home/sanjay/")!=0)
          {
             perror("/home/sanjay/");
          }
          continue;
        }

        if(chdir(argv[1])!=0)
        {
           perror(argv[1]);
        }
        continue;
      }
      execute(&argc,argv);

    }

}
