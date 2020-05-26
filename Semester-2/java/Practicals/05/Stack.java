public class Stack {
    private int tos;
    private int[] elements;
    private int size;

    Stack(int size) {
        this.tos = -1;
        this.size = size;
        elements = new int[this.size];
    }

    public void push(int e) throws StackException {
        if (tos == size - 1)
            throw new StackException("Stack Overflow : could not push, stack is full");
        else {
            elements[++this.tos] = e;
            System.out.println(e + " pushed into Stack");
        }
    }

    public int pop() throws StackException {
        if (tos < 0)
            throw new StackException("Stack Underflow : could not pop, stack is empty");
        else
            return this.elements[tos--];
    }

    public int peek() throws StackException {
        if (tos < 0)
            throw new StackException("Stack Underflow : could not peek, stack is empty");
        else
            return this.elements[tos];
    }

    public int tos() {
        return this.tos;
    }

    @Override
    public String toString() {
        return "Stack : size = " + this.size;
    }
}