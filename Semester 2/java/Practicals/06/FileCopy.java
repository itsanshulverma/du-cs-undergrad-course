import java.io.*;

public class FileCopy {
    public static void main(String[] args) throws Exception {
        if (args.length != 2)
            System.out.println("\nCorrect Usage : java FileCopy <filename1.txt> <filename2.txt>");
        else {
            FileInputStream fin = new FileInputStream(args[0]);
            FileOutputStream fout = new FileOutputStream(args[1]);
            int i;
            System.out.println("\nCopying data from " + args[0] + " to " + args[1] + "....");
            while ((i = fin.read()) != -1) {
                fout.write(i);
            }
            System.out.println(">> Copying Done!");
            fin.close();
            fout.close();
        }
    }
}