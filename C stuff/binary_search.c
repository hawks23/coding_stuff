#include<stdio.h>
void main()
{
        int len,key;
        printf("Enter length of array :");
        scanf("%d",&len);
        int arr[len];
        printf("Enter elements :\n");
        for(int i=0;i<len;i++)
        {
            scanf("%d",&arr[i]);
        }
        printf("Enter Element to search : ");
        scanf("%d",&key);
        int mid;
        int l=0,h=(len-1);
        int flag =-1;
        while(l<=h)
        {
            mid=((l+h)/2);
            if(key==mid)
            {
                flag=1;
                break;
            }
            else if(key>arr[mid])
            {
                h=(mid-1);
            }
            else if(key<arr[mid])
            {
                l=(mid+1);
            }
        }
        if(flag==1)
        {
            printf("Element found\n");
        }
        else
        {
            printf("Not found\n");
        }
}