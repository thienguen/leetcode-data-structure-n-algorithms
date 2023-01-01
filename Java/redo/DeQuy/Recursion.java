public class Recursion {

    public static void main(String[] args) throws Exception 
    {   // theo tung cau, chat luong
        
        // ================================================================= //
        System.out.println("\nCau 1: Sau 5h so luong vi trung la " +
        time2Recursion(5) + "\n");
        
        // ================================================================= //
        System.out.println("Cau 2: Sau 30 nam, tong so tien lai duoc la "
        + bankInterest(1000, 0.12, 30) + "\n" );
        
        // ================================================================= //
        System.out.print("Cau 3: in dao nguoc so nguyen duong n = ");
        reverseNumber(123456789);
        
        // ================================================================= //
        System.out.println("\n\nCau 4: dem so nguyen duong n = " +
        countNumber(123456789) + " so\n");
        
        // ================================================================= //
        System.out.println("Cau 5: chu so le cua so nguyen duong n = " +
        oddDigitCounter(1234567) + " so\n");
        
        // ================================================================= //
        System.out.println("Cau 6: chu so lon nhat cua so nguyen duong n la so " +
        largestDigit(123456789) + "\n");
        
        System.out.println("Cau 6: chu so lon nhat cua so nguyen duong n la so " +
        largestDigit(7654321));
        
        System.out.println("\nCau 6: chu so lon nhat cua so nguyen duong n la so " +
        largestDigit(841246));
        
        // ================================================================= //
        System.out.print("\nCau 7: Kiem tra so nguyen duong co toan la so chan hay khong --> ");
        if (isEven(123456789) == 1) {
            System.out.println("So nguyen duong n khong phai la chu so toan chan\n");
        } else {
            System.out.println("So nguyen duong n la so toan chan\n");
        }
        
        // ================================================================= //
        System.out.println("Cau 8: Co so 2 Logarit cua so n la " + logarit(10) + "\n");
        
        // ================================================================= //
        System.out.println("Cau 9: Uoc so chung lon nhat cua 2 so a va b la: " + GCD(12, 18) + "\n");
    }

    // cau 1
    public static int time2Recursion(int n) {
        if (n < 1) {
            return 1;
        } else {
            return 2 * time2Recursion(n - 1);
        }
    }

    // cau 2
    public static double bankInterest(double balance, double interestRate, int years) {
        if (years == 0) {
            return balance;
        } else {
            return bankInterest(balance * (1 + interestRate), interestRate, years - 1);
        }
    }

    // cau 3
    public static void reverseNumber(int n) {
        if (n < 10) {
            System.out.print(n);
            return;
        } else {
            System.out.print(n % 10);
            reverseNumber(n / 10);
        }
    }

    // cau 4
    public static int countNumber(int n) {
        if (n == 0) {
            return 0;
        } else {
            return countNumber(n / 10) + 1;
        }
    }

    // cau 5
    public static int oddDigitCounter(int number) {
        if (number == 0) {
            return 0;
        }
        // 1 & 1 --> true. 1 & 0 --> false, hence we can check if the digit is odd
        return (number & 1) + oddDigitCounter(number / 10);
    }

    // cau 6
    public static int largestDigit(int n) {
        int largest = 0;
        int remainder = 0;

        if (n > 0) {
            remainder = n % 10;

            if (remainder > largest) {
                largest = remainder;
            }
            largestDigit(n / 10);
        }

        return largest;
    }

    // cau 7
    public static int isEven(int n) {
        if (n == 0) {
            return 0;
        } else {
            int remainder = n % 10;

            if ((remainder % 2) != 0) {
                return 1;
            }

            return isEven(n / 10);
        }
    }

    // cau 8
    public static int logarit(int n) {
        if (n < 0)
            return -1;
        else {
            if (n >= 2)
                return 1 + logarit(n / 2);
            else
                return 0;
        }
    }

    // cau 9
    public static int GCD(int a, int b) {
        if (a == b) return a;
        else {
            if (a > b) a = a - b;
            else b = b - a; 
        }
        return GCD(a, b);
    }


    // mac ke cai nay, viet choi
    public static int isPrime(int n) {
        if (n == 1) {
            return 0;
        } else if (n == 2) {
            return 1;
        } else {
            for (int i = 2; i <= n / 2; i++) {
                if (n % i == 0) {
                    return 0;
                }
            }
            return 1;
        }
    }

}

// câu 1: vi trùng cứ 1 giờ lại nhân đôi. Vậy sau 5 giờ sẽ có mấy con vi trùng
// nếu ban đầu có 2 con
// câu 2: gửi ngân hàng 1000usd, lãi 12%/năm. số tiền có được sau 30 năm là bao
// nhiêu
// câu 3: in đảo ngược số n nguyên dương
// câu 4: đếm số lượng chữ số nguyên dương n
// câu 5: hãy đếm số lượng chữ số lẻ của số nguyên dương n
// câu 6: tìm chữ số có giá trị lớn nhất của số nguyên dương n
// câu 7: kiếm tra số nguyên dương n có toàn chữ số chăn hay không ?
// câu 8: tìm giá trị nguyên logarit cơ số2 của n
// câu 9: tìm ước số chung lớn nhất của 2 số nguyên a,b
