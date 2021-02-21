#include	<stdio.h>
#include	<string.h>


//char	*p	=	"abcd11111abcd2222abcdqqqqq";	
//字符串中"abcd"出现的次数。
int	getSubCount(char	*str, char	*substr, int	*mycount)
{
	int	ret = 0;
	char	*p = str;
	char	*sub = substr;
	int cnt = 0;

	if (str == NULL || substr == NULL || mycount == NULL)
	{
		ret = -1;
		return	ret;
	}
	void *pp = p;
	
	char * p = (char*)malloc(1000 *sizeof(char));


	do
	{
		p = strstr(p, sub);
		if (p != NULL)
		{
		//	*mycount++; // *mycount ; mycount++
			(*mycount)++;
			//cnt++;
			p = p + strlen(sub);
		}
		else
		{
			break;
		}
	} while (*p != '\0');

	//*mycount = cnt;

	return	ret;
}

int	main(void)
{
	char	*p = "abcd11111abcd2222abcdqqqqq";
	int	count = 0;
	if (getSubCount(p, "abcd", &count) < 0)	{
		
			printf("error\n");
	}
	printf("abcd's	count	:%d\n", count);
	return 0;
}
