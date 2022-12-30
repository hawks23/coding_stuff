import java.io.*;
import java.io.IOException;
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
import java.util.Scanner;

class myContent
{
    public static void main(String args[]) 
    {
        File f1 = new File("File1.txt");
        Scanner sc = new Scanner(System.in);
        String toWrite = sc.nextLine();
        // Writing into file using Byte Stream Classes
        FileOutputStream fos = FileOutputStream("File1.txt");
        byte[] bytesArray = toWrite.getBytes();
        fos.write(bytesArray);
        fos.flush();
        fos.close();
        // Reading from file using Byte Stream Classes
        FileInputStream fis = FileInputStream("File1.txt");
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
        f2r.close();
    }
}