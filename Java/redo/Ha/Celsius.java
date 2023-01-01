import java.util.Scanner;

public class Celsius  
{  
    public static void main (String args[])  
    {
        System.out.println("CONVERT FAHRENHEITH TO CELSIUS\n");
        
        Scanner scanner = new Scanner(System.in);
        
        float Fahrenheit, Celsius;  
        
        System.out.println("Enter a tempature in Farenheith : ");

        Fahrenheit = scanner.nextFloat();

        Celsius  = ((Fahrenheit-32)*5)/9;  
        
        System.out.println("The temperature in celsius is: " + Celsius);          

        scanner.close();

    }
}  