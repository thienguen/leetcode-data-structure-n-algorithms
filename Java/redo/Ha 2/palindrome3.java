// Main class
class palindrome3 {

    // Method 1
    // Returns true if string is a palindrome
    static boolean isPalindrome(String str)
    {

        // Pointers pointing to the beginning
        // and the end of the string
        int i = 0, j = str.length() - 1;

        // While there are characters to compare
        while (i < j) {

            // If there is a mismatch
            if (str.charAt(i) != str.charAt(j))
                return false;

            // Increment first pointer and
            // decrement the other
            i++;
            j--;
        }

        // Given string is a palindrome
        return true;
    }

    // Main driver method
    public static void main(String[] args)
    {
        String str = "geeks";
        String str2 = "RACEcar";
    
        //Change strings to lowercase
        str = str.toLowerCase();
        str2 = str2.toLowerCase();

        // For string 1
        System.out.print("String 1 :");

        if (isPalindrome(str))
            System.out.print("It is a palindrome");
        else
            System.out.print("It is not a palindrome");

        // new line for better readability
        System.out.println();

        // For string 2
        System.out.print("String 2 :");
        if (isPalindrome(str2))
            System.out.print("It is a palindrome\n");
        else
            System.out.print("It is not a palindrome\n");
    }
}