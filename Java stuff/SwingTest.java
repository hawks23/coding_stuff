// Designing a bad login page
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class LoginPage
{
    public static void main(String args[]) 
    {
        JFrame f = new JFrame("Frame 1");
        JLabel j1 = new JLabel("Username :");
        JLabel j2 = new JLabel("Password :");
        JTextField t1 = new JTextField(null);
        JPasswordField t2 = new JPasswordField(null);
        JButton jb1 = new JButton("Login");

        j1.setBounds(50,50,100,50);
        j2.setBounds(50,100,100,50);
        t1.setBounds(200,60,100,30);
        t2.setBounds(200,110,100,30);
        jb1.setBounds(100,200,100,30);

        jb1.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent ae)
            {
                System.out.println("Logged in " + t1.getText());
            }
        });

        f.add(jb1);
        f.add(j1);
        f.add(j2);
        f.add(t1);
        f.add(t2);
        f.setSize(500,500);
        f.setLayout(null);
        f.setVisible(true);
    }
}