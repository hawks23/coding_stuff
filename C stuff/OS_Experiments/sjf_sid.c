#include <stdio.h>

void gantt_chart(int b[], int t[], int n){
    int i, j;
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<b[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n|");
    for(i=0; i<n; i++) {
        for(j=0; j<b[i] - 1; j++) printf(" ");
        printf("P%d", i);
        for(j=0; j<b[i] - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    for(i=0; i<n; i++) {
        for(j=0; j<b[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n");

    printf("0");
    for(i=0; i<n; i++) {
        for(j=0; j<b[i]; j++) printf("  ");
        if(t[i] > 9) printf("\b");
        printf("%d", t[i]);
 
    }
    printf("\n");
}

void main(){
	int n, min;
	printf("Enter Number of Processes:");
	scanf("%d", &n);
	int p[10], a[10], b[10], c[10], turn[10], wait[10];
	int avgt=0, avgw=0, temp;
	for(int i=0; i<n; i++){
		p[i] = i+1;
		printf("Enter Arrival Time and Burst Time of P%d: ", i+1);
		scanf("%d%d", &a[i], &b[i]);
	}
	for(int i=0; i<n; i++){
		min=i;
		for(int j=i+1; j<=n; j++){
			if(b[j]<b[min]){
				min=j;
			}
		}
		temp = b[i];
		b[i] = b[min];
		b[min] = temp;
		
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
		
		temp = p[i];
		p[i] = p[min];
		p[min] = temp;
	}
	c[0] = a[0]+b[0];
	for(int i=1; i<n; i++){
		c[i] = c[i-1] + b[i];
	}
	for(int i=1; i<n; i++){
		turn[i] = c[i] - a[i];
		wait[i] = turn[i] - b[i];
		avgt += turn[i];
		avgw += wait[i];		 
	}
	avgt/=n;
	avgw/=n;
	printf("PID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
	for(int i=0; i<n; i++){
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, a[i], b[i], c[i], turn[i], wait[i]);
	}
	gantt_chart(b, turn, n);
	printf("Average Turnaround Time = %d\n", avgt);
	printf("Average Waiting Time = %d\n", avgw);
}
