    #include <stdio.h>
    int main(){
        char str[30];
        char c;
        int i;
        for(c=65,i=0; c<=90; c++,i++){
            str[i] = c;
        }
        printf("%s\n", str);
        return 0;
    }