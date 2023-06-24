#include<stdio.h>
int n;
int temp[100];

void main()
{
    printf("Enter length of array :");
    scanf("%d",&n);
    int array[n];
    printf("\nEnter elements of array :\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    printf("The array is :\n");
    for(int i=0;i<n;i++)
    {
        printf("%d",array[i]);
    }
    int ch;
    while(1)
    {
        printf("\n\n1. Selection sort\n2. Insertion sort\n3. Merge sort\n4. Heap sort\n5. Quick sort\n");
        printf("\nEnter choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                SelectionSort(array,n);
                break;
            case 2:
                InsertionSort(array,n);
                break;
            case 3:
                MergeSort(array,0,n-1);
                for(int i=0;i<n;i++)
                    printf("%d",a[i]);
                break;
        }
    }
}

void SelectionSort(int a[],int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("\nThe array is :\n");
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}

void InsertionSort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        temp = a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }

    printf("\nThe array is :\n");
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}

void MergeSort(int array[],int l,int h)
{
    if(l<h)
    {
        int mid = (l+h)/2;
        MergeSort(array,l,mid);
        MergeSort(array,mid+1,h);
        merge(array,l,mid,h);
    }
}

void merge(int a[], int l, int mid, int h)
{
    int i=l,j=mid+1,k=l;
    while(i<=mid && j<=h)
    {
        if(a[i]<a[j])
        {
            temp[k]=a[i];
            k++;
            i++;
        }
        else
        {
            temp[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        temp[k]=a[i];
        k++;
        i++;
    }
    while(j<=h)
    {
        temp[k]=a[j];
        k++;
        j++;
    }
    for(int i=l;i<=h;i++)
    {
        a[i]=temp[i];
    }
}