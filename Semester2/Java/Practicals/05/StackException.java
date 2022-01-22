public class StackException extends Exception {
    String message;

    StackException(String message) {
        this.message = message;
    }

    @Override
    public String getMessage() {
        return message;
    }
}