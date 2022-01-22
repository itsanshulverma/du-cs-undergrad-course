package P3;

import P1.Shape;
import java.io.*;

public class Circle extends Shape {
    private double r;

    public void get() throws java.io.IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("\nEnter the Radius of circle : ");
        r = Double.parseDouble(br.readLine());
    }

    public double area() throws java.io.IOException {
        get();
        return Math.PI * (r * r);
    }
}