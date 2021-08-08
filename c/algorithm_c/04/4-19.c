#include "stdio.h"
//递归反向输出字符串
Print()
{
    char a;
    scanf("%c",&a);
    if(a != '#')  Print();
    if(a != '#')
        printf("%c",a);
}

main()
{
    printf("Please input a string ending for '#'\n");
    Print();
}

