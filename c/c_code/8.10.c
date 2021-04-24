#include <stdio.h>
void main()
{
    char name[6][10];
    int score[6][5];

    int i  ;
 
    for(i=0;i<6;i++)
    {
       printf("please input the name:\n");
       scanf("%s",name[i]);

       printf("score ,math:\n");
       scanf("%d",&score[i][0]);

       printf("score ,English:\n");
       scanf("%d",&score[i][1]);

       printf("score ,Chinese:\n");
       scanf("%d",&score[i][2]);

       score[i][3] =  score[i][0]+score[i][1]+score[i][2];
       score[i][4]= (int)(score[i][3] /3);
    }
     printf("result:\n math  English Chinese  total  average :\n");
    for(i=0;i<6;i++)
    {
       printf("%s: %d   %d    %d    %d   %d  \n",name[i],score[i][0],score[i][1],score[i][2],score[i][3],score[i][4]);
    }


}
