#include <stdio.h>
#include <string.h>
main()
{
   char a[]="C is a useful language for Linux OS.I'll study it hard.";
   char *s="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
   int i;
   i=strspn(a,s);
   printf("%d",i);
}
