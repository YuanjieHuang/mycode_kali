#include "stdio.h" 
#include "time.h"

main(void)
{ 
    struct tm *ptr; 
    time_t lt; 
    lt =time(NULL); 
    ptr=gmtime(&lt); 
    printf(asctime(ptr)); 
    printf(ctime(&lt)); 
   
} 
