import java.io.*;
import P1.Shape;
import P2.Rectangle;
import P3.Circle;

public class Main {
    public static void main(String[] args) throws java.io.IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("\nSelect a Shape : 1) Rectangle, 2) Circle");
        System.out.print("1 or 2 ? : ");
        Shape shape;
        switch (Integer.parseInt(br.readLine())) {
            case 1:
                shape = new Rectangle();
                System.out.println("\n> Area : " + shape.area() + " sq. units");
                break;
            case 2:
                shape = new Circle();
                System.out.println("\n> Area : " + shape.area() + " sq. units");
                break;
            default:
                System.out.println("\nInvalid Choice!");
                break;
        }
    }
}