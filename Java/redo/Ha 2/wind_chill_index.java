import java.util.Scanner;

public class wind_chill_index {
    
    public static void main(String[] args)
    {
        // the flyer doesn't have formula so F
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the wind speed (>= 2): ");
        
        double speed = scanner.nextDouble();
        
        System.out.print("Enter the air temparature between -58ºF and 41ºF: ");
        
        double temperature = scanner.nextDouble();
        
        double windChill = 35.74 + 0.6215 * temperature - 
                        35.75 * Math.pow(speed, 0.16) + 0.4275 
                        * temperature * Math.pow(speed, 0.16);
        if (windChill < -25) {
            System.out.print("The wind chill index is : " + windChill);
            System.out.println("it's dangerous");
        } else if (windChill < -75) 
        {
            System.out.print("The wind chill index is : " + windChill);
            System.out.println("it's super dangerous");
        } else {
            System.out.print("The wind chill index is : " + windChill);
            System.out.println(" it's normal");
        }
        
        scanner.close();
    }
}
