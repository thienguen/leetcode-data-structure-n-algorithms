import java.util.Scanner;

public class congress {
    
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        System.out.println("CONGRESS ELIGIBILITY\n");

        System.out.print("Enter age of candidate: ");
        
        int age = scanner.nextInt();
        
        System.out.print("Enter years of U.S citizenship: ");
        
        int years = scanner.nextInt();

        if (age >= 30 && years >= 9) 
        {
            System.out.println("The candidate is " +
                                "eligibile for election to both" + 
                                " the HOR and the Senate");
        } else if (age >= 25 && years <= 9 && years >= 7) {
            System.out.println("The candidate is eligibile for election to" 
                                + " the HOR but not the Senate ");
        } else 
        {
            System.out.println("The candidate is not " +
                                "eligibile for election to either" +
                                " the HOR and the Senate ");
            
        }

        scanner.close();
    }
}
