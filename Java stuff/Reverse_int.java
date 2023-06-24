class Reverse_int
{
    public static void main(String args[])
    {
        String x = "125";
        String y = "";
        for(int i=x.length()-1;i>-1;i--)
        {
            y = y + x.charAt(i);
        }
        
        System.out.println("The int is " + y);
    }
}