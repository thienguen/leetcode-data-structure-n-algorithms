#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>
#include <limits>

void diamond(int32_t n, int32_t space);
void diamondRecursive(int32_t n);
void RowNumbers(int n, int max);
void PrintRhombus(int n, int i = 1);
unsigned int sumOfTheSquares(int n);
bool isPalindrome(std::string str);
int func(int32_t x, int32_t y);
double squareRoot(double x, double a, double epsilon);
template <class InputIt, class T>
InputIt find(InputIt first, InputIt last, const T &value);

int main()
{
    int32_t n = 0, space = 0;

    while (std::cin >> n && n > 0)
    {
        /**/
        std::cout << "CASE 1: Recursive diamond" << std::endl;
        std::cout << "Non-recursive:" << std::endl;
        diamond(n, space);

        std::cout << "Recursive Rhombus:" << std::endl;
        PrintRhombus(n);

        std::cout << "Recursive diamond:" << std::endl;
        diamondRecursive(n);

        /**/
        std::cout << "CASE 2: Sum of the squares" << std::endl;
        std::cout << "Sum of the squares: ";
        std::cout << sumOfTheSquares(n) << std::endl;

        /**/
        std::cout << "CASE 3: Palindrome" << std::endl;
        std::string str = "A Man, a Plan, a Canal -- Panama!";
        std::cout << "Is this string: " << str << " a palindrome? ";

        if (isPalindrome(str))
            std::cout << "Yes\n\n";
        else
            std::cout << "No\n\n";

        /**/
        std::cout << "CASE 4: Greatest common divisor" << std::endl;
        std::cout << "func(12, 18) = " << func(12, 18) << std::endl;
        std::cout << "func(18, 12) = " << func(18, 12) << std::endl;

        /**/
        std::cout << "CASE 5: Square root" << std::endl;
        std::cout << "squareRoot(2.0, 2, 0.0001) = " << squareRoot(2.0, 2.0, 0.0001) << std::endl;
        std::cout << "squareRoot(2.0, 2, 0.0000001) = " << squareRoot(2.0, 2.0, 0.0000001) << std::endl;
        std::cout << "squareRoot(200.0, 200.0, 0.0000001) = " << squareRoot(200.0, 200.0, 0.0000001) << std::endl;

        /**/
        std::cout << "CASE 6: Find" << std::endl;
        std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        std::vector<int>::iterator it = ::find(v.begin(), v.end(), 5);

        if (it != v.end())
            std::cout << "Element found in myvector: " << *it << '\n';
        else
            std::cout << "Element not found in myvector\n";

        std::cout << "End of cases for n = " << n << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Continue with a new n or enter 0 to exit: ";
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}

void diamond(int32_t n, int32_t space)
{
    space = n - 1;

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= space; i++)
            std::cout << ".";

        space--;

        for (int j = 1; j <= 2 * k - 1; j++)
            std::cout << "*";

        std::cout << std::endl;
    }

    space = 1;

    for (int k = 1; k <= n - 1; k++)
    {
        for (int i = 1; i <= space; i++)
            std::cout << ".";

        space++;

        for (int j = 1; j <= 2 * (n - k) - 1; j++)
            std::cout << "*";

        std::cout << std::endl;
    }
}

void diamondRecursive(int32_t n)
{
    int c, space;
    static int stars = -1;

    if (n <= 0)
        return;

    // top half
    space = n - 1;
    stars += 2;
    for (c = 0; c < space; c++)
        std::cout << ".";
    for (c = 0; c < stars; c++)
        std::cout << "*";
    std::cout << std::endl;

    diamondRecursive(--n);

    // bottom half
    space = n + 1;
    stars -= 2;
    for (c = 0; c < space; c++)
        std::cout << ".";
    for (c = 0; c < stars; c++)
        std::cout << "*";
    std::cout << std::endl;
}

void RowNumbers(int n, int max)
{
    if (n < max)
    {
        std::cout << n << ' ';
        RowNumbers(n + 1, max);
    }
    std::cout << n << ' ';
}

void PrintRhombus(int n, int i)
{
    if (i == 2 * n)
        return;

    int numbers_in_line = i < n ? i : 2 * n - i;
    int space = (n - numbers_in_line) * 2;

    std::cout << std::string(space, ' ');

    RowNumbers(1, numbers_in_line);

    std::cout << std::endl;

    PrintRhombus(n, i + 1);
}

unsigned int sumOfTheSquares(int n)
{
    if (n == 1)
        return 1;
    return n * n + sumOfTheSquares(n - 1);
}

bool isPalindrome(std::string str)
{
    // if lenght is 0 or 1, it is a palindrome by definition
    if (str.length() == 0 || str.length() == 1)
        return true;
    // if not alphanumeric, remove first char
    if (!isalnum(str[0]))
        return isPalindrome(str.substr(1, str.length() - 1));
    // if not alphanumeric, remove last char
    if (!isalnum(str[str.length() - 1]))
        return isPalindrome(str.substr(0, str.length() - 1));
    // if not equal, return false
    if (std::tolower(str[0]) != std::tolower(str[str.length() - 1]))
        return false;
    // if equal, remove first and last char and recurse
    return isPalindrome(str.substr(1, str.length() - 2));
}

int func(int32_t x, int32_t y)
{
    if (y == 0)
        return x;

    return func(y, x % y);
}

double squareRoot(double x, double a, double epsilon)
{
    if (fabs(a * a - x) <= epsilon)
        return a;

    return squareRoot(x, (a * a + x) / (2*a), epsilon);
}

template <class InputIt, class T>
InputIt find(InputIt first, InputIt last, const T &value)
{
    if (first == last)
        return last;
    if (*first == value)
        return first;
    return ::find(++first, last, value);
}
