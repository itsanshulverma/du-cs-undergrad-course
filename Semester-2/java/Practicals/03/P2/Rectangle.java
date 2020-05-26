package P2;

import P1.Shape;
import java.io.*;

public class Rectangle extends Shape {
    private double l, b;

    public void get() throws java.io.IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("\nEnter the length of Rectangle : ");
        l = Double.parseDouble(br.readLine());
        System.out.print("Enter the beadth of Rectangle : ");
        b = Double.parseDouble(br.readLine());
    }

    public double area() throws java.io.IOException {
        get();
        return l * b;
    }
}