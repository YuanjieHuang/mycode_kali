#include <stdio.h>
#include <string.h>
void main()
{
   char a[20]="asdfgh";
   char b[20]="ijklmn";
   printf("1:%s \n %s\n",a,b);
   bcopy(a,b,4);
   printf("2:%s \n %s\n",a,b);

}
