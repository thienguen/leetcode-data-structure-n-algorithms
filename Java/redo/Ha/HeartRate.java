import java.util.Scanner;

class HeartRate
{
	public static void main(String args[])
	{
        double max, min;

        Scanner scanner = new Scanner(System.in);

        System.out.println("TARGET HEART RATE");

        System.out.print("Enter your age : ");
        double age = scanner.nextDouble();

          max = (220 - age) * 0.85;
          min = (220 - age) * 0.65;

        int a = (int) max;
        int b = (int) min;
        System.out.println("Your target heartrate is " + b + " to " + a + " beats per minute.");

        scanner.close();
	}	
}