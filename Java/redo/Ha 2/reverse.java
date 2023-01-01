import java.util.Scanner;

class reverse {
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);   
        
        System.out.println("DIGIT REVERSAL\n");

        System.out.print("Enter a positive integer: ");

        int num = scanner.nextInt();

        int reversed = 0;

        while(num != 0) {
        
            int digit = num % 10;
            
            reversed = reversed * 10 + digit;
    
            num /= 10;
        }
    
        System.out.println("The integer with digits revered is: " + reversed);
    }
}