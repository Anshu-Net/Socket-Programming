#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
int main()
{
	/* code */
	int clientsocket;
	char buffer[1024];
	struct sockaddr_in serverAddr;
	socklen_t addr_size;
	clientsocket=socket(PF_INET,SOCK_STREAM,0);
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=htons(7891);
	serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero,'\0',sizeof serverAddr.sin_zero);
	addr_size=sizeof serverAddr;
	connect(clientsocket,(struct sockaddr *)&serverAddr,addr_size);
	recv(clientsocket,buffer,1024,1024);
	printf("Date received: %s\n",buffer);
	return 0;
}
