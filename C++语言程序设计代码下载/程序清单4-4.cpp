程序清单4-4
const   float   DISCOUNT = 0.05 ;   	// 全局常量
float   payRate ;	// 全局变量
void    calculate ( int,  float ) ;	// 函数原型	
using  namespace  std ;

int  main (  )
{
	int number ;						// number和distance是本函数的局部变量
	float distance ;
        .								// 不能在此使用handle函数中的a, b, 和 tax 
        .  							// 可以在此使用本函数的局部变量number和distance
        .								// 可以在此使用全局常量DISCOUNT和全局变量payRate
	calculate(number, distance) ;
   
    return 0 ;
}

void calculate(int a,  float b)
{
float  bill ;		// a, b和bill是本函数的局部变量
        .				// 不能在此使用main函数中的number和distance
        .				// 可以在此使用本函数的a, b 和bill
        .				// 可以在此使用全局常量DISCOUNT和全局变量payRate
}
