import java.util.*;

public class std_details{
    public static void main(String[] args) {
        System.out.println("Enter String :");
        Scanner sc = new Scanner(System.in);
        String a = sc.nextLine();
        int n = a.length();
        int c = 0;
        System.out.println("Enter Frequency to find :");
        char l = sc.nextLine().charAt(0);
        for(int i=0;i<n;i++){
            if(a.charAt(i)==l){
                c++;
            }
        }
        System.out.println("The Freq is "+ c);
        sc.close();
    }
}


