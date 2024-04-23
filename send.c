#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define REMOTEPORT 1234
#define limit 1024
int main(int x, char* file[])
{
	int fd;
	fd=open(file[1],O_RDONLY);
	int nb;
	nb=lseek(fd,0,SEEK_END);
	printf("%d",nb);
	char buffer[limit];
	lseek(fd,0,SEEK_SET);
	int c=1,i=1,w=limit,sockfd;
	
  	struct sockaddr_in   receiverAddr;
  	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
  	{
    	perror("socket failed");
    	exit(EXIT_FAILURE);
  	}

  	memset(&receiverAddr, 0, sizeof(receiverAddr));
  	receiverAddr.sin_family = AF_INET;
  	receiverAddr.sin_port = htons(REMOTEPORT);
  	receiverAddr.sin_addr.s_addr =inet_addr(file[2]);
	

	while(c!=0)
	{
			
			int m = read(fd,buffer,limit);
			sendto(sockfd, (const char *)buffer, m , 0, (const struct sockaddr *) &receiverAddr, sizeof(receiverAddr)); 
			usleep(limit);
			nb=nb-m;
			if(nb==0)
			{
				c=0;
			}
	}
	close(fd);
	close(sockfd);
	return 0;
}



