package com.anshul.practical12;

public class Student {
    int rollno;
    String name, email, gender, course;

    public Student(int rollno, String name, String email, String gender, String course) {
        this.rollno = rollno;
        this.name = name;
        this.email = email;
        this.gender = gender;
        this.course = course;
    }

    public int getRollNo() {
        return rollno;
    }

    public String getName() {
        return name;
    }

    public String getEmail() {
        return email;
    }

    public String getGender() {
        return gender;
    }

    public String getCourse() {
        return course;
    }
}
