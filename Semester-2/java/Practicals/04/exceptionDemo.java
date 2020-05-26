import java.util.Scanner;

public class exceptionDemo {

    public static void test(int age) throws UnderAgeException {
        if (age < 18)
            throw new UnderAgeException(age);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter the age : ");
        int age = sc.nextInt();
        try {
            test(age);
            System.out.println(">> Test Sucessful");
        } catch (UnderAgeException e) {
            System.err.println(e.getMessage());
            System.out.println(">> Test Unsucessful");
        } finally {
            sc.close();
        }
    }
}