#include<stdio.h>
#include<stdlib.h>
char outbuf[50];
#if 0
int main(void)
{
    /* 将outbuf与stdout输出流相连接 */
    setbuf(stdout,outbuf);
    /* 向stdout中放入一些字符串 */
    puts("This is a test of buffered output.");
    puts("This output will go into outbuf");
    puts("and won't appear until the buffer");
    puts("fills up or we flush the stream.\n");
    /* 以下是outbuf中的内容 */
//    puts(outbuf);
    /*刷新流*/
//    fflush(stdout);
    return 0;
}
#endif
 

//char buf[6];
int main()
{
    // static char buf[6];
    setbuf(stdout,malloc(100));
    int c;
 
    int i = 0;
    while((c=getchar())!=EOF && getchar())
    {
        putchar(c);
#if 1
        printf("hello\n");
        i++;
        if(i>5)  
        {  
            return 0;  
        }  
#endif  
    }  
    return 0;  
}  