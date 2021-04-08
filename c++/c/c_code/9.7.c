#include <stdio.h>

void myresult(int x);
char result(int x);

int main()
{
   
   int i=1 ;
   while(i!=0)
   {
     scanf("%d",&i);
     myresult(i);
   }
}

void myresult(int x)
{
   char s;
   if(x>0&&x<=100)
   {
      s=result(x);
      printf("%c\n",s);
   }
   else
   {
      printf("error.\n",s);
   }

}

char result(int x)
{
   char s;
   if(x>=90)
   {
     s='A';
   }
   else
   {
      if(x>=80)
      {
         s='B';
      }
      else
      {
         if(x>=70)
         {
            s='C';
         }
         else
         {
            if(x>=60)
            {
               s='D';
            }
            else
            {
             s='E';
            }

         }

      }
   }
   return(s);
}



