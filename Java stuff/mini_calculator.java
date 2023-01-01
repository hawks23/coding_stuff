/*import javax.swing.*;
import java.io.IOException;
import java.io.*;

class swingProg
{
    public static void main(String args[]) 
    {
        JFrame f = new JFrame("Frame1");
        JTextField t1 = new JTextField(0);
        JTextField t2 = new JTextField(0);
        JTextField t3 = new JTextField(0);

        JButton plusButton = new JButton("+");
        JButton minusButton = new JButton("-");
        t1.setBounds(100,100,100,30);
        t2.setBounds(250,100,100,30);
        t3.setBounds(400,100,100,30);
        t1.setEditable(true);
        t2.setEditable(true);
        t3.setEditable(false);

        plusButton.setBounds(175,200,70,70);
        minusButton.setBounds(250,200,70,70);

        f.add(t1);
        f.add(t2);
        f.add(t3);
        f.add(plusButton);
        f.add(minusButton);
        
        f.setSize(500,500);
        f.setVisible(true);
        f.setLayout(null);
    }
}
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class SwingExample
{
  public static void main(String[] args) {
    // Create a new JFrame container
    JFrame frame = new JFrame("Swing Example");

    // Set the layout manager to flow layout
    frame.setLayout(new FlowLayout());

    // Create three text fields with initial text "0"
    JTextField T1 = new JTextField("0", 5);
    JTextField T2 = new JTextField("0", 5);
    JTextField T3 = new JTextField("0", 5);

    // Create two buttons with labels "+" and "-"
    JButton plusButton = new JButton("+");
    JButton minusButton = new JButton("-");

    // Add action listeners for the buttons
    plusButton.addActionListener(new ActionListener() 
    {
      public void actionPerformed(ActionEvent e) 
      {
        // Parse the text in T1 and T2 as integers and add them
        int result = Integer.parseInt(T1.getText()) + Integer.parseInt(T2.getText());
        // Set the text of T3 to the result
        T3.setText(Integer.toString(result));
      }
    });
    minusButton.addActionListener(new ActionListener() 
    {
      public void actionPerformed(ActionEvent e)
      {
        // Parse the text in T1 and T2 as integers and subtract them
        int result = Integer.parseInt(T1.getText()) - Integer.parseInt(T2.getText());
        // Set the text of T3 to the result
        T3.setText(Integer.toString(result));
      }
    });

    // Add the text fields and buttons to the frame
    frame.add(T1);
    frame.add(T2);
    frame.add(plusButton);
    frame.add(minusButton);
    frame.add(T3);

    // Set the size of the frame and make it visible
    frame.setSize(500, 500);
    frame.setVisible(true);
  }
}
