#include<stdio.h>
#include<unistd.h>
int main(void)
{
int pid[2],i=0,re;
char *pro= "brain";
char *args[2];

args[0]=pro;
args[1]="etob1";
args[2]="btom1";

pid[i]=fork();
if(pid[i]>=0)
{
	if(pid[i] == 0)
	{
		re=execv(pro,(char **) args);
		if(re==-1)
		{
			printf("Error free");
			return 0;
		}
		return 0;
	}
}
else 
{
	printf("Error calling fork() \n");
	return 0;
}
return 0;
}

