import java.util.Scanner;

public class Shoessize {
    
    public static void main(String[] args)
    {

        System.out.println("ASIAN SHOES SIZE\n");

        
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter your shoes length");
        
        int lenght = scanner.nextInt();
        
        int size = ( ( (lenght - 9) * 3 ) / 2 ) + 15;
        
        if (size >= 17 && size <= 46)
        {
            System.out.println(" Your shoes size is: " + size);

        } else {
            System.out.println("Not Asian shoes size");
        }
        

        scanner.close();




    }
}
