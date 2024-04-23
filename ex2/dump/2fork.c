#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
void main()
{
	int f= fork();
	if (f==0)
	{
		char *p=("mouth");
		char *args[4];
		args[0]=p;
		args[1]="btom1";
		args[2]="<f2";          
		args[3]=NULL;
		int e=execv(p,args);
		if(e==-1)
		{
			printf("fork failed");
		}
		printf("Child");
	}

	if (f>0)
	{
		printf("Parent");
	}
}
