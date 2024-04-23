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

#define BUFLEN 1024
#define LISTENPORT 1234
#define REMOTEPORT 1235
int main()
{
  //ear
  
  int sockfd, len, n;
  char bufferr[BUFLEN];
  struct sockaddr_in receiverAddr, senderAddr;

  if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
  {
    perror("socket system call failed");
    exit(EXIT_FAILURE);
  }

  memset(&receiverAddr, 0, sizeof(receiverAddr));
  memset(&senderAddr, 0, sizeof(senderAddr));

  receiverAddr.sin_family = AF_INET;
  receiverAddr.sin_addr.s_addr = INADDR_ANY;
  receiverAddr.sin_port = htons(LISTENPORT);

  if(bind(sockfd, (const struct sockaddr *)&receiverAddr, sizeof(receiverAddr)) < 0)
  {
    perror("bind syscall failed");
    exit(EXIT_FAILURE);
  }
  len = sizeof(senderAddr);
  printf("sear waiting for data to be received: \n");
  n = recvfrom(sockfd, (char *)bufferr, BUFLEN, MSG_WAITALL, (struct sockaddr *) &senderAddr, &len);
  bufferr[n] = '\0';
  int fd;
  fd = open("etob",O_WRONLY | O_CREAT | O_TRUNC , 0644);
  if(fd<0)
  {
	  printf("Error opening the file");
	  exit(1);
  }
  write(fd,bufferr,strlen(bufferr));
  close(fd);
  close(sockfd);

  // brain

int nb;
char buff[1024],tuff[1024];
fd=open("etob",O_RDONLY );
if(fd<0)
{
	perror("Unable to open file");
	exit(1);
}
nb=read(fd,buff,1024);
printf("Message:");
int m=0;
while(m<nb)
{
	printf("%c",buff[m]);
	m=m+1;

}

close(fd);

printf("Response :");
scanf("%s",tuff);

fd=open("btom",O_WRONLY | O_CREAT | O_TRUNC , 0644);
if(fd<0)
{
	perror("Unable to open file");
	exit(1);
}

write(fd,tuff,strlen(tuff));

  close(fd);

  //mouthhhhhhhhhh//

  char buffer[BUFLEN];
  char mes[1024];
  fd=open("btom",O_RDONLY);
	
	if (fd<0)
	{
		perror("file cannot be opened");
		exit(1);
	}
  read(fd,mes,1024);
  struct sockaddr_in   receiverAddrr;
  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
  {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  memset(&receiverAddrr, 0, sizeof(receiverAddrr));
  receiverAddrr.sin_family = AF_INET;
  receiverAddrr.sin_port = htons(REMOTEPORT);
  receiverAddrr.sin_addr.s_addr = INADDR_ANY;
  sendto(sockfd,mes , strlen(mes), 0, (const struct sockaddr *) &receiverAddrr, sizeof(receiverAddrr));
  close(sockfd);
  close(fd);

  return 0;
  }
