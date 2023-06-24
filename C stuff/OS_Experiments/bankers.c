#include <stdio.h>  
int main()  
{  
    int n, m, i, j, k;
    
    //reading number of processes and resource types
    
    printf("Enter Number of Processes and Resource Types:");
    scanf("%d%d", &n,&m);
    int alloc[n][m], max[n][m], avail[m];
    printf("Enter Allocation List:");
    for(int i=0; i<n; i++){
    	for(int j=0; j<m; j++){
    		scanf("%d", &alloc[i][j]);
    	}
    }
    printf("Enter Max List:");
    for(int i=0; i<n; i++){
    	for(int j=0; j<m; j++){
    		scanf("%d", &max[i][j]);
    	}
    }
    printf("Enter Available List:");
    for(int i=0; i<m; i++){
    	scanf("%d", &avail[i]);
    }
    
    //starting banker's algorithm
    
    int f[n], ans[n], ind = 0;  
    for (k = 0; k < n; k++)
    {  
        f[k] = 0;  // Flag to check whether process allocated or not
    }  
    int need[n][m];  
    for (i = 0; i < n; i++){  
        for (j = 0; j < m; j++)  
            need[i][j] = max[i][j] - alloc[i][j];  
    }  
    int y = 0;  
    for (k = 0; k < 5; k++){  
        for (i = 0; i < n; i++)
        {  
            if (f[i] == 0)
            {  
                int flag = 0;  
                for (j = 0; j < m; j++)
                {  
                    if (need[i][j] > avail[j])
                    {  
                        flag = 1;  // Cannot allocate
                        break;  
                    }  
                }  
                if (flag == 0)
                {  
                    ans[ind++] = i;  // Adding to safe sequence
                    for (y = 0; y < m; y++)  
                        avail[y] += alloc[i][y];  
                    f[i] = 1;  
                }  
            }  
        }  
    }  
    int flag = 1;  
    for (int i = 0; i < n; i++)
    {  
        if (f[i] == 0)
        {  
            flag = 0;  
            printf("The following system is not safe");  
            break;  
        }  
    }  
    if (flag == 1){  
        printf("Following is the SAFE Sequence\n");  
        for (i = 0; i < n - 1; i++)  
            printf(" P%d ->", ans[i]);  
        printf(" P%d", ans[n - 1]);  
    } 
    printf("\n");
    return (0);  
}  
