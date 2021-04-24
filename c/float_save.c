    #include <stdio.h>
    #include <stdlib.h>

void strreverse(char* begin, char* end) {
	
	char aux;
	
	while(end>begin)
	
		aux=*end, *end--=*begin, *begin++=aux;
	
}
	

 void itoa(int value, char* str, int base) {
	
	static char num[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	
	char* wstr=str;
	
	int sign;
	
	div_t res;
	


	
	// Validate base
	
	if (base<2 || base>35){ *wstr='\0'; return; }
	

	
	// Take care of sign
	
	if ((sign=value) < 0) value = -value;
	


	
	// Conversion. Number is reversed.
	
	do {
	
		res = div(value,base);
	
		*wstr++ = num[res.rem];
	
	}while(value=res.quot);
	
	if(sign<0) *wstr++='-';
	
	*wstr='\0';
	


	
	// Reverse string
	
	strreverse(str,wstr-1);
	
}
    //浮点数结构体
    typedef struct {
        unsigned int nMant : 23;  //尾数部分
        unsigned int nExp : 8;  //指数部分
        unsigned int nSign : 1;  //符号位
    } FP_SINGLE;
    int main()
    {
        // 0.3 0.6 0.2 0.6 0.2 
        char strBin[33] = { 0 };
        float f = 19.625;
        FP_SINGLE *p = (FP_SINGLE*)&f;
       
        itoa(p->nSign, strBin, 2);
        printf("sign: %s\n", strBin);
        itoa(p->nExp, strBin, 2);
        printf("exp: %s\n", strBin);
        itoa(p->nMant, strBin, 2);
        printf("mant: %s\n", strBin);
       
        return 0;
    }
/*
精度问题:
    对于十进制小数，整数部分转换成二进制使用“展除法”（就是不断除以 2，直到余数为 0），一个有限位数的整数一定能转换成有限位数的二进制。
    但是小数部分就不一定了，小数部分转换成二进制使用“乘二取整法”（就是不断乘以 2，直到小数部分为 0），一个有限位数的小数并不一定能转换成有限位数的二进制，
    只有末位是 5 的小数才有可能转换成有限位数的二进制，其它的小数都不行。 
*/