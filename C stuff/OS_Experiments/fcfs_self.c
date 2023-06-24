#include<stdio.h>

int queue[100][100];    // [Process_no][Burst_time]
int pno,bt;
int front=-1;
int rear=-1;
int p_temp,t_temp;

void enqueue(int p,int t)
{
    if(front==-1)
    {
        front = 0;
        rear = 0;
    }
    else
        rear++;
    queue[0][rear]=p;
    queue[1][rear]=t;
}

void dequeue()
{
    if(front>rear)
        return;
    p_temp=queue[0][front];
    t_temp=queue[1][front];
    front++;
}

void main()
{

    int n,p,t;
    printf("Enter number of processes : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nEnter Process Number : ");
        scanf("%d",&p);
        printf("\nEnter Burst Time :");
        scanf("%d",&t);
        enqueue(p,t);
    }

    // Printing Gantt Chart
    for(int i=0;i<n;i++)        // Top Line
    {
        printf("-----");
    }
    printf("\n");
    int temp_front = front;
    for(int i=0;i<n;i++)        // Printing Process Number
    {
        printf("|\t%d\t|",queue[0][temp_front]);
        temp_front++;
    }
    for(int i=0;i<n;i++)        // Bottom Line
    {
        printf("-----");
    }
    printf("\n");
    printf("\n0");
    temp_front = front;
    for(int i=0;i<n;i++)
    {
        printf("\t \t%d",queue[1][temp_front]);
    }
    int total_time=0;
    int turn_time=0;
    int wait_time=0;
    double avg_wt=0;
    double avg_tt=0;
    // Printing Table
    printf("Process Number\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time");
    for(int i=0;i<n;i++)
    {
        dequeue();
        turn_time = t_temp + wait_time;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\n",p_temp,t_temp,wait_time,turn_time + t_temp);
        total_time=t_temp+total_time;
        avg_wt = avg_wt + wait_time;
        avg_tt= avg_tt + turn_time;
    }
    printf("\nAverage Turnaround Time = %.2f\n",avg_tt/n);
    printf("\nAverage Waiting Time = %.2f\n",avg_wt/n);
}
