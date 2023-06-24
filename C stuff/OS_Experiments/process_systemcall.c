/*Program 3.1*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>


int main()
{
    pid_t pid;
    int status;

    pid = fork();
    if(pid<0)
    {
        printf(stderr,"Failed");
        exit(-1);
    }
    else if(pid==0)
    {
        printf("Child with ID %d\n",getpid());
    }
    else
    {
        printf("Parent with ID %d\n",getpid());
        wait(&status);
        printf("Child Process terminated. Status %d",status);
    }
    return 0;
}