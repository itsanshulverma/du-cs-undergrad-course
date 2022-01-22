public class ComplexNumber{

    double x, y;

    // Constructor
    ComplexNumber(){
        this.x = 0;
        this.y = 0;
    }
    ComplexNumber(double r, double i){
        this.x = r;
        this.y = i;
    }

    // Addition of two complex numbers
    public static ComplexNumber add(ComplexNumber a, ComplexNumber b) {
        ComplexNumber n = new ComplexNumber();
        n.x = a.x + b.x;
        n.y = a.y + b.y;

        return n;
    }

    // Multiplication of two complex numbers
    public static ComplexNumber multiply(ComplexNumber a, ComplexNumber b) {
        ComplexNumber n = new ComplexNumber();
        n.x = (a.x*b.x) - (a.y*b.y);
        n.y = (a.x*b.y) + (a.y*b.x);

        return n;
    }

    // Display method
    public String toString() {
        return ("( " + this.x + " + " + this.y + "i )");
    }

    // Main method
    public static void main(String[] args) {
        ComplexNumber n1 = new ComplexNumber(1,1);
        ComplexNumber n2 = new ComplexNumber(1,1);
        System.out.println("\n Adding two numbers...\n");
        ComplexNumber addN = add(n1,n2);
        System.out.println(n1.toString() + " + " + n2.toString() + " = " + addN.toString());
        System.out.println("\n Multiplying two numbers...\n");
        ComplexNumber mulN = multiply(n1,n2);
        System.out.println(n1.toString() + " * " + n2.toString() + " = " + mulN.toString());
    }
}