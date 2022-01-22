import javax.swing.*;
import java.awt.event.*;

public class DemoSwing1 {
    int width = 300, height = 150;
    JLabel jLbl1, jLbl2;

    DemoSwing1() {
        JFrame jFrame = new JFrame("Swing Demo 1");
        jFrame.setLayout(null);
        jFrame.setSize(width, height);
        jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jLbl1 = new JLabel("", JLabel.CENTER);
        jLbl2 = new JLabel(width + "x" + height, JLabel.CENTER);
        jLbl1.setBounds(50, 50, 100, 25);
        jLbl2.setBounds(50, 75, 100, 25);
        jFrame.add(jLbl1);
        jFrame.add(jLbl2);
        jFrame.setVisible(true);

        jFrame.addMouseListener(new MouseListener() {
            public void mousePressed(MouseEvent e) {
            }

            public void mouseReleased(MouseEvent e) {
            }

            public void mouseExited(MouseEvent e) {
                jLbl1.setText("Mouse Exited");
                jLbl2.setText(jFrame.getWidth() + "x" + jFrame.getHeight());
                jFrame.dispose();
            }

            public void mouseEntered(MouseEvent e) {
                jLbl1.setText("Mouse Entered");
                jFrame.setSize(jFrame.getWidth() * 3, jFrame.getHeight() * 3);
                jLbl2.setText(jFrame.getWidth() + "x" + jFrame.getHeight());
            }

            public void mouseClicked(MouseEvent e) {
                jLbl1.setText("Mouse Clicked");
                jFrame.setSize(width, height);
                jLbl2.setText(jFrame.getWidth() + "x" + jFrame.getHeight());
            }
        });
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new DemoSwing1();
            }
        });
    }
}