    #include <stdio.h>

    int m;
    char c;
    int n;
    struct{
    int a;
    char b;
    int c;
    }t={ 10, 'C', 20 };


    //返回两个数中较大的一个
    int max(int a, int b){
        return a>b ? a : b;
    }
    int main(){
        printf("&m: %p\n&c: %p\n&n: %p\n", &m, &c, &n);
        printf("length: %d\n", sizeof(t));
        printf("&a: %X\n&b: %X\n&c: %X\n", &t.a, &t.b, &t.c);

        // int x, y, maxval;
        // //定义函数指针
        // int (*pmax)(int, int) = max;  //也可以写作int (*pmax)(int a, int b)
        // printf("Input two numbers:");
        // scanf("%d %d", &x, &y);
        // maxval = (*pmax)(x, y);
        // printf("Max value: %d\n", maxval);
#if A
        int array[6] = {0, 1, 2, 3, 4, 5};
        int *p = array;
        int len_a = sizeof(array) / sizeof(int);
        int len_p = sizeof(p) / sizeof(int);
        printf("a:%p p:%p\n", array, p);
        printf("sizeof(int)=%d sizeof(p):%d\n",sizeof(int), sizeof(p));
        printf("len_a = %d, len_p = %d\n", len_a, len_p);

        int a =100;
        int *p1 = &a;
        int **p2 = &p1;
        int ***p3 = &p2;
        printf("%d, %d, %d, %d\n", a, *p1, **p2, ***p3);
        printf("&p2 = %#X, p3 = %#X\n", &p2, p3);
        printf("&p1 = %#X, p2 = %#X, *p3 = %#X\n", &p1, p2, *p3);
        printf(" &a = %#X, p1 = %#X, *p2 = %#X, **p3 = %#X\n", &a, p1, *p2, **p3);
#elif B
        char str[20] = "c.bianxheng.net";
   
        char *s1 = str;
        char *s2 = str+2;
    
        char c1 = str[4];
        char c2 = *str;
        char c3 = *(str+4);
        char c4 = *str+2;
        char c5 = (str+1)[5];
    
        int num1 = *str+2;
        long num2 = (long)str;
        long num3 = (long)(str+2);
        printf("  s1 = %s\n", s1);
        printf("  s2 = %s\n", s2);
        printf("  c1 = %c\n", c1);
        printf("  c2 = %c\n", c2);
        printf("  c3 = %c\n", c3);
        printf("  c4 = %c\n", c4);
        printf("  c5 = %c\n", c5);
    
        printf("num1 = %d\n", num1);
        printf("num2 = %ld\n", num2);
        printf("num3 = %ld\n\n", num3);
#endif
        char str[20] = {0};
        int i;
        for(i=0; i<10; i++){
            *(str+i) = 97+i;  // 97为字符a的ASCII码值
        }
    
        printf("%s\n", str);
        printf("%s\n", str+2);
        printf("%c\n", str[2]);
        printf("%c\n", (str+2)[2]);

    int a = 16, b = 932, c = 100;
    //定义一个指针数组
    int *arr[3] = {&a, &b, &c};//也可以不指定长度，直接写作 int *arr[]
    //定义一个指向指针数组的指针
    int **parr = arr;
    printf("%d, %d, %d\n", *arr[0], *arr[1], *arr[2]);
    printf("%d, %d, %d\n", **(parr+0), **(parr+1), **(parr+2));

    int array[] = { 99, 15, 100, 888, 252 };
    int j, *p = array, len = sizeof(array) / sizeof(int);
    for(j=0; j<len; j++){
        printf("%d  ", *(p+j) );
    }
    printf("\n");

    //     char *strNull = NULL;
    // scanf(strNull);
    // printf("%s\n", strNull);

        union{
        int n;
        char ch;
        } data;
        data.n = 0x00000001;  //也可以直接写作 data.n = 1;
        if(data.ch == 1){
            printf("Little-endian\n");
        }else{
            printf("Big-endian\n");
        }
    // typedef char ARRAY20[20];
    // ARRAY20 a1, a2, s1, s2;

    // typedef int (*PTR_TO_ARR)[4];
    // PTR_TO_ARR p1, p2;
    // typedef int (*PTR_TO_FUNC)(int, int);
    // PTR_TO_FUNC pfunc;


        // register int loop = 0;  // 寄存器变量
        // double sign = 1.0, res = 0, ad = 1.0;
        // for(loop=1; i<=100; loop++)
        // {
        //     res += ad;
        //     sign=-sign;
        //     ad=sign/(2*loop+1);
        // }
        // res *= 4;
        // printf("pi is %f", res);
        // getc(stdout);

            char *memAccessTest = (char*)0XFFF00000;  //使用数值表示一个明确的地址
            printf("%s\n", memAccessTest);
        return 0;
    }