import java.util.Scanner;

public class Obesity {
    
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter your sex (0 for male, 1 for female): ");

        int sex = scanner.nextInt();

        if (sex == 0) {
            
            double BMI = BMI();
            
            if (BMI < 27.8 && BMI >= 25)
            {
                System.out.print("You are not obese, you risk of heart desease is very average");
            } else if (BMI < 25) {
                System.out.print("You are not obese, you risk of heart desease is low");
            } else if (BMI >= 27.8 && BMI < 30) {
                System.out.print("You are obese, you risk of heart desease is average");
            } else {
                System.out.print("You are obese, you risk of heart desease is high af");
            }
            
        } else if (sex == 1) {
            double BMI = BMI();

            if (BMI < 27.3 && BMI >= 25)
            {
                System.out.print("You are not obese, you risk of heart desease is very average");
            } else if (BMI < 25) {
                System.out.print("You are not obese, you risk of heart desease is low");
            } else if (BMI >= 27.3 && BMI < 30) {
                System.out.print("You are obese, you risk of heart desease is average");
            } else {
                System.out.print("You are obese, you risk of heart desease is high af");
            }
        }

    }

    public static double BMI() {

        Scanner scanner = new Scanner(System.in);
        // who know their own height in inches...even if they do? why
        System.out.print("\nInput height in inches: ");

        double height = scanner.nextDouble();

        height = height / 39.37;

        System.out.print("Input weight in pounds: ");

        double weight = scanner.nextDouble();
               weight = weight / 2.2d;

        double BMI = weight / (height * height);

        System.out.println("\nThe Body Mass Index (BMI) is " + BMI);

        return BMI;
    }
    
}
