
import java.util.Scanner;

public class entryfee {
    
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter age:");

        // your english suck
        int ageOfEntrace = scanner.nextInt();

        if (ageOfEntrace < 5)
        {
            float entryFee = 0f;
            System.out.println("The entry fees is: &$" + entryFee);
        } else if (ageOfEntrace > 65)
        {
            float entryFee = 1.50f;
            System.out.println("The entry fees is: &$" + entryFee);
        } else {
            float entryFee = 2.50f;
            System.out.println("The entry fees is: &$" + entryFee);
        }

    }

}
