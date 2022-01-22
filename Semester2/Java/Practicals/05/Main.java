import java.util.Random;

public class Main {
    public static void main(String[] args) {
        int r;
        Stack s = new Stack(5);
        Random random = new Random(1242);
        System.out.println("\nCreated a stack : " + s.toString());
        System.out.println("Pushing into stack...");

        while (true) {
            r = random.nextInt(100);
            System.out.println("Pushing " + r + " into stack");
            try {
                s.push(r);
                System.out.println("Elements in stack : " + s.tos() + 1);
            } catch (StackException e) {
                System.err.println(e.getMessage());
                break;
            }
        }

        System.out.println("Popping from stack...");
        while (true) {
            r = random.nextInt(100);
            System.out.println("Pushing " + r + " into stack");
            try {
                System.out.println("Popped " + s.pop() + " from stack");
            } catch (StackException e) {
                System.err.println(e.getMessage());
                break;
            }
        }
    }
}