#include "stdio.h"
/*
	同构数：正整数n是它平方数的尾部，如6^2=36,76^2=2776
*/
int func(int i)
{
	int j;
	for(j=10;j<1000;j=j*10)
	{
		if(i/j == 0)
			break;
	}
	if((i*i)%j == i)
		return 1;
	else
		return 0;
}
void gettonggou()
{
	int i;
	for(i=1;i<=1000;i++)
	{
		if(func(i))
			printf("%d ",i);
	}
}

main()
{
	printf("The Tonggoushu bellow 1000 are\n");
	gettonggou();
	printf("\n");
}
