#include "socket.h"


//初始化socket'句柄的接口
int  socket_client_init(void **handle)
{
	return 0;
}

//发送socket网络报文
int socket_client_send(void *handle, unsigned char *buf, int buf_len)
{
	return 0;
}


//接收socket网络报文
int socket_client_recv(void *handle, unsigned char *buf, int *buf_len)
{
	return 0;
}

//释放socket句柄资源
int destory_socket(void *handle)
{
	return 0;
}