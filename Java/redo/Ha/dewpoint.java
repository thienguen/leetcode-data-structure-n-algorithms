import java.util.Scanner;

public class dewpoint {
    
    public static void main(String[] args)
    {
        double dew, tem, hum, a, b, c;
        Scanner scanner = new Scanner(System.in);

        double N1 = 14.55;
        double N2 = 0.114;
        double N3 = 2.5;
        double N4 = 0.0007;
        double N5 = 15.9;
        double N6 = 0.117;
        double N7 = 0.01;

        System.out.print("Enter tempature : ");
        tem = scanner.nextDouble();

        System.out.print("\nEnter raltive humidity : ");
        hum = scanner.nextDouble();

        a = tem - (N1 + (N2 * hum)) * (1 - (N7 * hum));
        b = Math.pow((N3 + (N4 * tem)) * (1 - (N7 * hum)), 3);
        c = Math.pow((N5 + (N6 * tem)) * (1 - (N7 * hum)), 14);
        
        dew = a - b - c;

        System.out.println("dew point is : " + dew);
        
        scanner.close();
    }
}
