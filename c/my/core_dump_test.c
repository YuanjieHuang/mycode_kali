#include<stdlib.h>

void repeatFree(char *p)
{
    if(NULL != p)
    {
        free(p);
    }
}

int main()
{
    char* pstr =(char*) malloc(10);

    repeatFree(pstr); // 第一次释放

    repeatFree(pstr); // 第二次释放

    return 0;
}