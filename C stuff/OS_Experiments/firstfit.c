#include <stdio.h>

void main(){
	int np, nb;
	int p[10], b[10];
	printf("Enter Number of Processes:");
	scanf("%d",&np);
	printf("Enter Process Size:\n");
	for(int i=0; i<np; i++){
		scanf("%d",&p[i]);
	}
	int alloc[nb];
	printf("Enter Number of Blocks:");
	scanf("%d",&nb);
	printf("Enter Block Size:\n");
	for(int i=0; i<nb; i++){
		scanf("%d",&b[i]);
	}
	for(int i=0; i<nb; i++){
		alloc[i] = -1;
	}
	for(int i=0; i<np; i++){
		for(int j=0; j<nb; j++){
			if(p[i] <= b[j]){
				alloc[i]=j;
				b[j] -= p[i];
				break;
			}
		}
	}
	printf("\nProcess No.\tProcess Size\tBlock no.\n");
	for (int i = 0; i < nb; i++)
	{
		printf(" %d\t\t\t", i+1);
		printf("%d\t\t\t\t", p[i]);
		if (alloc[i] != -1)
			printf("%d", alloc[i] + 1);
		else
			printf("Not Allocated");
		printf("\n");
	}
}


