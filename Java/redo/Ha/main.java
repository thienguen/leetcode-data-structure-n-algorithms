import java.util.Scanner;

public class main {
    public static void main(String[] args) {

    System.out.println("ASIAN SHOES SIZE\n");

    
    Scanner scanner = new Scanner(System.in);
    
    System.out.println("Enter your shoes length");
    
    int lenght = scanner.nextInt();
    
    int size = ( ( (lenght - 9) * 3 ) / 2 ) + 15;
    
    
    System.out.println(" Your shoes size is: " + size);

    scanner.close();
    }

}