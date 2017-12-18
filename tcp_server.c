#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
int main()
{
	/* code */
	int welcomesocket,newsocket;
	char buffer[1024];
	struct sockaddr_in serverAddr;
	struct sockaddr_storage serverstorage;
	socklen_t addr_size;
	welcomesocket=socket(PF_INET,SOCK_STREAM,0);
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=htons(7891);
	serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero,'\0',sizeof serverAddr.sin_zero);
	bind(welcomesocket,(struct sockaddr *)&serverAddr,sizeof(serverAddr));
	if (listen(welcomesocket,5)==0)
	{
		/* code */
		printf("listening\n");
	}
	else
		printf("error\n");
	addr_size=sizeof serverstorage;
	newsocket=accept(welcomesocket,(struct sockaddr *)&serverstorage,&addr_size);
	strcpy(buffer,"Welcome to pes");
	send(newsocket,buffer,1024,1024);
	return 0;
}
