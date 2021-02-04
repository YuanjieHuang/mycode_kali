#include <stdio.h>

int main()
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
while(a[i]!=NULL)
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
}
