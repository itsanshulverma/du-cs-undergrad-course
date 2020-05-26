import javax.swing.*;
import java.awt.event.*;

public class Info {

    Info() {
        JFrame jFrame = new JFrame("Personal Information");
        JLabel jlName = new JLabel("Name     :  Anshul Verma");
        jlName.setBounds(50, 50, 300, 50);
        JLabel jlCourse = new JLabel("Course   :  BSc (Hons) Computer Science");
        jlCourse.setBounds(50, 100, 300, 50);
        JLabel jlRollNo = new JLabel("Roll No. :  19/78065");
        jlRollNo.setBounds(50, 150, 300, 50);
        JLabel jlCollege = new JLabel("College  :  ARSD College");
        jlCollege.setBounds(50, 200, 300, 50);
        JButton jbtnClose = new JButton("Close");
        jbtnClose.setBounds(100, 300, 200, 50);
        jbtnClose.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                jFrame.dispose();
            }
        });
        JPanel jPanel = new JPanel();
        jPanel.setLayout(null);
        jPanel.add(jlName);
        jPanel.add(jlCourse);
        jPanel.add(jlRollNo);
        jPanel.add(jlCollege);
        jPanel.add(jbtnClose);
        jFrame.add(jPanel);
        jFrame.setSize(400, 450);
        jFrame.setVisible(true);
        jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}