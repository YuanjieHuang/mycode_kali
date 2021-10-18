#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>

void time_test0(void)
{ 
    struct tm *ptr; 
    time_t lt; 
    lt =time(NULL); 
    ptr=gmtime(&lt); 
    printf(asctime(ptr)); 
    printf(ctime(&lt)); 


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

int time_test()
{
  time_t *p = malloc(sizeof(time_t));
  if(NULL == p)
    return 0;
  time_t s = time(p);
  printf("Now  :%ld %ld\n",*p, s);
  if(NULL != p)
    free(p);
  return 0;

}

void gmtime_test(){
   time_t t;
   struct tm *p = NULL;
   time(&t);
   p=gmtime(&t);
   printf("Year  :%d\n",1900+p->tm_year);
   printf("Month :%d\n",1+p->tm_mon);
   printf("Day   :%d\n",p->tm_mday);
   printf("Hour  :%d\n",p->tm_hour);
   printf("Minute:%d\n",p->tm_min);
   printf("Second:%d\n",p->tm_sec);
   printf("Weekday:%d\n",p->tm_wday);
   printf("Days  :%d\n",p->tm_yday);
   printf("Isdst :%d\n",p->tm_isdst);
}

void localtime_show(){
   time_t t;
   struct tm *p;
   time(&t);
   p=localtime(&t);
   printf("Year  :%d\n",1900+p->tm_year);
   printf("Month :%d\n",1+p->tm_mon);
   printf("Day   :%d\n",p->tm_mday);
   printf("Hour  :%d\n",p->tm_hour);
   printf("Minute:%d\n",p->tm_min);
   printf("Second:%d\n",p->tm_sec);
   printf("Weekday:%d\n",p->tm_wday);
   printf("Days  :%d\n",p->tm_yday);
   printf("Isdst :%d\n",p->tm_isdst);
}

void ctime_test()
{
  time_t p;
  char s[30];
  time(&p);
  strcpy(s,ctime(&p)) ;
  printf("%s\n",s);
}

void green_time()
{
  time_t p;
  struct tm *q;
  char s[30];
  time(&p);
  q=gmtime(&p);//Greenwich Mean Time
  strcpy(s,asctime(q)) ;
  printf("%s\n",s);
}

void mktime_show()
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

void timeval_timezone()
{ 
   struct timeval tv;
   struct timezone tz;
   gettimeofday (&tv , &tz);
   printf("tv_sec        : %d\n", tv.tv_sec);
   printf("tv_usec       : %d\n",tv.tv_usec);
   printf("tz_minuteswest: %d\n", tz.tz_minuteswest);
   printf("tz_dsttime    : %d\n",tz.tz_dsttime);
   tv.tv_sec=tv.tv_sec- 4000;
   settimeofday (&tv , &tz);
   printf("tv_sec        : %d\n", tv.tv_sec);
   printf("tv_usec       : %d\n",tv.tv_usec);
   printf("tz_minuteswest: %d\n", tz.tz_minuteswest);
   printf("tz_dsttime    : %d\n",tz.tz_dsttime);
}

main()
{ 
   struct timeval tv;
   struct timezone tz;
   gettimeofday (&tv , &tz);
   printf("tv_sec        : %d\n", tv.tv_sec);
   printf("tv_usec       : %d\n",tv.tv_usec);
   printf("tz_minuteswest: %d\n", tz.tz_minuteswest);
   printf("tz_dsttime    : %d\n",tz.tz_dsttime);
}

