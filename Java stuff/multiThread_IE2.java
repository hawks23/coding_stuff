
/* Question asked in Internal Examintaion 2
 * Write a program to create two threads and display multiples of 3 and 5
 * separately using multithreading
 */

/*public class multiThread_IE2 implements Runnable
{
    public static void main(String args[]) throws InterruptedException
    {
        multiThread_IE2 MultiThree = new multiThread_IE2();
        Thread t1 = new Thread(MultiThree,"MultiThree");
        //multiThread_IE2 MultiFive = new multiThread_IE2();
        Thread t2 = new Thread(MultiThree,"MultiFive");

        t1.start();
        t1.join();
        t2.start();
        t2.join();
    }

    synchronized public void run()
    {
        String str;
        str = Thread.currentThread().getName();
        if(str=="MultiThree")
        {
            for(int i=0;i<30;i+=3)
            {
                System.out.println(str + " : " + i);
            }
        }

        if(str=="MultiFive")
        {
            for(int i=0;i<30;i+=5)
            {
                System.out.println(str + " : " + i);
            }
        }
    }
    
}*/

// Using Thread Class

class Multitreading extends Thread
{
    public static void main(String args[])
    {
        Multitreading m1 = new Multitreading();
        Multitreading m2 = new Multitreading();
        m1.setName("MultiThree");
        m2.setName("MultiFive");
        m1.start();
        m2.start();
    }

    synchronized public void run()
    {
        String st = Thread.currentThread().getName();
        if(st.equals("MultiThree"))
        {
            for(int i=0;i<30;i+=3)
            {
                System.out.println(st +" : " + i);
            }
        }
        if(st.equals("MultiThree"))
        {
            for(int i=0;i<30;i+=5)
            {
                System.out.println(st +" : " + i);
            }
        }
    }
}