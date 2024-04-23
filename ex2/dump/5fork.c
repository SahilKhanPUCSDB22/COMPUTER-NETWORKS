#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	char* ear[]={"ear","etob1","<f1",NULL};
	char* mouth[]={"mouth","btom1","<f2",NULL};
	int f;
	f=fork();
	if(f==0)
	{
		int re=execv(ear[0],ear);
		if(re==-1)
		{
			perror("");
			exit(0);
		}
	}
	else
	{
		int r=execv(mouth[0],mouth);
		if(r==-1)
		{
			perror("");
			exit(0);
		}
	}
	while(1)
	{
	}
}
