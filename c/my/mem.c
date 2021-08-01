    #include <stdio.h>
    #include <stddef.h>
    char *str1 = "c.biancheng.net";  //字符串在常量区，str1在全局数据区
    int n;  //全局数据区
    char* func(){
        char *str = "C语言中文网";  //字符串在常量区
        return str;
    }
    struct s
    {
       char a;
       int b[2];
       float c;
    };
    

    int  __attribute__((cdecl)) max(int m, int n)
    {
        int max = m>n ? m : n;
        return max; 
    }

    int main(){
        int a;  //栈区
        char *str2 = "01234";  //字符串在常量区，str2在栈区
        char  arr[20] = "56789";  //字符串和arr都在栈区
        char *pstr = func();  //栈区
        int b;  //栈区
        printf("str1: %p\npstr: %p\nstr2: %p\n", str1, pstr, str2);
        puts("--------------");
        printf("&str1: %p\n   &n: %p\n", &str1, &n);
        puts("--------------");
        printf("  &a: %p\n arr: %p\n  &b: %p\n", &a, arr, &b);
        puts("--------------");
        printf("n: %d\na :%d\nb: %d\n", n, a, b);
        puts("--------------");
        printf("%s\n", pstr);

        //  char strStackOver[1024*1024*1024] = {0};
        int m, n;
        printf("%#X, %#X\n", m, n);
        printf("offsetof(struct s,c):%d,sieof(s):%d\n", offsetof(struct s,c), sizeof(struct s));
        return 0;
    }