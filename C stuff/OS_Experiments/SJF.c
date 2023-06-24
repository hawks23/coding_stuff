#include<stdio.h>
void main()
{
	int i,n,p[10],min,k=0,btime=0;
	int bt[10],compt[100],temp,j,at[10],wt[10],tt[10],ta=1,sum=1;
	float wavg=0,tavg=0,tsum=0,wsum=0;
	printf("Enter the no of processes :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the id:");
		scanf("%d",&p[i]);
		printf("Enter the burst time of %d process:",i+1);
		scanf("%d",&bt[i]);
		printf("Enter the arrival time of %d process(Starts at 1):",i+1);
		scanf(" %d",&at[i]);
	}
	for(i=0;i<n;i++)	// Sorting based on Arrival Time. p,at,bt are sorted in 1D
	
	{
		for(j=0;j<n;j++)
		{
			if(at[i]<at[j])
			{
				temp=p[j];
				p[j]=p[i];
				p[i]=temp;
				temp=at[j];
				at[j]=at[i];
				at[i]=temp;
				temp=bt[j];
				bt[j]=bt[i];
				bt[i]=temp;
			}
		}
	}
 
	for(j=0;j<n;j++)
	{
		btime=btime+bt[j];
		min=bt[k];
		for(i=k;i<n;i++)
		{
			if(btime>=at[i] && bt[i]<min)
			{
				temp=p[k];
				p[k]=p[i];
				p[i]=temp;
				temp=at[k];
				at[k]=at[i];
				at[i]=temp;
				temp=bt[k];
				bt[k]=bt[i];
				bt[i]=temp;
			}
		}
		k++;
	}

	wt[0]=0;
	for(i=1;i<n;i++)
	{
		sum=sum+bt[i-1];
		wt[i]=sum-at[i];
		wsum=wsum+wt[i];
	}
 
	wavg=(wsum/n);
	for(i=0;i<n;i++)
	{
		ta=ta+bt[i];
		tt[i]=ta-at[i];
		tsum=tsum+tt[i];
	}
	compt[0]=1;
	for(int i=1;i<=n;i++)
	{
		compt[i]=compt[i-1]+bt[i-1];
	}
 
	tavg=(tsum/n);
	printf("\nProcess\t Arrival\t Burst\t\t Waiting\t Turnaround" );
	for(i=0;i<n;i++)
	{
		printf("\np%d\t %d\t\t %d\t\t %d\t\t%d",p[i],at[i],bt[i],wt[i],tt[i]);
	}
 
	printf("\nAverage waiting time:%f\n",wavg);
	printf("Average turnaround time:%f\n|",tavg);
	for(i=0;i<n;i++)
	{
		printf("p%d",p[i]);
		for(j=0;j<=bt[i];j++)
		{
			printf(" ");
		}
		printf("|");
	}
	printf("\n");
	for(i=0;i<=n;i++)
	{
		printf("%d  ",compt[i]);
		for(int j=0;j<=bt[i];j++){
			printf(" ");
		}
	}
}
