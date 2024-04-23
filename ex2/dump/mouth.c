#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <string.h>

//reads from brain
//sends to ear on different port

//#define REMOTEPORT 1234
#define BUFLEN 1024

int main(int i,char* f[])
{
  int sockfd,REMOTEPORT;
  char buffer[BUFLEN];
  scanf("%d",&REMOTEPORT);
  char mes[1024];
  int fd;
  
  fd=open(f[1],O_RDONLY);
	if (fd<0)
	{
		perror("file cannot be opened");
		exit(1);
	}
  read(fd,mes,1024);
  struct sockaddr_in   receiverAddr;
  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
  {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  memset(&receiverAddr, 0, sizeof(receiverAddr));
  receiverAddr.sin_family = AF_INET;
  receiverAddr.sin_port = htons(REMOTEPORT);
  receiverAddr.sin_addr.s_addr = INADDR_ANY;
  sendto(sockfd, mes , strlen(mes), 0, (const struct sockaddr *) &receiverAddr, sizeof(receiverAddr));
  printf("Sent");
  close(sockfd);
  close(fd);

  return 0;
}

