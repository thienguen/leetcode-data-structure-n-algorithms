import java.util.Scanner;

public class Loan {

	public static void main(String[] args)
	{
        Scanner scan = new Scanner(System.in); 
            // input process
            System.out.print("Enter Principal Amount : ");
            double principal = scan.nextDouble(); 

            System.out.print("Enter the number of period in years : ");
            double years = scan.nextInt();

            System.out.print("Enter interest rate : ");
            double rate = scan.nextDouble(); 

            // process phase
            rate  = rate  / 12; 
            years = years * 12;
            
            // output phase
            double payment = ( principal * rate ) / (1 - Math.pow(1 + rate, - years));
            System.out.println("Payment: " + payment);

            scan.close();   
        }
    
}
