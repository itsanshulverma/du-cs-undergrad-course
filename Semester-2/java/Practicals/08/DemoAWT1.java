import java.awt.*;
import java.awt.event.*;

public class DemoAWT1 {

    public static void main(String[] args) {
        int width = 300, height = 150;
        Frame fr = new Frame("AWT Demo 1");
        Label l1 = new Label();
        Label l2 = new Label(width + "x" + height);
        l1.setBounds(50, 50, 100, 25);
        l2.setBounds(50, 75, 100, 25);
        l1.setAlignment(Label.CENTER);
        l2.setAlignment(Label.CENTER);
        fr.add(l1);
        fr.add(l2);
        fr.setSize(width, height);
        fr.setLayout(null);
        fr.setVisible(true);
        fr.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                fr.dispose();
            }
        });

        fr.addMouseListener(new MouseListener() {
            public void mousePressed(MouseEvent e) {
            }

            public void mouseReleased(MouseEvent e) {
            }

            public void mouseExited(MouseEvent e) {
                l1.setText("Mouse Exited");
                l2.setText(fr.getWidth() + "x" + fr.getHeight());
                fr.dispose();
            }

            public void mouseEntered(MouseEvent e) {
                l1.setText("Mouse Entered");
                fr.setSize(fr.getWidth() * 3, fr.getHeight() * 3);
                l2.setText(fr.getWidth() + "x" + fr.getHeight());
            }

            public void mouseClicked(MouseEvent e) {
                l1.setText("Mouse Clicked");
                fr.setSize(width, height);
                l2.setText(fr.getWidth() + "x" + fr.getHeight());
            }
        });
    }
}