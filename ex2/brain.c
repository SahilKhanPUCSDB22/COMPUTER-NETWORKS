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

/*
 * connect the sbrain to sear and smouth 
 * */
int main(int xx,char* f[])
{

		char* p[2]={"ear","mouth"};
		char* files[2]={"etob1 < f1","btom1 < f2"};
		char* args[3];
		int pid[2];
		int i=0,re;
		while(i<2)
		{
			args[0]=p[i];
			args[1]=files[i];
			args[2]=NULL;
			pid[i]=fork();
				if(pid[i]==0)
				{	
					re=execv(p[i],args);
					if(re==-1)
					{
						perror("");
						return 0;
					}
					return 0;
				}
				
			if(pid[i]==-1)
			{
				printf("Error Calling fork %d\n",i);
			}
			i = i+1;
		}


	int fd,fd1,nb=0,old=0,new=0,c=1;
	char buff[1024],tuff[1024];
	fd=open(f[1],O_RDONLY);
	if(fd<0)
	{
	perror("File failed");
	exit(1);
	}
	old=lseek(fd,0,SEEK_END);
	close(fd);
	write(1,"B STD",5);
	while(c!=0)
		{
			fd=open(f[1],O_RDONLY );
			if(fd<0)
			{
				perror("Unable to open file");
				exit(1);
			}
			new=lseek(fd,0,SEEK_END);

			if(new > old)//check for any change in file
			{
				lseek(fd,old,SEEK_SET);
				nb=read(fd,buff,1024);
				write(1,"Message:",8);
				write(1,buff,nb);
				close(fd);

				write(1,"Response :",10);
				int r=read(0,tuff,1024);
				fd1=open(f[2],O_WRONLY | O_CREAT | O_APPEND , 0644);
				if(fd1<0)
				{
					perror("Unable to open file");
					exit(1);
				}
				write(fd1,tuff,r);
				old=new;
				close(fd1);
			}
			close(fd);
		}
return 0;
}


