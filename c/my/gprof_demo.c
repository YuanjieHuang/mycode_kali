#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
static void my_print (char *); 
static void my_print2 (char *); 
 
int main () 
{ 
    char my_string[] = "hello world!"; 
    my_print (my_string); 
    my_print2 (my_string); 
    my_print (my_string); 
    return 0;
} 
 
void count_sum() 
{ 
    int i,sum=0; 
    for(i=0; i<1000000; i++) 
    sum += i; 
} 
void my_print (char *string) 
{ 
    count_sum(); 
    printf ("The string is %s \n", string); 
} 
 
void my_print2 (char *string) 
{ 
    char *string2; int size, i,sum =0; count_sum(); 
    size = strlen (string); 
    string2 = (char *) malloc (size + 1);
    for (i = 0; i < size; i++) 
    string2[size -1 - i] = string[i]; string2[size] ='\0';
    for(i=0; i<5000000; i++) 
    sum += i; 
    printf ("The string printed backward is %s \n", string2); 
} 
/*
run steps:
gcc  –pg gprof_demo.c
./a.out
gprof a.out gmon.out -b
*/
