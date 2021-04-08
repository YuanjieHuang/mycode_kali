#include <stdio.h>
#include <time.h>

int main()
{
  time_t s;
  s= time((time_t*)NULL);
  printf("Now  :%ld\n",s);
  getch();
}
