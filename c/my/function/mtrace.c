#include <stdio.h>
#include <stdio.h>
#include <errno.h>
#include <mcheck.h>
int main()
{
    char * hello;
    setenv("MALLOC_TRACE", "output", 1);
    mtrace();
    if((hello = (char *) malloc(sizeof(char))) == NULL)
    {
        perror("cannot allocate memory.");
        return -1;
    }
    free(hello);
    return 0;
}