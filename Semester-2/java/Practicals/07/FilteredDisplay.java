import java.io.*;

public class FilteredDisplay {
    public static void main(String[] args) {
        if (args.length != 1)
            System.err.println("\nCorrect Usage : java FilteredDisplay <filename.txt>");
        else {
            try (BufferedReader br = new BufferedReader(new FileReader(args[0]))) {
                String line;
                System.out.println("\nReading " + args[0] + "...\n");
                while ((line = br.readLine()) != null) {
                    if (line.trim().substring(0, 2).equals("//")) {
                        System.out.println(line);
                    }
                }
                br.close();
            } catch (final Exception e) {
                System.err.println(e.getMessage());
            }
        }
    }
}