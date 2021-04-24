#include<cstdio>
#include<climits>
using namespace std;
#define STR(s) #s
#define CONS(a,b) int(a##e##b)
int main(){
printf(STR(vck)); // output vck
printf("%d/n", CONS(2,3)); // 2000

#define A 2
#define _STR(s) #s
#define STR1(s) _STR(s) // 转换宏
#define _CONS(a,b) int(a##e##b)
#define CONS1(a,b) _CONS(a,b) // 转换宏
printf("int max: %s/n", STR1(INT_MAX)); // INT_MAX#include<climits>
printf("%s/n", CONS1(A, A));
return 0;
}