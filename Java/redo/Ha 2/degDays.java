import java.util.Scanner;

public class degDays {
    
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter high temp:");
        
        int highTemp = scanner.nextInt();
        
        System.out.print("Enter low temp:");
        
        int low = scanner.nextInt();

        float degDays = 65 - ( ( highTemp + low ) / 2 );

        if (degDays < 0) {
            float coolingDegDays = degDays;
            System.out.println("Cooling days" + coolingDegDays + " F");
        } else {
            float heatingDegDays = degDays;
            System.out.println("heating days: " + heatingDegDays + " F");
        }

        scanner.close();
    }

}
