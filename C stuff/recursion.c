#include<stdio.h>

void main()
{
    int n;
    printf("Enter a number :");
    scanf("%d",&n);
    int sum = 0;
    sum = rec(n);
    int fact = fac(n);
    printf("The sum is %d\n",sum);
    printf("\nThe factorial is %d\n",fact);
}

int rec(int n)
{
    if(n>0)
    {
        return(n+rec(n-1));
    }
    else
    {
        return 0;
    }
}

int fac(int n)
{
    if (n>0)
    {
        return(n*fac(n-1));
    }
    else
    {
        return 1;   
    }
}