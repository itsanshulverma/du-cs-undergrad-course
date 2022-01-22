import java.awt.*;
import java.awt.event.*;

public class DemoAWT3 extends Frame implements ActionListener {
    Button btnRed, btnBlue;

    DemoAWT3() {
        super("AWT Demo 3");
        btnRed = new Button("Red");
        btnRed.setBounds(50, 100, 300, 50);
        btnRed.addActionListener(this);
        btnBlue = new Button("Blue");
        btnBlue.setBounds(50, 200, 300, 50);
        btnBlue.addActionListener(this);
        this.add(btnRed);
        this.add(btnBlue);
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
        if (e.getSource() == btnBlue) {
            this.setBackground(Color.BLUE);
        }
        if (e.getSource() == btnRed) {
            this.setBackground(Color.RED);
        }
    }

    public static void main(String[] args) {
        new DemoAWT3();
    }
}