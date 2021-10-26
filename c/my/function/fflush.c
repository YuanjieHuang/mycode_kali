    #include <stdio.h>
    #include <stdlib.h>
    int main(){
        int a;
        char c;
       
        scanf("%d", &a);
        fflush(stdin);
        c = getchar();
        printf("a = %d, c = %c \n", a, c);
        return 0;
    }