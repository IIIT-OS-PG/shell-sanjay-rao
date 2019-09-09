//#include "pc2.h"
char *removeSpaces(char *str)
{
  int i = 0, j = 0;
  while (str[i])
  {
    if (str[i] != ' ')
       str[j++] = str[i];
       i++;
  }
  str[j] = '\0';

  return str;
}
char *removeSpacesFront(char *str)
{
  int j=0,i=1;
  if(str[0] == ' ')
    while(str[j])
    {
      str[j++]=str[i];
      i++;
    }
    str[j]='\0';
  return str;
}
