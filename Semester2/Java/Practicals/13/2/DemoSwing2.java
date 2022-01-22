import javax.swing.*;
import java.awt.Color;
import java.awt.event.*;

public class DemoSwing2 {

    DemoSwing2() {
        JFrame jFrame = new JFrame("Swing Demo 2");
        JLabel jLbl = new JLabel("This is a string.", JLabel.CENTER);
        jLbl.setBounds(100, 50, 100, 25);
        jFrame.add(jLbl);
        jFrame.setSize(300, 125);
        jFrame.getContentPane().setBackground(Color.PINK);
        jFrame.setVisible(true);
        jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new DemoSwing2();
            }
        });
    }
}