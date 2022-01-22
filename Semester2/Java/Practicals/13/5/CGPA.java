import javax.swing.*;
import java.awt.event.*;

public class CGPA {

    CGPA() {
        JFrame jFrame = new JFrame("CGPA");
        JLabel jlCGPA = new JLabel("Previous Semester CGPA : 8.32");
        jlCGPA.setBounds(50, 25, 300, 50);
        JButton jbtnClose = new JButton("Close");
        jbtnClose.setBounds(100, 125, 200, 50);
        jbtnClose.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                jFrame.dispose();
            }
        });
        jFrame.add(jlCGPA);
        jFrame.add(jbtnClose);
        jFrame.setSize(400, 250);
        jFrame.setLayout(null);
        jFrame.setVisible(true);
        jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}