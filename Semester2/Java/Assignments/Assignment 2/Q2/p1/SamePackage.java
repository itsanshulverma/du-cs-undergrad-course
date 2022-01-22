package p1;

class SamePackage {
    SamePackage() {
        Protection p = new Protection();
        System.out.println("same package constructor");
        System.out.println("n = " + p.n + "//default variable");
        // class only
        // System.out.println("n_pri = " + p.n_pri + "//private variable");
        System.out.println("n_pro = " + p.n_pro + "//protected variable");
        System.out.println("n_pub = " + p.n_pub + "//public variable");
    }
}
