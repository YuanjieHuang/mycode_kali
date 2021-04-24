#include "stdio.h"
#include "math.h"

unsigned ppow(unsigned a, unsigned b);
/*
ref:  https://www.runoob.com/cprogramming/c-examples-five-fish-html.html
A、B、C、D、E 五人在某天夜里合伙去捕鱼，到第二天凌晨时都疲惫不堪，于是各自找地方睡觉。
日上三杆，A 第一个醒来，他将鱼分为五份，把多余的一条鱼扔掉，拿走自己的一份。
B 第二个醒来，也将鱼分为五份，把多余的一条鱼扔掉拿走自己的一份。 。
C、D、E依次醒来，也按同样的方法拿鱼。
问他们台伙至少捕了多少条鱼?以及每个人醒来时见到了多少鱼？

*/

int fivePeopleDivideFish(){
    int n,x,j,k,l,m;
    for(n=5;;n++){
        j=4*(n-1)/5;
        k=4*(j-1)/5;
        l=4*(k-1)/5;
        m=4*(l-1)/5;
        if(n%5==1&&j%5==1&&k%5==1&&l%5==1&&m%5==1){
            printf("至少合伙捕鱼：%d条\n",n);
            printf("分别见到鱼的条数：%d %d %d %d\n",j,k,l,m);
            break;
        }
    }
    return 0;
}

/*
30 个人在一条船上，超载，需要 15 人下船。
于是人们排成一队，排队的位置即为他们的编号。
报数，从 1 开始，数到 9 的人下船。
如此循环，直到船上仅剩 15 人为止，问都有哪些编号的人下船了呢？
*/

int YosefLiveGame()
{
    int c = 0;
    int i = 1;
    int j = 0;
    int a[30] = { 0 };
    int b[30] = { 0 };
    while (i<=31)
    {
        if (i == 31)
        {
            i = 1;
        }
        else if (c == 15)
        {
            break;
        }
        else
        {
            if (b[i] != 0)
            {
                i++;
                continue;
            }
            else
            {
                j++;
                if (j != 9)
                {
                    i++;
                    continue;
                }
                else
                {
                    b[i] = 1;
                    a[i] = j;
                    j = 0;
                    printf("第%d号下船了\n", i);
                    i++;
                    c++;
                }
            }
        }
    }
}

int convertBinaryToDecimal(long long n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*ppow(2,i);
        ++i;
    }
    return decimalNumber;
}

long long convertDecimalToBinary(int n)
{
    long long binaryNumber = 0;
    int remainder, i = 1, step = 1;
 
    while (n!=0)
    {
        remainder = n%2;
        printf("Step %d: %d/2, 余数 = %d, 商 = %d\n", step++, n, remainder, n/2);
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    return binaryNumber;
}

//求a的b次方函数
unsigned ppow(unsigned a, unsigned b) {
    unsigned cc = 1;
    while (b) {
        cc*=a;
        b--;
    }
    return cc;
}

int calcNumberAllFactors()
{
    int number = 3456, i;
    // printf("输入一个整数: ");
    // scanf("%d",&number);
    printf("%d 的因数有: ", number);
    for(i=1; i <= number; ++i)
    {
        if (number%i == 0)
        {
            printf("%d ",i);
        }
    }
    return 0;
}

int isPrimeNumber()
{
    int n, i, flag = 0;
 
    printf("输入一个正整数: ");
    scanf("%d",&n);
 
    for(i=2; i<=n/2; ++i)
    {
        // 符合该条件不是素数
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }
 
    if (flag==0)
        printf("%d 是素数",n);
    else
        printf("%d 不是素数",n);
    return 0;
}

void reverseSentence()
{
    char c;
    scanf("%c", &c);
 
    if( c != '\n')
    {
        reverseSentence();
        printf("%c",c);
    }
}
/*
一只小猴子一天摘了许多桃子，第一天吃了一半，然后忍不住又吃了一个；
第二天又吃了一半，再加上一个；后面每天都是这样吃。
到第10天的时候，小猴子发现只有一个桃子了。问小猴子第一天共摘了多少个桃子。
*/
void monkeyEatPeach()
{
    int peachNum = 1;
    for (int day = 10; day > 1; day--)//从最后一天倒推到第一天
    {
        peachNum++;
        peachNum = 2 * peachNum;
    }
    printf("第一天摘了 %d 个桃子。", peachNum);
}

int main()
{
    char c;
    while(c != '0')
    {
        printf("输入一个字符: ");
        // 读取用户输入
        scanf("%c", &c);  
        // %d 显示整数
        // %c 显示对应字符
        printf("%c 的 ASCII 为 %d\n", c, c);
    }
    return 0;
}