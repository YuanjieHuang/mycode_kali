程序清单4-10
void  getRoots(  /*in*/    float a,	// 一元二次方程系数
				/*in*/    float b,	// 一元二次方程系数
				/*in*/    float c,	// 一元二次方程系数
				/*out*/   float& root1,	// 一元二次方程第一个实根
				/*out*/   float& root2)	// 一元二次方程第二个实根
// 求以a, b, c为系数的一元二次方程的两个实根
// 前置条件：
//     a、b和c已赋值且b*b - 4*a*c >= 0
// 后置条件：
//     root1 = (-b + sqrt(b*b – 4*a*c)) / (2*a) 
//     root2 = (-b - sqrt(b*b – 4*a*c)) / (2*a)
{   
	float temp;					  // 求根过程中的b*b – 4*a*c
     
	temp = b * b - 4.0 * a * c;  // 求b*b – 4*a*c

     root1 = (-b + sqrt(temp) ) / ( 2.0 * a );  // 求两实根
     root2 = (-b - sqrt(temp) ) / ( 2.0 * a );
}
