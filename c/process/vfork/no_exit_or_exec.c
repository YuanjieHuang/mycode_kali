    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
     
    int main(int argc, char *argv[])
    {
    	pid_t pid;
    	
    	pid = vfork();	// 创建进程
    	if(pid < 0){ // 出错
    		perror("vfork");
    	}
    	
    	if(0 == pid){ // 子进程
    	
    		printf("i am son\n");
    		sleep(1);
    		
    		// 子进程没有调用 exec 或 exit
    	}else if(pid > 0){ // 父进程
    		
    		printf("i am father\n");
    		sleep(1);
    	}
    	
    	return 0;
    }
