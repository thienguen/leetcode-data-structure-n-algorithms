import java.util.Scanner;

class palindrome {
    public static void main(String[] args) {
    
        Scanner scanner = new Scanner(System.in);   
        
        System.out.print("PALINDROME\n");
        System.out.print("Enter a number: ");
        
        int num = scanner.nextInt();

        int reversedNum = 0, remainder;
        
        int originalNum = num;

        while (num != 0) {
            remainder = num % 10;
            reversedNum = reversedNum * 10 + remainder;
            num /= 10;
        }

        if (originalNum == reversedNum) {
            System.out.println(originalNum + " is Palindrome.");
        } else {
            System.out.println(originalNum + " is not Palindrome.");

                originalNum = originalNum + reversedNum;

                num = originalNum;

                while (num != 0) {
                    remainder = num % 10;
                    reversedNum = reversedNum * 10 + remainder;
                    num /= 10;
                }
                if (reversedNum == originalNum) {
                    System.out.println(originalNum + " is a palindrome");
                } else {
                    System.out.println(originalNum + " is not a palindrome");
                }
        }
        
        scanner.close();
    }
}