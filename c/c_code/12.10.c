#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>
main()
{ 
   struct timeval tv,tv2;
   struct timezone tz;
   long sec,usec,i;
   
   gettimeofday (&tv , &tz);
   for(i=0;i<100000000;i++)
   {
   	   ;;;;;;;;;;;;;;
   }
   gettimeofday (&tv2, &tz);
   sec=tv2.tv_sec-tv.tv_sec;
   usec=tv2.tv_usec-tv.tv_usec;
   printf("%ld\n",sec*1000000 + usec);

} 



