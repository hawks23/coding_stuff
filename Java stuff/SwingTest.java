// Swing Test
import javax.swing.*;

class SwingTest
{
    public static void main(String args[]) 
    {
        JFrame f = new JFrame("Frame 1");
        JLabel j1 = new JLabel("Username :");
        j1.setBounds(50,50,100,30);
        JButton jb1 = new JButton("Click Here !");
        jb1.setBounds(50,100,100,30);
        f.add(jb1);
        f.add(j1);
        f.setSize(500,500);
        f.setLayout(null);
        f.setVisible(true);
    }
}