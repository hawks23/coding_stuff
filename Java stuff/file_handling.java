import java.io.*;
import java.io.IOException;
import java.util.Scanner;
/*class MyInput
{
    public static void main(String[] args) throws IOException
    {
        File f1 = new File("text.txt");
        try{
            if(f1.createNewFile())
            {
                System.out.println("File text.txt created");
            }
            else
            {
                 System.out.println("File Already Exists !");
            }
        }
        catch(IOException ie)
        {
            System.out.println("Error has occured");
        }*/
        /*Writing using Byte Stream */
        /*String toBeWritten = "Hi ! This is Flume";
        FileOutputStream fos = new FileOutputStream(f1);
        byte[] bytesArray = toBeWritten.getBytes();
        fos.write(bytesArray);
        fos.close();*/
        /*Reading using Byte Stream */
        /*FileInputStream fis = new FileInputStream(f1);
        int i;
        while((i=fis.read())!=-1)
        {
            System.out.print((char)i);
        }
        fis.close();
    }
}*/

/* 
class myContent
{
    public static void main(String args[]) throws IOException
    {
        File f1 = new File("File1.txt");
        if(f1.createNewFile())
        {
            System.out.println("Created\n");
        }
        Scanner sc = new Scanner(System.in);
        String toWrite = sc.nextLine();
        // Writing into file using Byte Stream Classes
        FileOutputStream fos = new FileOutputStream(f1);
        byte[] bytesArray = toWrite.getBytes();
        fos.write(bytesArray);
        fos.flush();
        fos.close();
        // Reading from file using Byte Stream Classes
        FileInputStream fis = new FileInputStream(f1);
        int i;
        while((i = fis.read()) != -1)
        {
            System.out.println((char)i);
        }
        fis.close();
        
        // Writing into file using Character Stream Classes
        FileWriter f2 = new FileWriter("File1.txt");
        f2.write(toWrite);
        f2.flush();
        f2.close();

        // Reading from file using Character Stream Classes
        FileReader f2r = new FileReader(f1);
        char[] myContent = new char[100];
        f2r.read(myContent);
        System.out.println(String.valueOf(myContent));
        f2r.close();
    }
}*/

class myContent
{
    public static void main(String[] args) throws IOException
    {
        File f1 = new File("Hello1.txt");
        File f2 = new File("Hello2.txt");
        if(f1.createNewFile())
        {
            System.out.println("File created");
        }
        else
        {
            System.out.println("File already exists");
        }

        FileOutputStream fos = new FileOutputStream(f1);
        String st = "Hello World";
        byte[] bytesArray = st.getBytes();
        fos.write(bytesArray);
        System.out.println("Content Written !");

        System.out.println("The content is : ");
        FileInputStream fis = new FileInputStream(f1);
        int i;
        while((i=fis.read())!=-1)
        {
            System.out.print((char)i);
        }

        if(f2.createNewFile())
        {
            System.out.println("File created");
        }
        else
        {
            System.out.println("File already exists");
        }
        FileInputStream fis2 = new FileInputStream(f1);
        FileOutputStream fos2 = new FileOutputStream(f2);
        String st2 = "";
        byte[] bytesArray2;
        while((i=fis2.read())!=-1)
        {
            st2+=(char)i;
        }
        bytesArray2 = st2.getBytes();
        fos2.write(bytesArray2);
        fis2.close();
        fos2.close();
        fos.close();
        fis.close();
    }
}