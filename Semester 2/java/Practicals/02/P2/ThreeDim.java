package P2;

import P1.TwoDim;

public class ThreeDim extends TwoDim {
    private int z;

    public ThreeDim() {
        super();
        this.z = 0;
    }

    public ThreeDim(int x, int y, int z) {

        super(x, y);
        this.z = x;
    }

    @Override
    public String toString() {
        return super.toString() + ", z = " + this.z;
    }
}