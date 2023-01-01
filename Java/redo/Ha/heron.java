import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
public class heron {

    // Function to calculate area using Heron's Formula
    static void area(double a, double b, double c){
        double s = ( a + b + c) / 2;
        s = s * ( s - a ) * ( s - b ) * ( s - c);
        System.out.println("Area of the triangle is " + Math.sqrt(s));
    }

    // Function to read user input
    public static void main(String[] args) {
        double a,b,c;
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the three sides of the triangle");

        System.out.print("Enter a : ");
        a = scanner.nextDouble();
        
        System.out.print("\nEnter b : ");
        b = scanner.nextDouble();
        
        System.out.print("\nEnter c : ");
        c = scanner.nextDouble();

        area(a,b,c);

        scanner.close();
    }
}

