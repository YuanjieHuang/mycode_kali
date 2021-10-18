#include <stdio.h>
#include <string.h>

void strlen_test()
{
   char a[20]="qweaQWEa^*&aIOP";
   char b[]="qwer";
   int i,j;
   i=strlen(a);
   j=strlen(b);
   printf("%d\n",i);
   printf("%d\n",j);
}

main()
{
   char a[]="C is a useful language for Linux OS.I'll study it hard.";
   char *s="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
   int i;
   i=strspn(a,s);
   printf("%d",i);
}
