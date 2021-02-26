    #include <stdio.h>  //引入标准输入输出库
    void main( ) {
        char ch;
        printf ("Input a character: ");   //输入提示信息
        ch = getc(stdin);  // 从标准输入控制台中读取字符
        printf ("The character input was: '%c'\n", ch);  // 输出字符
    }