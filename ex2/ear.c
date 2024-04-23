#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#define BUFLEN 1024

int main (int q, char *file[])
{	
 // write(1,"EAR STARTED",11);
  int sockfd, fd, len, n, LISTENPORT,c=1;
  char buffer[BUFLEN],o[BUFLEN]/*file[5]*/;
  struct sockaddr_in receiverAddr, senderAddr;
  scanf ("%d", &LISTENPORT);
  while(c!=0)
  {
  if ((sockfd = socket (AF_INET, SOCK_DGRAM, 0)) < 0)
    {
      perror ("socket system call failed");
      exit (EXIT_FAILURE);
    }

  memset (&receiverAddr, 0, sizeof (receiverAddr));
  memset (&senderAddr, 0, sizeof (senderAddr));

  receiverAddr.sin_family = AF_INET;
  receiverAddr.sin_addr.s_addr = INADDR_ANY;
  receiverAddr.sin_port = htons (LISTENPORT);
  if (bind(sockfd, (const struct sockaddr *) &receiverAddr,sizeof (receiverAddr)) < 0)
    {
      perror ("bind syscall failed");
      exit (EXIT_FAILURE);
    }
  len = sizeof (senderAddr);
  //write(1,"W",1);
  n =recvfrom (sockfd, (char *) buffer, BUFLEN, MSG_WAITALL,(struct sockaddr *) &senderAddr, &len);
  buffer[n] = '\0';
  fd=open(file[1],O_WRONLY | O_APPEND | O_CREAT,0644);
  write(fd,buffer,n);
  write(1,"S",1);
  close (fd);
  close(sockfd);
  }
return 0;
}

