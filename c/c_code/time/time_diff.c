#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>
void time_diff_usec()
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

main()
{ 
   time_diff_usec();
   struct timeval tv,tv2;
   struct timezone tz;
   long sec,usec,i;
   
   printf("please input a number:\n");
   scanf("%d",&i);
   gettimeofday (&tv , &tz);
   printf("please input a number:\n");
   scanf("%d",&i);
   gettimeofday (&tv2 , &tz);

   sec=tv2.tv_sec-tv.tv_sec;
   usec=tv2.tv_usec-tv.tv_usec;
   printf("%d.%ld\n",(sec*1000000 + usec)/1000000,(sec*1000000 + usec)%1000000);
}



