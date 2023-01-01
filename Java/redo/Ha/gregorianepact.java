import java.util.Scanner;

public class gregorianepact {
    
    public static void main(String[] args)
    {
        // set up
        double century, golden, years, day;
        Scanner sc = new Scanner(System.in);

        // question prompt
        System.out.println("GREGORIAN EPACT\n");
        System.out.print("Enter the year : ");

        // input phase
        years = sc.nextDouble();

        // processing phase
        century = years / 100;
        golden  = 1 + (years % 19);

        // processing phase
        day     = 8 + (century / 4) - century + (8 * century + 13) / 25 + 11 * (golden - 1);
        day     = day % 30;
        
        // convert to int
        int d   = (int) day;
        int y   = (int) years;
        System.out.println("The Gregorian Epact of " + y + " is " + d);

        sc.close();
    }


}
