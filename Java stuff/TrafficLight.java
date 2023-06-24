
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class trafficLights extends JPanel implements ActionListener
{
    static JRadioButton red,yellow,green;
    static ButtonGroup bg1;
    static Color red_c,yellow_c,green_c;
    static JFrame f;

    public static void main(String args[]) 
    {
        f = new JFrame("Traffic");
        trafficLights tf1 = new trafficLights();
        red = new JRadioButton();
        yellow = new JRadioButton();
        green = new JRadioButton();
        bg1 = new ButtonGroup();

        red.setBounds(30,20,10,10);
        yellow.setBounds(60,20,10,10);
        green.setBounds(90,20,10,10);

        bg1.add(red);
        bg1.add(yellow);
        bg1.add(green);
        f.add(red);
        f.add(yellow);
        f.add(green);

        red.addActionListener(tf1);
        yellow.addActionListener(tf1);
        green.addActionListener(tf1);

        f.setLayout(new FlowLayout());
        f.setSize(600,480);
        f.setVisible(true);
        
        

    }

    public void actionPerformed(ActionEvent ae)
    {
        if((red.isSelected())==true)
        {
            red_c=Color.RED;
            yellow_c=getBackground();
            green_c=getBackground();
        }
        else if((yellow.isSelected())==true)
        {
            System.out.println("selected");
            red_c=getBackground();
            yellow_c=Color.YELLOW;
            green_c=getBackground();
        }
        else if((green.isSelected())==true)
        {
            red_c=getBackground();
            yellow_c=getBackground();
            green_c=Color.ORANGE;
        }
        repaint();
    }

    public void paintComponent(Graphics g)
    { 
        super.paintComponent(g); 
        g.drawOval(50,50,60,60);
        g.drawOval(50,110,60,60);
        g.drawOval(50,170,60,60);
        g.setColor(red_c);
        g.fillOval(50,50,50,50);
        g.setColor(yellow_c);
        g.fillOval(50,110,50,50);
        g.setColor(green_c);
        g.fillOval(50,170,50,50);
        f.repaint();
    }
}
/*
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class TrafficLight extends JFrame implements ActionListener {

    private JRadioButton redButton, yellowButton, greenButton;
    private JPanel lightPanel;

    public TrafficLight() {
        super("Traffic Light");

        // create radio buttons
        redButton = new JRadioButton("Red");
        yellowButton = new JRadioButton("Yellow");
        greenButton = new JRadioButton("Green");

        // create button group and add radio buttons to it
        ButtonGroup buttonGroup = new ButtonGroup();
        buttonGroup.add(redButton);
        buttonGroup.add(yellowButton);
        buttonGroup.add(greenButton);

        // create panel to display traffic light
        lightPanel = new JPanel();
        lightPanel.setPreferredSize(new Dimension(100, 300));

        // add radio buttons and traffic light panel to frame
        Container contentPane = getContentPane();
        contentPane.setLayout(new BorderLayout());
        JPanel buttonPanel = new JPanel();
        buttonPanel.add(redButton);
        buttonPanel.add(yellowButton);
        buttonPanel.add(greenButton);
        contentPane.add(buttonPanel, BorderLayout.NORTH);
        contentPane.add(lightPanel, BorderLayout.CENTER);

        // register action listener for radio buttons
        redButton.addActionListener(this);
        yellowButton.addActionListener(this);
        greenButton.addActionListener(this);

        // set frame properties
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        // determine which radio button was selected
        if (e.getSource() == redButton) {
            drawTrafficLight(Color.RED);
        } else if (e.getSource() == yellowButton) {
            drawTrafficLight(Color.YELLOW);
        } else if (e.getSource() == greenButton) {
            drawTrafficLight(Color.GREEN);
        }
    }

    private void drawTrafficLight(Color color) {
        // clear panel and draw ovals of the specified color
        lightPanel.removeAll();
        lightPanel.setBackground(Color.BLACK);
        lightPanel.setLayout(new GridLayout(3, 1));
        lightPanel.add(new Oval(color));
        lightPanel.add(new Oval(Color.BLACK));
        lightPanel.add(new Oval(Color.BLACK));
        lightPanel.revalidate();
        lightPanel.repaint();
    }

    private class Oval extends JPanel {
        private Color color;

        public Oval(Color color) {
            this.color = color;
        }

        public void paintComponent(Graphics g) {
            super.paintComponent(g);
            g.setColor(color);
            g.fillOval(25, 25, 50, 50);
        }
    }

    public static void main(String[] args) {
        new TrafficLight();
    }

}
*/