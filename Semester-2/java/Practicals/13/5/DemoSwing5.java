import javax.swing.*;
import java.awt.event.*;

public class DemoSwing5 implements ActionListener {
    JButton jbtnA, jbtnB;

    DemoSwing5() {
        JFrame jFrame = new JFrame("Swing Demo 1");
        JPanel jPanel = new JPanel();
        jbtnA = new JButton("A");
        jbtnA.setBounds(50, 50, 300, 50);
        jbtnA.addActionListener(this);
        jbtnB = new JButton("B");
        jbtnB.setBounds(50, 150, 300, 50);
        jbtnB.addActionListener(this);
        jPanel.add(jbtnA);
        jPanel.add(jbtnB);
        jPanel.setLayout(null);
        jFrame.add(jPanel);
        jFrame.setSize(400, 300);
        jFrame.setVisible(true);
        jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == jbtnA) {
            new Info();
        }
        if (e.getSource() == jbtnB) {
            new CGPA();
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new DemoSwing5();
            }
        });
    }
}