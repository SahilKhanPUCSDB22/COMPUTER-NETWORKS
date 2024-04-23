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

#define LISTENPORT 1235
#define REMOTEPORT 1234
#define BUFLEN 1024

void ear()
  {
      int sockfd, len, n;
  char buffer[BUFLEN];
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
  /*printf("sear waiting for data to be received: \n");*/
  n = recvfrom(sockfd, (char *)buffer, BUFLEN, MSG_WAITALL, (struct sockaddr *) &senderAddr, &len);
  buffer[n] = '\0';
  int c;
  int i=0;
  printf("Rec : %s",buffer);
  return;
  
  }
  
  
  void mouth()
  {
  int sockfd;
  char buffer[BUFLEN];
  char mes[1024];
   printf("\nSend :");
   scanf("%s",mes);
   if(strcmp(mes,"end")==0)
   {
   exit(0);
   }
   
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
  close(sockfd);
  return;
  }
int main()
{
int i=1;
while(i!=0){	
	  ear();
	mouth();
}
  return 0;
  }
  
