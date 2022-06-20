#include <stdio.h>
#define ESC_START     "\033["
#define ESC_END       "\033[0m"
#define COLOR_FATAL   "31;40;5m"
#define COLOR_ALERT   "31;40;1m"
#define COLOR_CRIT    "31;40;1m"
#define COLOR_ERROR   "31;40;1m"
#define COLOR_WARN    "33;40;1m"
#define COLOR_NOTICE  "34;40;1m"
#define COLOR_INFO    "32;40;1m"
#define COLOR_DEBUG   "36;40;1m"
#define COLOR_TRACE   "37;40;1m"
 
#define Msg_Info(format, ...)      (printf("[INFO]-[%s]-[%s]-[%d]:" format, __FILE__, __FUNCTION__ , __LINE__, ##__VA_ARGS__))
 
#define Msg_Debug(format, args...) (printf( ESC_START COLOR_DEBUG "[DEBUG]-[%s]-[%s]-[%d]:" format ESC_END, __FILE__, __FUNCTION__ , __LINE__, ##args))
 
#define Msg_Warn(format, args...)  (printf( ESC_START COLOR_WARN "[WARN]-[%s]-[%s]-[%d]:" format ESC_END, __FILE__, __FUNCTION__ , __LINE__, ##args))
 
#define Msg_Error(format, args...) (printf( ESC_START COLOR_ERROR "[ERROR]-[%s]-[%s]-[%d]:" format ESC_END, __FILE__, __FUNCTION__ , __LINE__, ##args))
  
#define xxxlog(fmt, ...) (printf("[%s:%d->%s] " fmt, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__))
 
 int main(int argc, char *argv[])
 {

    Msg_Info("test!\n");
    Msg_Warn("%d\n",10);
    Msg_Error("%s\n","error");
    Msg_Debug("Debug\n");

     int num = 99;
     printf("num"  "%d\n",num);
     xxxlog("hello, world!\n");
     xxxlog("num is %d\n", num);
 
     return 0;
 }