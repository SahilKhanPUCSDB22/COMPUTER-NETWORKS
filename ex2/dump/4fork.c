#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int  main()
{
	char* p[2]={"ear","mouth"};
	char* files[2]={"etob1","btom1"};
	char* files2[2]={"<f1","<f2"};
	char* args[4];
	int pid[2];
	int i=0;
	while(i<2)
	{
		args[0]=p[i];
		args[1]=files[i];
		args[2]=files2[i];
		args[3]=NULL;
		pid[i]=fork();
		if(pid[i]==0)
		{
			int re=execv(p[i],args);
			if(re==-1)
			{
				perror("");
				exit(1);
			}
			exit(1);
		}
		i=i+1;
	}
return 0;	
}


