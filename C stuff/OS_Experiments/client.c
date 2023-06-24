// Experiment 4

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<string.h>
#include<sys/shm.h>

int main()
{
    void *shared_memory;
    char buff[100];
    int shmid;
    shmid = shmget((key_t)3000,27,0666);
    printf("Key of shared memory is %d\n",shmid);
    shared_memory = shmat(shmid,NULL,0);
    printf("Process attached at %p\n",shared_memory);
    printf("Data read from shared memory is %s\n",(char*)shared_memory);
}