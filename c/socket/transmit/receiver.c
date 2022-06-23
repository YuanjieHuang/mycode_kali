#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define PORT 8888
struct fileinfo
{
    char filename[1024];
    size_t sz;
};

int main()
{
    int sock = socket(AF_INET,SOCK_DGRAM,0);
    if(sock < 0) return 0;
    struct sockaddr_in recv;
    recv.sin_family = AF_INET;
    recv.sin_port = htons(PORT);
    recv.sin_addr.s_addr = inet_addr("127.0.0.1");
    int len = sizeof(recv);
    int ret = bind(sock,(struct sockaddr *)&recv,len);
    if(ret <0)
    {
        perror("bind");
    }
    
    struct sockaddr_in send;
    struct fileinfo info;
    recvfrom(sock,&info,sizeof(info),0,(struct sockaddr *)&send,&len);
    printf("file name %s size %lu\n",info.filename,info.sz);

    char name[1024] = {"file/"};
    strcat(name,info.filename);
    int fd = open("bak",O_CREAT|O_RDWR,0644);
    size_t sz = info.sz;
    while(sz) {
        char buf[1024] = {0};
        int ret = recvfrom(sock,buf,1024,0,(struct sockaddr *)&send,&len);
        write(fd,buf,ret);
        sz -=ret;
    }
    printf("recv over \n");
    close(fd);
    close(sock);
    return 0;
}