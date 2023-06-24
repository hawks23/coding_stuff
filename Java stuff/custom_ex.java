
class custom_exception extends Exception
{
    custom_exception()
    {
        System.out.println("A Cutsom Exception has occured !");
    }
}

public class custom_ex
{
    public static void main(String args[]) 
    {
        int x = 10;
        try
        {
            if(x==10)
            {
                throw new custom_exception();
            }
        }    
        catch (custom_exception ae)
        {

        }
    }
}