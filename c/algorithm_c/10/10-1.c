#include <stdio.h>
/*输入一个字符串，并输出*/
inputString()
{
    char c, lastc = 'a';
    c = getchar();
    while(c!=EOF)
    {
        if(c!=' '){
            putchar(c); 
            lastc = c;
            c = getchar();    
            }
        else{
            if(lastc!=' ')
                putchar(c);   
            lastc = c;
            c = getchar();
        }
    }
}
main()
{
     inputString();
}
