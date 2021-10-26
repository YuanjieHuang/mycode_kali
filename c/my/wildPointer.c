#include<stdio.h>
#include<stdlib.h>
#include <string.h>

 int main()
 {
    char *p=(char *)malloc(sizeof(char)*100);
   strcpy(p, "hello"); 
   printf("%s ",p); 
   free(p); // p 所指的内存被释放，但是p所指的地址仍然不变 
   if(p != NULL) // 没有起到防错作用 
   {
    strcpy(p, "world"); // 出错 
    printf("%s \n",p);
   }
}