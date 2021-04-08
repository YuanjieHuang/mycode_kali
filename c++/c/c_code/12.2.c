#include <stdio.h>
#include <time.h>

int main()
{
  time_t *p;
  time(p);
  printf("Now  :%ld\n",*p);

}
