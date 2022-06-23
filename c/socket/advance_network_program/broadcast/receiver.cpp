#include <iostream>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MULTIADDR "239.0.0.10"

using namespace std;

int main() {
    int fd;
    sockaddr_in addr;
    ip_mreq op;
    char recvBuf[1024];
    int num = 0;

    if((fd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
        exit(-1);
    }

    //接收端绑定本地IP和端口
    addr.sin_family = PF_INET;
    addr.sin_port = htons(9999);
    addr.sin_addr.s_addr = INADDR_ANY;

    if(bind(fd, (sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(-1);
    }

    //加入到多播组
    inet_pton(AF_INET, MULTIADDR, &op.imr_multiaddr.s_addr);
    op.imr_interface.s_addr = INADDR_ANY;
    setsockopt(fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &op, sizeof(op));

    //通信
    while(1) {  
        //接收数据
        int num = recvfrom(fd, recvBuf, sizeof(recvBuf), 0, NULL, NULL);
        cout << "(Client) recv data: " << recvBuf << endl;
    }
    
    close(fd);
    return 0;
}
