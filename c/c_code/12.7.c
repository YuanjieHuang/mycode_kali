#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>
main()
{ 
    time_t t;
    struct tm *p;
    char s[30];
    time(&t);
    strcpy(s,ctime(&t));
    printf("%s\n",s);
    p=gmtime(&t);
    t=mktime(p);
    time(&t);
    strcpy(s,ctime(&t));
    printf("%s\n",s);
}


