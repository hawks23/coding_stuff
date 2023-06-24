#include <stdio.h>

void WorstFit(int bs[], int b, int ps[], int p)
{
    int alloc[p], occup[b];
    for(int i = 0; i < p; i++){
        alloc[i] = -1;
    }
    for (int i=0; i < p; i++){
        int index = -1;
        for (int j=0; j < b; j++) { 
            if (bs[j] >= ps[i]){
                if (index == -1)
                    index = j;
                else if (bs[j] > bs[index])
                    index = j;
            }
        }
        if (index != -1){
            alloc[i] = index;
            occup[i] = 1;
            bs[index] -= ps[i];
        }
    }
 
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < p; i++){
        printf("%d \t\t\t %d \t\t\t", i+1, ps[i]);
        if (alloc[i] != -1)
            printf("%d\n",alloc[i]+1);
        else
            printf("Not Allocated\n");
    }
}
void main(){
	int b, p;
	int ps[10], bs[10];
    	printf("Enter Number of Blocks:");
	scanf("%d",&b);
	printf("Enter Block Size:\n");
	for(int i=0; i<b; i++){
		scanf("%d",&bs[i]);
	}
    	printf("Enter Number of Processes:");
	scanf("%d",&p);
	printf("Enter Process Size:\n");
	for(int i=0; i<p; i++){
		scanf("%d",&ps[i]);
	}
  	WorstFit(bs, b, ps, p);

}
