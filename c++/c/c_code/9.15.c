#include <stdio.h>

void stradd(char *a,char *b,char *c)
{
   while(*a!=NULL)
   {
       *c=*a;
       c++;
       a++;
   }
   while(*b!=NULL)
   {
       *c=*b;
       c++;
       b++;
   }
}

int main()
{
    char a[30]="abcdefg";
    char b[30]="HIJKLMN";
    char c[30]="";
    printf("a:  %s\n",a);
    printf("b:  %s\n",b);
    stradd(a,b,c);
    printf("c:  %s\n",c);
}

