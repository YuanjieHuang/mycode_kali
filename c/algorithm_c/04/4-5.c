#include "stdio.h"
main()
{
    int year;
    printf("Please a year:\n");
    scanf("%d",&year);
    /*判断是否是闰年*/
    if((year % 4 == 0 && year % 100 !=0)||(year % 400 ==0 ))
        printf("%d is leap year!\n",year);
    else
        printf("%d is not leap year!\n",year);
}

