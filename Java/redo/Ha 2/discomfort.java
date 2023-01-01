import java.util.Scanner;

public class discomfort {
    
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("The dry-bulb temperature today is: ");
        
        double dryTemp = scanner.nextDouble();
        
        System.out.print("The wet-bulb temperature today is: ");
        
        double wetTemp = scanner.nextDouble();

        double ans = 0.4 * (dryTemp + wetTemp) + 15;

        if ( ans > 85 ) 
        {
            System.out.print("The discomfort index to day is: " + ans);
            System.out.println(" ,very uncomfortable, thanks");
            
        } else {
            System.out.print("The discomfort index to day is: " + ans);
            System.out.println(" ,a pleasant day, thanks");
        }
        scanner.close();
    }
}
