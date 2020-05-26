import java.awt.*;
import java.awt.event.*;

public class Info extends Frame implements ActionListener {
    Panel pnl;
    Label lName, lCourse, lRollNo, lCollege;
    Button btnClose;

    Info() {
        super("Personal Information");
        lName = new Label("Name     :  Anshul Verma");
        lName.setBounds(50, 50, 300, 50);
        lCourse = new Label("Course   :  BSc (Hons) Computer Science");
        lCourse.setBounds(50, 100, 300, 50);
        lRollNo = new Label("Roll No. :  19/78065");
        lRollNo.setBounds(50, 150, 300, 50);
        lCollege = new Label("College  :  ARSD College");
        lCollege.setBounds(50, 200, 300, 50);
        btnClose = new Button("Close");
        btnClose.setBounds(100, 300, 200, 50);
        btnClose.addActionListener(this);
        pnl = new Panel();
        pnl.setLayout(null);
        pnl.add(lName);
        pnl.add(lCourse);
        pnl.add(lRollNo);
        pnl.add(lCollege);
        pnl.add(btnClose);
        this.add(pnl);
        this.setSize(400, 450);
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