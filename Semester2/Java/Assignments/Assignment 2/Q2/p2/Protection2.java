package p2;

class Protection2 extends p1.Protection {
    Protection2() {
        System.out.println("derived other package constructor");
        // class or package only
        // System.out.println("n = " + n + "//default variable");
        // class only
        // System.out.println("n_pri = " + n_pri + "//private variable");
        System.out.println("n_pro = " + n_pro + "//priotected variable");
        System.out.println("n_pub = " + n_pub + "//public variable");
    }
}
