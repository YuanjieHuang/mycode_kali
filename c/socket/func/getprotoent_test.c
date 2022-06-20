#include <stdio.h>
#include <netdb.h>   
/*backgroud color*/
#define B_BLACK 40
#define B_RED 41
#define B_GREEN 42
#define B_YELLOW 43
#define B_BLUE 44
#define B_PURPLE 45
#define B_DARKGREEN 46
#define B_WHITE 47

/*word color*/
#define W_BLACK   30
#define W_RED     31
#define W_GREEN   32
#define W_YELLOW  33
#define W_BLUE    34
#define W_PURPLE     35
#define W_DARKGREEN  36
#define W_WHITE      37
int  main()
{
    struct protoent *pro;
    int i = 0;
    /*
    char ch[20];
    printf("%*.*s\n",m,n,ch);
    前边的*定义的是总的宽度，后边的定义的是输出的个数，分别对应外面的参数m和n 
部分颜色代码:
字背景颜色: 40--49                字颜色: 30--39
40: 黑                           30: 黑
41: 红                           31: 红
42: 绿                           32: 绿
43: 黄                           33: 黄
44: 蓝                           34: 蓝
45: 紫                           35: 紫
46: 深绿                         36: 深绿
47：白色                         37：白色
    printf("\033[字背景颜色;字体颜色m 字符串 \033[0m" );
    printf("\033[47;31mThis is a color test.\033[0m");

    */
   printf("\033[47;31mThis is a color test.\033[0m");
    while(pro=getprotoent()) 
    {
        // %[flags][width][.precision]type
        printf("%-2d:protocol %-15s %-5d %-20s\n",i, pro->p_name,pro->p_proto, pro->p_aliases[0]);
        i++;
    }
}
