import javax.swing.*;
import java.awt.Color;
import java.awt.event.*;

public class DemoSwing3 implements ActionListener {

    JFrame jFrame;
    JButton jbtnRed, jbtnBlue;

    DemoSwing3() {
        jFrame = new JFrame("Swing Demo 3");
        jbtnRed = new JButton("Red");
        jbtnRed.setBounds(50, 100, 300, 50);
        jbtnRed.addActionListener(this);
        jbtnBlue = new JButton("Blue");
        jbtnBlue.setBounds(50, 200, 300, 50);
        jbtnBlue.addActionListener(this);
        jFrame.add(jbtnRed);
        jFrame.add(jbtnBlue);
        jFrame.setSize(400, 350);
        jFrame.setLayout(null);
        jFrame.setVisible(true);
        jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == jbtnBlue) {
            jFrame.getContentPane().setBackground(Color.BLUE);
        }
        if (e.getSource() == jbtnRed) {
            jFrame.getContentPane().setBackground(Color.RED);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new DemoSwing3();
            }
        });
    }
}