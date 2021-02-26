#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int i,j;
    srand((int)time(0));
    for(j=0; j<10; j++)
    {
        for(i=0; i<10; i++)
        {
            printf("%d\t",rand());
        }
        printf("\n");
    }
    system("pause");
    return 0;
}