import javax.swing.*;
import java.awt.event.*;
/*
class tiny_calc implements ActionListener
{
    static JFrame f;
    static JTextField t1,t2;
    static JButton b1;

    public static void main(String args[])
    {
        tiny_calc tiny = new tiny_calc();
        f = new JFrame("Example1");
        t1 = new JTextField(null);
        t2 = new JTextField(null);
        b1 = new JButton("+");
        t1.setBounds(100,100,100,30);
        t2.setBounds(150,100,100,30);
        b1.setBounds(125,150,100,30);
        f.add(t1);
        f.add(t2);
        f.add(b1);
        
        f.setLayout(null);
        f.setSize(500,500);
        f.setVisible(true);
        
        
        b1.addActionListener(tiny);
    }

    public void actionPerformed(ActionEvent ae)
    {
        if(ae.getActionCommand()=="+")
        {
            int x = Integer.parseInt(t1.getText());
            int y = Integer.parseInt(t2.getText());
            int sum = (x + y);
            t1.setText(String.valueOf(sum));
        }
    }
}*/

class tiny_calc implements ActionListener
{
    static JTextField t1,t2,t3;
    static JButton plusButton;
    static JFrame f;
    
    public static void main(String args[])
    {
        f = new JFrame("Calculator");
        t1 = new JTextField(null);
        t2 = new JTextField(null);
        t3 = new JTextField(null);
        plusButton = new JButton("+");

        t1.setBounds(100,100,100,30);
        t2.setBounds(210,100,100,30);
        t3.setBounds(155,150,100,30);
        plusButton.setBounds(155,200,100,30);
        
        f.add(t1);
        f.add(t2);
        f.add(t3);
        f.add(plusButton);

        f.setLayout(null);
        f.setSize(500,500);
        f.setVisible(true);

        tiny_calc obj = new tiny_calc();
        plusButton.addActionListener(obj);
    }

    public void actionPerformed(ActionEvent ae)
    {
        if((ae.getActionCommand()).equals("+"))
        {
            t3.setText(String.valueOf((Integer.parseInt(t1.getText()) + Integer.parseInt(t2.getText()))));
        }
    }
}