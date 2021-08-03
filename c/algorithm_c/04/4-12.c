#include <time.h> 
#include <stdio.h> 
int main() 
{ 
   clock_t start, end;
   /*程序运行到现在的时间*/
   start = clock(); 
   /*间隔1秒*/
   sleep(1);
   /*程序运行到现在的时间*/
   end = clock(); 
   printf("The time was: %f\n", (end - start) / CLOCKS_PER_SEC); 
   return 0; 
}

