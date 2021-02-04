#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
  time_t p;
  struct tm *q;
  char s[30];
  time(&p);
  q=gmtime(&p);
  strcpy(s,asctime(q)) ;
  printf("%s\n",s);
}
