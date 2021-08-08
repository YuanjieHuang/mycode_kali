#include "stdio.h"
//判断一年中的第几天
int Day(int year ,int month,int date)
{
    int months[13]={0,31,0,31,30,31,30,31,31,30,31,30,31} ,i,days=0;
    /*判断是否是闰年*/
    if((year % 4 == 0 && year % 100 !=0)||(year % 400 ==0 ))
        months[2]=29;
    else
        months[2]=28;
    for(i=1;i<month;i++)
     days = days + months[i];
    days = days + date;
    return days;
}

main()
{
    int year, month, day;
    printf("Please input year month day\n");
    scanf("%d", &year);
    scanf("%d", &month);
    scanf("%d", &day);
    printf("The days of %d th %d %d is %d\n", day, month, year, Day(year,month,day));
}

