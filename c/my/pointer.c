#include <stdio.h>



void addr()
{
    struct{
        int a;
        char b;
        int c;
    }t={ 10, 'C', 20 };
    int m;
    char c;
    int n;
    printf("&m: %p\n&c: %p\n&n: %p\n", &m, &c, &n);
    printf("length: %d\n", sizeof(t));
    printf("&a: %X\n&b: %X\n&c: %X\n", &t.a, &t.b, &t.c);
}

//返回两个数中较大的一个
int max(int a, int b)
{
    return a>b ? a : b;
}

void funcPtr()
{
    int x = 1, y = 2, maxval = 0;
    //定义函数指针
    int (*pmax)(int, int) = max;  //也可以写作int (*pmax)(int a, int b)
    printf("Input two numbers:");
    maxval = (*pmax)(x, y);
    printf("Max value: %d\n", maxval);

}

void ptrArray()
{
    int a = 16, b = 932, c = 100;
    //定义一个指针数组
    int *arr[3] = {&a, &b, &c};//也可以不指定长度，直接写作 int *arr[]
    //定义一个指向指针数组的指针
    int **parr = arr;
    printf("%d, %d, %d\n", *arr[0], *arr[1], *arr[2]);
    printf("%d, %d, %d\n", **(parr+0), **(parr+1), **(parr+2));
}

void pointer()
{
    int a =100;
    int *p1 = &a;
    int **p2 = &p1;
    int ***p3 = &p2;
    printf("%d, %d, %d, %d\n", a, *p1, **p2, ***p3);
    printf("&p2 = %#X, p3 = %#X\n", &p2, p3);
    printf("&p1 = %#X, p2 = %#X, *p3 = %#X\n", &p1, p2, *p3);
    printf(" &a = %#X, p1 = %#X, *p2 = %#X, **p3 = %#X\n", &a, p1, *p2, **p3);
}

void arrayIndex()
{
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
}

void registerValueTest()
{
    register int loop = 0;  // 寄存器变量
    double sign = 1.0, res = 0, ad = 1.0;
    for(loop=1; loop<=100000000; loop++)
    {
        res += ad;
        sign=-sign;
        ad=sign/(2*loop+1);
    }
    res *= 4;
    printf("pi is %f\n", res);
}

void getEndian()
{
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
    int endian = 1;
    printf("%s\n",*(char *)&endian == 1 ? "little endian":"big endian");
}

void massiveMalloc()
{
    for(;;)
    {
        int *prt = malloc(100);
    }
}

int main()
{
    registerValueTest();
    pointer();
    return 0;
}

