#include <iostream>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MULTIADDR "239.0.0.10"

using namespace std;

int main() {
    int fd;
    sockaddr_in broadaddr;
    in_addr imr_multiaddr;
    char sendBuf[1024];

    if((fd = socket(PF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
        exit(-1);
    }

    // 设置多播属性
    inet_pton(AF_INET, MULTIADDR,&imr_multiaddr);
    setsockopt(fd, IPPROTO_IP, IP_MULTICAST_IF, &imr_multiaddr, sizeof(imr_multiaddr));
    
    // 初始化发送端地址信息
    broadaddr.sin_family = PF_INET;
    broadaddr.sin_port = htons(9999);
    inet_pton(AF_INET, MULTIADDR, &broadaddr.sin_addr.s_addr);

    //通信
    int num = 0;
    while(1) {
        //发送数据
        sprintf(sendBuf,"组播... %d\n", num++);
        sendto(fd, sendBuf, strlen(sendBuf) + 1, 0, (sockaddr *)&broadaddr, sizeof(broadaddr));

        cout << "(SERVER) send data: " << sendBuf << endl;
        sleep(1);
    }

    close(fd);
    return 0;
}
