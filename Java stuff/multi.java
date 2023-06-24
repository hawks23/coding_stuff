import java.util.Random;

class multi implements Runnable
{
    int x;
    public static void main(String args[]) throws InterruptedException
    {
        multi m1 = new multi();
        Thread t1 = new Thread(m1,"Gen");
        multi m2 = new multi();
        Thread t2 = new Thread(m2,"Odd");
        multi m3 = new multi();
        Thread t3 = new Thread(m3,"Even");    
        
        t1.start();
        t2.start();
        t1.join();
        t3.start();
        t1.join();

    }

    synchronized public void run()
    {
        Random random = new Random();
        if(Thread.currentThread().getName()=="Gen")
        {
            x = random.nextInt(50);
            try
            {
                Thread.sleep(1000);
            }
            catch(InterruptedException e)
            {
                System.out.println(("Error"));
            }
        }

        if(Thread.currentThread().getName()=="Odd")
        {
            int i=0;
            while(i<x)
            {
                System.out.println(i);
                i+=2;
            }
        }
        
        else if(Thread.currentThread().getName()=="Even")
        {
            int i=1;
            while(i<x)
            {
                System.out.println(i);
                i+=2;
            }
        }
    }
}