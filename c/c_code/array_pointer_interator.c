#include <stdio.h>

void _1D_array_pointer_interator()
{
   char a[30]="Array and pointer interator.";

   char *p;
   int i;
 
   i=0;
   while(a[i]!='\0')
   {
      printf("%c",a[i]) ;
      i++;
   }
   printf("\n") ;
   p=a;

   printf("%s\n",p) ;
   while(*p!='\0')
   {
      printf("%c",*p) ;
      p++;
   }
}


int _2D_array_pointer_interator()
{
    int i=10 , m , n ;
    int a[4][5];
    //int (*p)[N] = a;    /*其中N是二维数组a[M][N]的列数, 是一个数字, 数组长度不能定义成变量*/
    int (*p)[5] = a;   //记住这种定义格式
    int *ptr = &a[0][0];
    /*
      二维数组就是一维数组，二维数组 a[3][4] 就是有三个元素 a[0]、a[1]、a[2] 的一维数组，
      所以数组 a 的第一个元素不是 a[0][0]，而是 a[0]，所以数组名 a 表示的不是元素 a[0][0] 的地址，
      而是 a[0] 的地址
    */
    printf("%p %p %p %p %p\n",&a[0][0],&a[0],&a,a[0],a);
    printf("%d %d \n",sizeof(a),sizeof(a[0]));
   //  typeof()
    for(m=0;m<4;m++)
    {
       for(n=0;n<5;n++)
       {
          a[m][n]=i;
          i++;
       }
    }
    
    for(m=0;m<4;m++)
    {
       for(n=0;n<5;n++)
       {
         // printf("a[%d][%d] addr=%p  ",m,n,&a[m][n]);
         printf("a[%d][%d]=%d  ",m,n,a[m][n]);
         printf("a[%d][%d]=%d  ",m,n,*(*(p+m)+n));
         printf("a[%d][%d]=%d  ",m,n,*(ptr+m*5+n));
       }
       printf("\n");
    }
    return 0;

}

int count_ASCII_by_type()
{
   char a[100];
   int i,uper,lower,marks,num;
   i=0;
   uper=0;
   lower=0;
   marks=0;
   num=0;
   printf("please input a string:\n") ;
   scanf("%s",a);
   i=0;
   while(a[i]!='\0')
   {
      if(a[i]<=57&&a[i]>=48)
      {
         num++;
      }
      else
      {
         if(a[i]<=90&&a[i]>=65)
         {
            uper++;
         }
         else
         {
            if(a[i]<=122&&a[i]>=97)
            {
               lower++;
            }
            else
            {
               marks++;
            }
         }

      }
      i++;
   }
   printf("total chars: %d \n",i) ;
   printf("uper chars: %d \n",uper) ;
   printf("lower chars: %d \n",lower) ;
   printf("number chars: %d \n",num) ;
   printf("other chars: %d \n",marks) ;
   return 0;
}
int main()
{
   _1D_array_pointer_interator();
   _2D_array_pointer_interator();

   return 0;
}