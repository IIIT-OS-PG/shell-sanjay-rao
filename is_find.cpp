//#include "pc2.h"
int is_find(string line,string s,int n,int m)
{
  int count1 = 0,found;
  if(s == "|")
  {
    found = line.find(s);
    if(found != string::npos)
      return 1;
    else
      return 0;
  }
  else
  {
  found = line.find(s);
  if(found != string::npos)
    count1++;
  found = line.find(s,found+1);
  if(found != string::npos)
    count1++;
  if(count1 > 1)
   return 0;
  else if(count1 == 1)
  return 1;
  }
}
