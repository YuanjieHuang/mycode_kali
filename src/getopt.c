#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
    int start = 0;
    int end = 0;
    int sum = 0;
    int opt;
    char *optstring = ":s:e:";
    //分析接收到的参数
    while((opt = getopt(argc, argv, optstring))!= -1){
        switch(opt){
            case 's': start = atoi(optarg); break;
            case 'e': end = atoi(optarg); break;
            case ':': puts("Missing parameter"); exit(1);
        }
    }
   
    //检测参数是否有效
    if(start<0 || end<=start){
        puts("Parameter error"); exit(2);
    }
   
    //打印接收到的参数
    printf("Received parameters: ");
    for(int i=0; i<argc; i++){
        printf("%s  ", argv[i]);
    }
    printf("\n");
   
    //计算累加的和
    for(int i=start; i<=end; i++){
        sum+=i;
    }
    printf("sum=%d\n", sum);
    return 0;
}