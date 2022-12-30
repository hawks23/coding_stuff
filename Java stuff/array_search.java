
import java.util.*;



public class array_search {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number of elements in array :");
        int n=sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter Elements of array :\n");
        for(int i=0;i<n;i++)
        {
            int elm=sc.nextInt();
            arr[i]=elm;
        }
        System.out.println("The Array is :\n");
        for(int i=0;i<n;i++)
        {
            System.out.println(arr[i]+"\t");
        }
        System.out.println("Enter element to Search for :\n");
        int ch=sc.nextInt();
        int flag=-1;
        for(int j=0;j<n;j++)
        {
            if(arr[j]==ch)
            {
                flag=1;
                break;
            }
        }
        if (flag==1)
        {
            System.out.println("Element Found");
        }
        else 
        {
            System.out.println("Element not found");
        }
        sc.close();
    }
}
