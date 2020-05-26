import java.awt.*;
import java.awt.event.*;

public class DemoAWT4 extends Frame {
    Label l1, l2, l3;

    DemoAWT4() {
        super("AWT Demo 3");
        l1 = new Label();
        l1.setBounds(50, 50, 300, 50);
        l1.setAlignment(Label.CENTER);
        l2 = new Label();
        l2.setBounds(50, 100, 300, 50);
        l2.setAlignment(Label.CENTER);
        l3 = new Label();
        l3.setBounds(50, 150, 300, 50);
        l3.setAlignment(Label.CENTER);
        this.add(l1);
        this.add(l2);
        this.add(l3);
        this.setSize(400, 250);
        this.setLayout(null);
        this.setVisible(true);
        this.addKeyListener(new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                l1.setText("Typed Character is : " + e.getKeyChar());
            }

            @Override
            public void keyPressed(KeyEvent e) {
                l2.setText("Pressed Character is : " + e.getKeyChar());
            }

            @Override
            public void keyReleased(KeyEvent e) {
                l2.setText("No Key is pressed");
                l3.setText("Released Character is : " + e.getKeyChar());
            }
        });
        this.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                dispose();
            }
        });
    }

    public static void main(String[] args) {
        new DemoAWT4();
    }
}