import java.awt.*;
import java.awt.event.*;

public class DemoAWT2 extends Frame {
    Label l;

    DemoAWT2() {
        super("AWT Demo 2");
        l = new Label("This is a string.");
        l.setBounds(100, 50, 100, 25);
        l.setAlignment(Label.CENTER);
        this.add(l);
        this.setSize(300, 125);
        this.setBackground(Color.PINK);
        this.setVisible(true);
        this.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                dispose();
            }
        });
    }

    public static void main(String[] args) {
        new DemoAWT2();
    }
}