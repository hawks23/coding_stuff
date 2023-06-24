#include <stdio.h>
int a[100][100];
int front=-1;
int rear=-1;
int ptemp,ttemp;
int totalt=0;
int avgwt=0,avgtt=0;

void enqueue(int p, int t)	// p is process number and t is burst time
{
	if(front == -1)
	{
		front++;
		rear++;
	}
	else
		rear++;
	a[rear][0]=p;
	a[rear][1]=t;
}

void dequeue()
{
	if(front>rear)
		return;
	ttemp=a[front][1];
	ptemp=a[front][0];
	front++;
}

void main()
{
	printf("Enter the no of processes \n");
	int n; scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		printf("Enter the process number and burst time \n");
		int p;int t;
		scanf("%d%d",&p,&t);
		enqueue(p,t);
	}

	// Printing Gantt Chart
	printf("\n\n Gantt chart \n");
	for(int box=0;box<n;box++)	// Top Line
	{
		printf("---------");
	}
	printf("\n");
	int tt=0;
	int tf=0;
	for(int box=0;box<n;box++)		// Process Number
	{
		printf("|   %d   |",a[tf][0]);
		tf++;
	}
	printf("\n");
	for(int i=0;i<n;i++)		// Bottom Line
	{
		printf("---------");
	}
	tf=0;
	printf("\n0");
	for(int i=0;i<n;i++)
	{
		tt = tt + a[tf][1];
		printf("      %d   ",tt);
		tf++;
	}
	// t is burst time
	printf("\n\nprocess 		burst time 		waiting time 		turnaroundtime\n");
	for(int j=0;j<n;j++)
	{
		dequeue();
		int p=ptemp;
		int t=ttemp;
		printf("   %d   		         %d     		          %d      		    %d\n",p,t,totalt,totalt+t);
		avgwt=avgwt+totalt;
		avgtt=avgtt+totalt+t;
		totalt=totalt+t;
	}
	printf("\n the average waiting time is %.2f \n the average turaroundtime is %.2f \n",((float)avgwt/n),((float)avgtt/n));
}
