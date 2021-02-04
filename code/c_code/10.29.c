#include <stdio.h>
#include <string.h>
main()
{
   char a[]="C is a useful language for Linux OS.I started to learn it 3 years ago .I'll study it hard.";
   printf("%d\n",strcspn(a," "));
   printf("%d\n",strcspn(a,"'."));
   printf("%d\n",strcspn(a,"aeiou"));
   printf("%d\n",strcspn(a,"AEIOU"));
   printf("%d\n",strcspn(a,"1234567890"));
}
