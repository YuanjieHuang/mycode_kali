#include "stdio.h"

int Mon[13]={ 0,31,28,31,30,31,30,31,31,30,31,30,31};

int funy(int y)    
  {
   return(y%4==0&&y%100!=0||y%400==0);
  }

int funa(int y,int m,int d)  
  {
    int i,days=0;
    for(i=m+1;i<13;i++) days+=Mon[i];
    days+=(Mon[m]-d);
 if(m<3) days+=funy(y);
    return days;
  }

int funb(int y,int m,int d)  
  {
    int i,days=0;
    for(i=1;i<m;i++) days+=Mon[1];
    days+=d;
    if(m>2) days+=funy(y);
    return days;
  }

int func(int y1,int y2)
{
  int i,days=0;
  for(i=y1+1;i<y2;i++)
   days+=(365+funy(i));
  return days;
}

main()
{
   int y1,m1,d1,y2,m2,d2,days=0;
   printf("please input begin date(yyyy-mm-dd)\n");
   scanf("%d-%d-%d",&y1,&m1,&d1);
   printf("please input end date(yyyy-mm-dd)\n");
   scanf("%d-%d-%d",&y2,&m2,&d2);
   if(y1==y2) days=funa(y1,m1,d1)-funa(y2,m2,d2);
      else days=funa(y1,m1,d1)+funb(y2,m2,d2)+func(y1,y2);
   printf("%d-%d-%d~%d-%d-%d:all days is %d !\n",y1,m1,d1,y2,m2,d2,days);
}

