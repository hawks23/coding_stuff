import java.util.*;
import java.util.Scanner;
class vectors extends functions
{
    public static void main(String args[])
    {
        Vector<Integer> v1 = new Vector<>();
        while(true)
        {
            System.out.println("\n1. Add Element\n2. Delete Element\n3. Replace Element\n4. Display Vecto\n5. Exit");
            switch(sc.nextInt())
            {
                case 1:
                    addElement(v1);
                    break;
                case 2:
                    deleteElement(v1);
                    break;
                case 3:
                    replaceElement(v1);
                    break;
                case 4:
                    display(v1);
                    break;
                case 5:
                    return;
            }
        }
    }
}

class functions
{
    static Scanner sc = new Scanner(System.in);
    static void addElement(Vector v)
    {
        v.add(sc.nextInt());
    }
    static void deleteElement(Vector v)
    {
        v.remove(sc.nextInt());
    }
    static void replaceElement(Vector v)
    {
        System.out.println("Enter element to replace :");
        int x = sc.nextInt();
        if(v.contains(x))
        {
            v.set(v.indexOf(x),sc.nextInt());
        }
        else
        {
            System.out.println("Element not found");
        }
    }
    static void display(Vector v)
    {
        System.out.println("The Vector is "+ v);
    }
}
