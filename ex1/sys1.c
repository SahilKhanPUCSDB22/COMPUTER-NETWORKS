#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
int main(int a, char* f[])
{
	int nc,fd1;
	char huf[1024];
	fd1=open(f[2],O_RDONLY);
	
	if (fd1<0)
	{
		perror("file cannot be opened");
		exit(1);
	}
	nc=read(fd1,huf,100);
	for(int m=0;m<nc;m++)
	{
		 printf("%c",huf[m]);
	}
	printf("\n");
	close(fd1);

	int nb,fd;
	char buf[1024];
        fd=open(f[1],O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd<0)
	{
	perror("File cannot be opened");
	exit(1);
	}
	char c[1024];
	printf("Message:");
	scanf("%s",c);
	char *msg = c;
	nb=write(fd,msg,strlen(c));
	printf("num of bytes written : %d ",nb);
	printf("\n");
	close(fd);
	return 0;
}

