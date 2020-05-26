package P;

import P1.TwoDim;
import P2.ThreeDim;

public class Main {

    public static void main(String[] args) {

        TwoDim obj = new TwoDim(4, 6);
        System.out.println("\n" + obj);
        obj = new ThreeDim(3, 4, 9);
        System.out.println(obj);

    }
}