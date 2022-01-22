public class UnderAgeException extends Exception {
    int age;

    UnderAgeException(int age) {
        this.age = age;
    }

    @Override
    public String getMessage() {
        return "Under Age : " + this.age;
    }
}