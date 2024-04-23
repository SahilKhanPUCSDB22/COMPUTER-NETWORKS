#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>

int main (int x, char* file[])
{
 // write(1,"MOUTH STARTED",13);
  int fd, old = 0,new=0,nb=0,port,sockfd,c=1;
  scanf("%d",&port);
  char temp[1024], buf[1024];
  fd = open (file[1], O_RDONLY);
  struct sockaddr_in receiverAddr;

  fd = open (file[1], O_RDONLY);
  if (fd < 0)
    {
      perror ("Error//");
      return 0;
    }

  old = lseek(fd,0,SEEK_END);
  
  while (c!=0)
    {
      fd = open (file[1], O_RDONLY);
      if (fd < 0)
	{
	  perror ("Error");
	  return 0;
	}
        new = lseek (fd, 0, SEEK_END);				
	
	if ((new - old) > 0)				
	{ 
	    		if ((sockfd = socket (AF_INET, SOCK_DGRAM, 0)) < 0)
	      		{
				perror ("socket failed");
				exit (EXIT_FAILURE);
	      		}
	    	
	    		memset (&receiverAddr, 0, sizeof (receiverAddr));
	    		receiverAddr.sin_family = AF_INET;
	    		receiverAddr.sin_port = htons (port);
	    		receiverAddr.sin_addr.s_addr = INADDR_ANY;
	  
	    		lseek (fd, old, SEEK_SET);		
	    		nb = read (fd, buf, 1024);
			buf[nb++] = '\0';  		
			sendto (sockfd, buf, strlen (buf), 0,(const struct sockaddr *) &receiverAddr,sizeof (receiverAddr));
//	    		write(1,"Sent",4);
    		        close (sockfd);
	    		old = new;
	}
	close (fd);
    }

  	return 0;
}
