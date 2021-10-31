#include <stdio.h>
#include <unistd.h>
int main(void)
{
	int i;
	alarm(1);
	for(i = 0; ; i++)
	{
		usleep(1000);
		printf("%d\n", i);
	}		
	return 0;
}
