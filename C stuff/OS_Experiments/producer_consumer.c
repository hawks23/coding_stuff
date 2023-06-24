#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#define SIZE 2
sem_t empty, full, mutex;
int in=0,out=0;
int buffer[SIZE];
void *Pr_Item(void*);
void *Cr_Item(void*);

void main()
{
	pthread_t P,C;
	sem_init(&empty,0,SIZE);
	sem_init(&full,0,0);
	sem_init(&mutex,0,1);
	pthread_create(&P,NULL,(void*)Pr_Item,NULL);
	pthread_create(&C,NULL,(void*)Cr_Item,NULL);
	pthread_join(P,NULL);
}

void *Pr_Item(void *args)
{
	while(1)
	{
		int item;
		item=rand()%10;
		sem_wait(&empty);
		sem_wait(&mutex);
		buffer[in]=item;
		printf("\nProducer produced item : %d ",item);
		sleep(1);
		in=(in+1)%SIZE;
		sem_post(&mutex);
		sem_post(&full);
	}
}

void *Cr_Item(void *arg)
{
	while(1)
	{
		int item;
		sem_wait(&full);
		sem_wait(&mutex);
		item=buffer[out];
		printf("\nConsumer consumed item : %d ",item);
		sleep(1);
		out=(out +1)%SIZE;
		sem_post(&mutex);
		sem_post(&empty);
	}
}
