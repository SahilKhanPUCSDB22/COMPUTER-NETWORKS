#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
void main()
{
	char* p="./mouth";
	char* args[4];
	args[0]=p;
	args[1]="btom1";
	args[2]="<f2";
	args[3]=NULL;
	int f;
	f=fork();
	if(f==0)
	{
		printf("child here");
		int re=execv(p,(char**)args);
		if(re==-1)
		{
			printf("Error in exec");
			exit(1);
		}
	}
	else 
		printf("parent here");


}
