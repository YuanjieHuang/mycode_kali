#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>
main()
{ 
     time_t t;
     struct tm *p;
     int i;
     struct timeval tv;
     struct timezone tz;
     tz.tz_minuteswest=0;
     tz.tz_dsttime=0;
     time(&t);
     p=gmtime(&t);
     printf("Change your time:\n");
     printf("Year:\n");
     scanf("%d",&i);
     (*p).tm_year=i-1900;
     printf("Month:\n");
     scanf("%d",&i);
     (*p).tm_mon=i-1;   
     printf("Date:\n");
     scanf("%d",&i);
     (*p).tm_mday=i;      
     printf("Hour:\n");
     scanf("%d",&i);
     (*p).tm_hour=i;  
     printf("Minute:\n");
     scanf("%d",&i);
     (*p).tm_min=i;  
     printf("Second:\n");
     scanf("%d",&i);
     (*p).tm_sec=i; 
     t=mktime(p);
     tv.tv_sec=t;
     tv.tv_usec=0;
     settimeofday (&tv , &tz); 
     printf("Done!\n");
} 
