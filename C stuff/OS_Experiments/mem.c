#include<stdio.h>
int s;
void bestFit(int block[], int block1[], int m, int process[], int n)
{
	int i, j;
	int al[n];
	for(i=0;i<n;i++){
		al[i] = -1;	// To vhevk whether allocated or not
	}
	for (i=0;i<n;i++){
		int best=-1;
		for (int j=0;j<m;j++)
		{
			if (block[j] >= process[i])
			{
				if(best==-1){
					best=j;
				}
				else if(block[best]>block[j]){
					best=j;
				}
			}

		}
		if (best!=-1)
		{
			al[i]=best;
			block[best]-=process[i];
		}
	}
	printf("\nSno\t\tProcess Size\t\tBlock\t\tTotal Space\t\tWastage Space\n");
	for (int i = 0; i < n; i++)
	{
		printf(" %d\t\t", i+1);
		printf("%d\t\t\t", process[i]);
		if (al[i] != -1){
			printf("%d\t\t", al[i] + 1);
			printf("%d\t\t\t", block1[al[i]]);
			printf("%d\t\t", block[al[i]]);
		}
		else{
			printf("Not Allocated\t\t");
		}		
		printf("\n");
	}
}

void worstFit(int block[], int block1[], int m, int process[], int n)
{
	int i, j;
	int al[n];
	for(i=0;i<n;i++){
		al[i] = -1;
	}

	for (i=0;i<n;i++){
		int worst=-1;
		for (int j=0;j<m;j++)
		{
			if (block[j] >= process[i])
			{
				if(worst==-1){
					worst=j;
				}
				else if(block[worst]<block[j]){
					worst=j;
				}
			}

		}
		if (worst!=-1)
		{
			al[i]=worst;
			block[worst]-=process[i];
		}
	}
	printf("\nSno\t\tProcess Size\t\tBlock\t\tTotal Space\t\tWastage Space\n");
	for (int i = 0; i < n; i++)
	{
		printf(" %d\t\t", i+1);
		printf("%d\t\t\t", process[i]);
		if (al[i] != -1){
			printf("%d\t\t", al[i] + 1);
			printf("%d\t\t\t", block1[al[i]]);
			printf("%d\t\t", block[al[i]]);
		}
		else{
			printf("Not Allocated\t\t");
		}		
		printf("\n");
	}
}


void firstFit(int block[], int block1[], int m, int process[], int n)
{
	int i, j;
	int al[n];
	for(i=0;i<n;i++){
		al[i] = -1;
	}
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			if (block[j]>=process[i]){
				al[i] = j;
				block[j] -= process[i];
				break;
			}
		}
	}
	printf("\nSno\t\tProcess Size\t\tBlock\t\tTotal Space\t\tWastage Space\n");
	for (int i = 0; i < n; i++)
	{
		printf(" %d\t\t", i+1);
		printf("%d\t\t\t", process[i]);
		if (al[i] != -1){
			printf("%d\t\t", al[i] + 1);
			printf("%d\t\t\t", block1[i]);
			printf("%d\t\t", block[i]);
		}
		else{
			printf("Not Allocated\t\t");
		}		
		printf("\n");
	}
}

void main()
{
	int m;int block[100];int block1[100];int block2[100];int block3[100];int process[100];
	int n;
	printf("Enter number of process\n");
	scanf("%d",&n);
	printf("Enter number of memory block\n");
	scanf("%d",&m);
	for(int i=0;i<n;i++){
		printf("Enter process size:");	
		scanf("%d",&process[i]);
	}
	for(int i=0;i<m;i++){
		printf("Enter block size:");	
		scanf("%d",&block[i]);
		block1[i]=block[i];
		block2[i]=block[i];
		block3[i]=block[i];
	}
	printf("\n\nFirstfit\n\n");
	firstFit(block1,block, m, process, n);
	printf("\n\nBestfit\n\n");
	bestFit(block2,block, m, process, n);
	printf("\n\nWorstfit\n\n");
	worstFit(block3,block, m, process, n);
}
	
