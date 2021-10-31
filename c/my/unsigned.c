    #include <stdio.h>
    int main()
    {
        short a = 0100;  //八进制
        int b = -0x1;  //十六进制
        long c = 720;  //十进制
       
        unsigned short m = 0xffff;  //十六进制
        unsigned int n = 0x80000000;  //十六进制
        unsigned long p = 100;  //十进制
       
        //以无符号的形式输出有符号数
        printf("a=%#ho, b=%#x, c=%ld\n", a, b, c);
        //以有符号数的形式输出无符号类型（只能以十进制形式输出）
        printf("m=%hd, n=%d, p=%ld\n", m, n, p);

        unsigned int a1 = 0x100000000;
        int b1 = 0xffffffff;
        printf("a=%u, b=%d\n", a1, b1);
        return 0;
    }