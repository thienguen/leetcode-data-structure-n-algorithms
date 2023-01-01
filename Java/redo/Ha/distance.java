import java.util.Scanner;

public class distance {
    public double calculateDistanceBetweenPoints(double x1, double y1, double x2, double y2) 
    { return Math.sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1)); }

    public static void main(String arg[])	
	{
        int x1,x2,y1,y2;

        double distance;

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter x1 point : ");
            x1 = sc.nextInt();

        System.out.print("Enter y1 point : ");
            y1 = sc.nextInt();

        System.out.print("Enter x2 point : ");
            x2 = sc.nextInt();

        System.out.print("Enter y2 point : ");
            y2 = sc.nextInt();

        distance=Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

        
        System.out.println("Distance between " + "(" + x1 + "," + y1 + ")," + "(" + x2 + "," + y2 + ") is " + distance);
	
        sc.close();
	}

}


