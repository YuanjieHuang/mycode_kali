#include "stdio.h"
main()
{
    int a,b,c;
    for(a=0;a<=1;a++)
        for(b=0;b<=1;b++)
            for(c=0;c<=1;c++)
            if((a&&!b || !a&&b) && (b&&!c || !b&&c) && (c&&a+b==0 || !c&&a+b!=0))
            {
                printf("甲 told a %s\n",a?"truth":"lie");
                printf("乙 told a %s\n",b?"truth":"lie");
                printf("丙 told a %s\n",c?"truth":"lie");
            }
    getche();
}

