#include <stdio.h>

int     a = 2, b = 1, c;


int main(void)
{
    int     tmp;

    asm (".intel_syntax noprefix");
        asm ("mov   eax, [a]");
        asm ("sub   eax, [b]");
        asm ("mov   [c], eax");
    asm (".att_syntax noprefix");

    printf("%d - %d = %d\n", a, b, c);

    return (0);
}
