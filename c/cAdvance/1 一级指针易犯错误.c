#include	<stdio.h>

void	copy_str(char	*from, char	*to)
{
	//if (*from == '\0' || *to == '\0')
	if (from == NULL|| to == NULL) //判断一个指针是否合法 是为了判断他是否是野指针， 而不是关心里面的内容
	{
		printf("func	copy_str()	err\n");
		return;
	}
	for (; *from != '\0'; from++, to++)
	{
		*to = *from;
	}
	*to = '\0';
}

char	*my_stract(char	*x, char*	y) //x = "123456\0",  y  ="abcd"
{
	char	str[80]; //"123456abcd\0 "
	                     //           ↑
	char	*z = str;											/*指针z指向数组str*/
	while (*z++ = *x++);
	z--;																				/*去掉串尾结束标志*/
	
	while (*z++ = *y++);
	z = str;		  /*将str地址赋给指针变量z*/


	return(z);
}

int	main()
{
	char	*p = "aabbccdd";
	char	to[100] = { 0 } ;
	copy_str(p, to);
	printf("to	:	%s\n", to);
	return 0;
}