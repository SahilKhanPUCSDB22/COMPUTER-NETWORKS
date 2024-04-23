#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
                char* p[3]={"ear","mouth","brain"};
                char* files[3]={"etob1","btom1","etob1"};
                char* files2[3]={"<f1","<f2","btom1"};
                char* args[4];
                int pid[3];
                int i=0,re;
                while(i<3)
                {
                        args[0]=p[i];
                        args[1]=files[i];
                        args[2]=files2[i];
                        args[3]=NULL;
                        pid[i]=fork();
                        if(pid[i]==0)
                        {
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
                                
                        }
                        else
                        {
                                printf("Error Calling fork %d\n",i);
                                return 0;
                        }
                        i = i+1;
                }
return 0;
}
