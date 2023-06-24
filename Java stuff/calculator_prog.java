import javax.swing.*;
import java.awt.event.*;


class calculator implements ActionListener
{
    static String temp1,oper,msg ="";
    static int result;
    static String finalText;
    static JButton clear,num1,num2,num3,num4,num5,num6,num7,num8,num9,num0,add,sub,mult,div,equal;
    static JTextField t1;
    public static void main(String args[])
    {
        calculator calc1 = new calculator();
        JFrame f = new JFrame("Frame_1");
        
        clear = new JButton("CC");
        num1 = new JButton("1");
        num2 = new JButton("2");
        num3 = new JButton("3");
        num4 = new JButton("4");
        num5 = new JButton("5");
        num6 = new JButton("6");
        num7 = new JButton("7");
        num8 = new JButton("8");
        num9 = new JButton("9");
        num0 = new JButton("0");
        add = new JButton("+");
        sub = new JButton("-");
        mult = new JButton("*");
        div = new JButton("/");
        equal = new JButton("=");

        t1 = new JTextField("");
        t1.setBounds(100,90,150,30);
        t1.setText("");
        t1.setEditable(true);

        clear.setBounds(150,450,75,75);
        num1.setBounds(100,120,50,50);
        num2.setBounds(150,120,50,50);
        num3.setBounds(200,120,50,50);
        num4.setBounds(100,170,50,50);
        num5.setBounds(150,170,50,50);
        num6.setBounds(200,170,50,50);
        num7.setBounds(100,220,50,50);
        num8.setBounds(150,220,50,50);
        num9.setBounds(200,220,50,50);
        num0.setBounds(150,270,50,50);
        add.setBounds(75,320,50,50);
        sub.setBounds(125,320,50,50);
        mult.setBounds(175,320,50,50);
        div.setBounds(225,320,50,50);
        equal.setBounds(275,320,50,50);
        clear.setBounds(140,370,75,75);


        f.add(num1);
        f.add(num2);
        f.add(num3);
        f.add(num4);
        f.add(num5);
        f.add(num6);
        f.add(num7);
        f.add(num8);
        f.add(num9);
        f.add(num0);

        f.add(clear);
        f.add(add);
        f.add(sub);
        f.add(mult);
        f.add(div);
        f.add(equal);

        f.add(t1);

        num1.addActionListener(calc1);
        num2.addActionListener(calc1);
        num3.addActionListener(calc1);
        num5.addActionListener(calc1);
        num6.addActionListener(calc1);
        num7.addActionListener(calc1);
        num8.addActionListener(calc1);
        num9.addActionListener(calc1);
        num0.addActionListener(calc1);
        add.addActionListener(calc1);
        sub.addActionListener(calc1);
        mult.addActionListener(calc1);
        div.addActionListener(calc1);
        clear.addActionListener(calc1);
        equal.addActionListener(calc1);
        
        f.setVisible(true);
        f.setSize(500,500);
        f.setLayout(null);
    }

    public void actionPerformed(ActionEvent ae)
    {
        String s = ae.getActionCommand();
        if(s.equals("+")||s.equals("-")||s.equals("*")||s.equals("/"))
        {
            temp1=t1.getText();     // temp1 stores first number
            oper=s;                 // Oper stores the operation
            t1.setText("");      // Clearing to take next input
            msg ="";
        }

        else if(s.equals("CC"))
        {
            t1.setText("");     // Clear button
            msg="";
        }

        else if(s.equals("="))
        {
            if(oper.equals("+"))
            {
                result = Integer.parseInt(temp1) + Integer.parseInt(t1.getText());
            }
            if(oper.equals("-"))
            {
                result = Integer.parseInt(temp1) - Integer.parseInt(t1.getText());
            }
            if(oper.equals("*"))
            {
                result = Integer.parseInt(temp1) * Integer.parseInt(t1.getText());
            }
            if(oper.equals("/"))
            {
                result = Integer.parseInt(temp1) / Integer.parseInt(t1.getText());
            }
            t1.setText(String.valueOf(result));
        }
        else
        {
            msg+=s;
            t1.setText(msg);
        }
    }
}

