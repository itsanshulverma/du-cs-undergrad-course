class User {
    String name, address;
    boolean isRegistered;

    User() {
        this.name = "Unknown";
        this.isRegistered = false;
        System.out.println("User not registered! //default constructor");
    }

    User(String name) {
        this.name = name;
        this.isRegistered = true;
        System.out.println("User " + name + " registered! //Parameterized constructor");
    }

    void setAddress(String details) {
        this.address = details;
    }

    void setAddress(String city, String zip) {
        this.address = city + " " + (zip);
    }

    void setAddress(String city, int zip) {
        this.address = city + " " + Integer.toString(zip);
    }

    void setAddress(int zip, String city) {
        this.address = city + " " + Integer.toString(zip);
    }

}

public class Test {

    public static void main(String[] args) {
        System.out.println();
        User a = new User();
        User b = new User("Abhishek");
        System.out.println("\nMethod Overloading with no of parameters : ");
        b.setAddress("Delhi 110011");
        System.out.println("Address : " + b.address + " //1 parameter of type string");
        b.setAddress("Delhi", "110011");
        System.out.println("Address : " + b.address + " //2 parameters of type string_string");
        System.out.println("\nMethod Overloading with type of parameters : ");
        b.setAddress("Delhi", "110011");
        System.out.println("Address : " + b.address + " //2 parameters of type string_string");
        b.setAddress("Delhi", 110011);
        System.out.println("Address : " + b.address + " //2 parameters of type string_int");
        System.out.println("\nMethod Overloading with different sequence of parameters : ");
        b.setAddress(110011, "110011");
        System.out.println("Address : " + b.address + " //2 parameters of type int_string");
        b.setAddress("Delhi", 110011);
        System.out.println("Address : " + b.address + " //2 parameters of type string_int");
    }

}