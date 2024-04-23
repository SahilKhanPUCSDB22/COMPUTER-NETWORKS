#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
void main()
{
int a[3];
int i=0;
while(i<3)
{
	a[i]=fork();
	if(a[i]==0)
	{
		printf("Child");
	}
	
	else
	{
printf("parent");
	}
	i=i+1;
}


}
