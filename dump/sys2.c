#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
//#include<string.h>


int main(int a, char *f[])
{
	FILE* fd;
	fd= fopen(f[1],"r");
	if(fd==NULL)
	{
		printf("file cannot ne opened \n");
		exit(1);
	}
	char ch;
	while(!feof(fd))
	{
	ch=fgetc(fd);
	printf("%c",ch);
	}
	fclose(fd);

	fd= fopen (f[2],"w");
	if(fd==NULL)
	{
		printf("opening failed");
		exit(1);
	}

	char *s="my name is sahil";
	//char s[100]=getchar();

	fputs(s,fd);
	printf("print success!!"); 
	fclose(fd);

	return 0;
}

