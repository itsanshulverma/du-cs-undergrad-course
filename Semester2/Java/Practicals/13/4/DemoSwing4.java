import javax.swing.*;
import java.awt.event.*;

public class DemoSwing4 {
    JLabel jl1, jl2, jl3;

    DemoSwing4() {
        JFrame jFrame = new JFrame("Demo Swing 4");
        jl1 = new JLabel("", JLabel.CENTER);
        jl1.setBounds(50, 50, 300, 50);
        jl2 = new JLabel("", JLabel.CENTER);
        jl2.setBounds(50, 100, 300, 50);
        jl3 = new JLabel("", JLabel.CENTER);
        jl3.setBounds(50, 150, 300, 50);
        jFrame.add(jl1);
        jFrame.add(jl2);
        jFrame.add(jl3);
        jFrame.setSize(400, 250);
        jFrame.setLayout(null);
        jFrame.setVisible(true);

        jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jFrame.addKeyListener(new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                jl1.setText("Typed Character is : " + e.getKeyChar());
            }

            @Override
            public void keyPressed(KeyEvent e) {
                jl2.setText("Pressed Character is : " + e.getKeyChar());
            }

            @Override
            public void keyReleased(KeyEvent e) {
                jl2.setText("No Key is pressed");
                jl3.setText("Released Character is : " + e.getKeyChar());
            }
        });
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new DemoSwing4();
            }
        });
    }
}
