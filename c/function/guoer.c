#include <stdio.h>
#include <string.h>
#define M 10
/**********found**********/
void fun(char (*ss) __1__, int k)
{ int i=0 ;
/**********found**********/
while(i< __2__) {
ss[i][k]=__3__; i++;}
}
main()
{ char x[N][M]={"Create","Modify",
"Sort","skip", "Delete"};

int i;

printf("\nThe original string\n\n");

for(i=0;i<N;i++)puts(x[i]);
printf("\n");

fun(x,4);

printf("\nThe string after deleted:
\n\n");

for(i=0; i<N; i++) puts(x[i]);
printf("\n");
}
