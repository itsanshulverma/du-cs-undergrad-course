import java.awt.*;
import java.awt.event.*;

public class CGPA extends Frame implements ActionListener {
    Label lCGPA;
    Button btnClose;

    CGPA() {
        super("CGPA");
        lCGPA = new Label("Previous Semester CGPA : 8.32");
        lCGPA.setBounds(50, 50, 300, 50);
        btnClose = new Button("Close");
        btnClose.setBounds(100, 150, 200, 50);
        btnClose.addActionListener(this);
        this.add(lCGPA);
        this.add(btnClose);
        this.setSize(400, 250);
        this.setLayout(null);
        this.setVisible(true);
        this.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                dispose();
            }
        });
    }

    public void actionPerformed(ActionEvent e) {
        dispose();
    }
}