    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    int main(){
        char *s = "0123456789012345678901234567890";
        char *p;
        p = strchr(s, '5');
    printf("%s\n", s);
        printf("%s\n", p);
    system("sleep 1");

    p = strrchr(s, '5');
    printf("%s\n", s);
    printf("%s\n", p);


        char str[] = "I welcome any ideas from readers， of course.";
    char *rc=strpbrk(str,"come");
    printf("%s\n",rc);
        return 0;
    }