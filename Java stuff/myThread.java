
/*class myThread extends Thread
{
    public void run()
    {
        for(int i=0;i<10;i++)
        {
            System.out.println(i);
        }
    }

    public static void main(String args[])
    {
        myThread m1 = new myThread();
        myThread m2 = new myThread();

        m1.start();
        m2.start();    
    }
}*/

class myThread implements Runnable
{
    public void run()
    {
        for(int i=0;i<10;i++)
        {
            System.out.println(String.valueOf(i) + " " + Thread.currentThread());
        }
    }

    public static void main(String args[]) throws InterruptedException
    {
        myThread m1 = new myThread();
        Thread t1 = new Thread(m1,"Thread : 1");
        myThread m2 = new myThread();
        Thread t2 = new Thread(m2, "Thread : 2");

        t1.start();
        t2.start();    
    }
}