#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 8888
struct fileinfo
{
    char filename[1024];
    size_t sz;
};

int main(int argc,char **argv)
{
    int sock = socket(AF_INET,SOCK_DGRAM,0);
    if(sock < 0) return 0;
    struct sockaddr_in send;
    send.sin_family = AF_INET;
    send.sin_port = htons(PORT);
    send.sin_addr.s_addr = inet_addr("127.0.0.1");
    int len = sizeof(send);
    int ret = bind(sock,(struct sockaddr *)&send,len);
    if(ret <0) {
        perror("bind");
    }
    
    struct fileinfo info;
    int fd = open(argv[1],O_RDONLY);
    struct stat st;
    fstat(fd,&st);
    strcpy(info.filename,strrchr(argv[1],'/')+1);
    printf("filename:%s\n", info.filename);
    info.sz = st.st_size;
    
    sendto(sock,&info,sizeof(info),0,(struct sockaddr *)&send,len); 
    size_t sz = info.sz;
    while(sz){
        char buf[1024] = {0};
        int ret = read(fd,buf,1024);
        sendto(sock,buf,ret,0,(struct sockaddr *)&send,len);
        sz -=ret;
    }   
    printf("send over\n");
    close(fd);
    close(sock);
    return 0;
}