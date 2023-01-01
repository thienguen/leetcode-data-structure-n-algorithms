import java.util.Scanner;

public class moisture {
    
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter temperature: ");

        double temp = scanner.nextDouble();

        System.out.print("Enter vapour pressure of water: ");

        double vapour = scanner.nextDouble();

        double e = temp + (vapour - 10);

        if (e <= 85) {
            System.out.println("Average humidity");
        } else if (e > 100) 
        {
            System.out.println("Discomfort for human");
        } else {
            System.out.println("All activities should be postpone");
        }

        scanner.close();
    }

}
