// Java implementation of the approach
class palindrome2
{
    public static void main (String[] args)
    {
        System.out.println("Oy, is it working?");
        
        int d = 12;
        printPalindromes(d);
    }

    // Function to return the
    // reverse of num
    static int reverse(int num)
    {
        int rev = 0;
        while (num > 0)
        {
            rev = rev * 10 + num % 10;
            num = num / 10;
        }
        return rev;
    }
    
    // Function that returns true
    // if num is palindrome
    static boolean isPalindrome(int num)
    {
        // If the number is equal to the
        // reverse of it then it
        // is a palindrome
        if (num == reverse(num))
            return true;
    
        return false;
    }
    
    // Function to print all the
    // d-digit palindrome numbers
    static void printPalindromes(int d)
    {
        if (d <= 0) return;
    
        // Smallest and the largest d-digit numbers
        boolean valid = false;
        // Starting from the smallest d-digit
        // number till the largest
        while (!valid)
        {
            // If the current number
            // is palindrome
            if (isPalindrome(d))
            { 
                System.out.print(d + " ");
                valid = true;
            }
            d = d + reverse(d);
        }
    }
    
}
