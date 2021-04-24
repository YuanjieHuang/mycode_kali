#define trace(x, format) printf(#x " = %" #format "\n", x)    
#define trace2(i) trace(x##i, d)   
  
#include <stdio.h> 
#include <string.h>
#include "macro.h"

 struct student
 {
     char gender;
     int id;
     int age;
     char name[20];
 };
int main(void)
{
    int i = 1;  
    char *s = "three";    
    float x = 2.0;  
  
    trace(i, d);                // 相当于 printf("x = %d\n", x)  
    trace(x, f);                // 相当于 printf("x = %f\n", x)  
    trace(s, s);                // 相当于 printf("x = %s\n", x)  
  
    int x1 = 1, x2 = 2, x3 = 3;    
    trace2(1);                  // 相当于 trace(x1, d)  
    trace2(2);                  // 相当于 trace(x2, d)  
    trace2(3);                  // 相当于 trace(x3, d) 
    // int bTest = 0x123456; byte m = MEM_B((&bTest));/*m=0x56*/ int n = MEM_W((&bTest));/*n=0x3456*/ 
    int y =4;
    PSQR(y);
    PSQR(2+4);

    int XNAME(10)=12;//int x10=12;
    PXN(10);//printf("x10 = %d\n", x10);

    int wt=1,sp=2;
    PR("hello\n");
    PR("weight = %d, shipping = %d\n",wt,sp);
    printf("%d\n",PP_NARG(1,2,3,4,1,1,5,6,7,8,9.10,11,12,13,14,15,16,17,18));

     int gender_offset, id_offset, age_offset, name_offset;
     gender_offset = offsetof(struct student, gender);
     id_offset = offsetof(struct student, id);
     age_offset = offsetof(struct student, age);
     name_offset = offsetof(struct student, name);
     printf("gender_offset = %d\n", gender_offset);
     printf("id_offset = %d\n", id_offset);
     printf("age_offset = %d\n", age_offset);
     printf("name_offset = %d\n", name_offset);

     struct student stu;
     struct student *pstu;
 
     stu.gender = '1';
     stu.id = 9527;
     stu.age = 24;
     strcpy(stu.name, "zhouxingxing");
     // 根据"id地址" 获取 "结构体的地址"。
     pstu = container_of(&stu.id, struct student, id);
     // 根据获取到的结构体student的地址，访问其它成员
     printf("gender= %c\n", pstu->gender);
     printf("age= %d\n", pstu->age);
     printf("name= %s\n", pstu->name);
    return 0;
}