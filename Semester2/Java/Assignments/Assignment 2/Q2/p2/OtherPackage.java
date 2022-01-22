package p2;

class OtherPackage {
    OtherPackage() {
        p1.Protection p = new p1.Protection();
        System.out.println("other package constructor");
        // class or package only
        // System.out.println("n = " + p.n + "//default variable");
        // class only
        // System.out.println("n_pri = " + p.n_pri + "//private variable");
        // class, subclass or package only
        // System.out.println("n_pro = " + p.n_pro + "//protected variable");
        System.out.println("n_pub = " + p.n_pub + "//public variable");
    }
}
