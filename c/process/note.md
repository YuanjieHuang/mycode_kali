进程返回值和结束方式：
子进程通过exit/_exit/return返回某个值（0-255）

父进程调用wait(&status)回收

WIFEXITED(%status)      判断子进程是否正常结束
WEXITSTATUS（status)	  获取子进程返回值
WIFSIGALED（status)     判断子进程是否被信号结束
WTERMSIG(status)	    获取结束子进程的信号类型

