/* Non Premptive Code for FCFS*/
/* Turnaround time = Burst Time + Waiting Time
Completion Time = Arrival Time + Burst Time
Waiting Time = Completion Time of Previous Process - Arrival Time*/
#include<stdio.h>

void main()
{
    int bt[10];
    int wt[10];
    int pid[10];
    int ct[10];    // Completion Time
    int ar[10];
    

    wt[0]=0;
    ar[0]=0;
    printf("Process ID :");
    scanf("%d",&pid[0]);
    printf("Burst Time :");
    scanf("%d",&bt[0]);
    ct[0]=bt[0];

    for(int i=1;i<3;i++)
    {
        printf("Process ID :");
        scanf("%d",&pid[i]);
        printf("Burst Time :");
        scanf("%d",&bt[i]);
        printf("Enter Arrival Time :");
        scanf("%d",&ar[i]);
        ct[i]=bt[i]+ar[i];
        wt[i]=ct[i-1]-ar[i];
    }

    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    float tat;
    float twt;
    int k=1;

    for(int i=0;i<3;i++)
    {
        printf("P%d\t\t",pid[i]);
        printf("%d\t\t",ar[i]);
        printf("%d\t\t",bt[i]);
        printf("%d\t\t",wt[i]);
        printf("%d\t\t",bt[i]+wt[i]);
        printf("%d\t\t",ct[i]);
        printf("\n");
        tat+=wt[i]+bt[i];
        twt+=wt[i];
        k++;
    }

    float avg_wt = twt/k;
    float avg_tat = tat/k;
    printf("Average Waiting Time = %f\n",avg_wt);
    printf("Average Turnaround Time = %f\n",avg_tat);
}
/*
    for(int i=0;i<3;i++)
    {
        if(i==0)
        {
            for(int j=0;i<bt[i];j++)
            {
                printf("| P%d ")
            }
        }
        for(int j=0;i<ct[j]-ct[j-1];j++)
    }
}
*/