#include <stdio.h>
void move(int n, char x, char y, char z)
{
    if(n == 1)//递归结束条件
    {
        printf("%c--->%c\n", x, z);
    }
    else
    {
        move(n-1, x, z, y);
        printf("%c---->%c\n", x, z);
        move(n-1, y, x, z);
        // printf("%c---->%c\n", x, z);

    }
}
int main()
{
    move(3, 'A', 'B', 'C');
    // printf("\n\n");
    // move(4, 'A', 'B', 'C');
    // printf("\n\n");
    // move(5, 'A', 'B', 'C');
    // printf("\n\n");
    return 0;
}