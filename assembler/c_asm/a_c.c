#include <stdio.h>
 
 #if 1
 int msvc_div64(int hi, int lo, int divisor, int *premainder)
 {
    int quotient, tmp;
    __asm__ 
    {

        mov   edx, hi
        mov   eax, lo
        idiv   divisor
        mov   quotient, eax
        mov   tmp, edx
        mov ecx, premainder   // Or this I guess?
        mov   [ecx], edxe
    }
    *premainder = tmp;
    return quotient;     // or omit the return with a value in eax
 }

#else 
// GNU C
// change everything to int64_t to do 128b/64b -> 64b division
// MSVC doesn't do x86-64 inline asm, so we'll use 32bit to be comparable
int gcc_div64(int lo, int hi, int *premainder, int divisor) {
    int quotient, rem;
    asm ("idivl  %[divsrc]"
          : "=a" (quotient), "=d" (rem)    // a means eax,  d means edx
          : "d" (hi), "a" (lo),
            [divsrc] "rm" (divisor)        // Could have just used %0 instead of naming divsrc
            // note the "rm" to allow the src to be in a register or not, whatever gcc chooses.
            // "rmi" would also allow an immediate, but unlike adc, idiv doesn't have an immediate form
          : // no clobbers
        );
    *premainder = rem;
    return quotient;
}
#endif

int main()
{
    int lo=0,  hi=0, premainder=0,  divisor=0;
    gcc_div64( lo,  hi, &premainder,  divisor);
    #if 0
    int result = 0;
    int input = 1;
 
    int a = 1;
    int b = 2;
 
    asm volatile (
        "movl %1, %0\n"
        : "=r"(result)
        : "r"(input)
        );
 
    printf("result = %d\n", result);
    printf("input = %d\n", input);
 
    asm volatile (
        "movl %%eax, %%ecx;"
        "movl %%ebx, %%eax\n"
        "movl %%ecx, %%ebx;"
        : "=a"(a), "=b"(b)
        : "a"(4), "b"(5)
        );
 
    printf("a = %d\n", a);
    printf("b = %d\n", b);
 
    return 0;
#endif
    

}