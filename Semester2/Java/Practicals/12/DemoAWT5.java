import java.awt.*;
import java.awt.event.*;

public class DemoAWT5 extends Frame implements ActionListener {
    Button btnA, btnB;

    DemoAWT5() {
        super("AWT Demo 5");
        btnA = new Button("A");
        btnA.setBounds(50, 100, 300, 50);
        btnA.addActionListener(this);
        btnB = new Button("B");
        btnB.setBounds(50, 200, 300, 50);
        btnB.addActionListener(this);
        this.add(btnA);
        this.add(btnB);
        this.setSize(400, 350);
        this.setLayout(null);
        this.setVisible(true);
        this.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                dispose();
            }
        });
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == btnA) {
            new Info();
        }
        if (e.getSource() == btnB) {
            new CGPA();
        }
    }

    public static void main(String[] args) {
        new DemoAWT5();
    }
}