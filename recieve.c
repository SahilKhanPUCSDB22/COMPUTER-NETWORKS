#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#define limit 1024
#define LISTENPORT 1234
int main(int x , char* s[])
{
	int buffer[limit];
	int fd,sockfd,len,n;	
	fd=open(s[1],O_CREAT | O_TRUNC | O_RDWR, 0644);
	if(fd<0)
	{
		perror("");
		exit(1);
	}

  	struct sockaddr_in receiverAddr, senderAddr;
	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
  	{
    	perror("socket system call failed");
    	exit(EXIT_FAILURE);
  	}

  	memset(&receiverAddr, 0, sizeof(receiverAddr));
  	memset(&senderAddr, 0, sizeof(senderAddr));

  	receiverAddr.sin_family = AF_INET;
  	receiverAddr.sin_addr.s_addr = inet_addr(s[2]);
  	receiverAddr.sin_port = htons(LISTENPORT);

  	if(bind(sockfd, (const struct sockaddr *)&receiverAddr, sizeof(receiverAddr)) < 0)
  	{
    	perror("bind syscall failed");
    	exit(EXIT_FAILURE);
  	}
  	len = sizeof(senderAddr);

	int c=1,r=0;
  	while(c!=0)
	{
		n = recvfrom(sockfd, buffer, limit , MSG_WAITALL, (struct sockaddr *) &senderAddr, &len);
		write(fd,buffer,n);
		r=r+n;
		if(n<limit)
		{
			c=0;
		}
	}
	close(fd);
	close(sockfd);
	printf("%d",r);
	return 0;
}	
