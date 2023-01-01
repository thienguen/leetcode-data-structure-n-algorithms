
#include <iostream>
using namespace std;

int main()
{
     int i = 10;       // simple or ordinary variable.
     int *p = &i;      // single pointer
     int **pt = &p;    // double pointer
     int ***ptr = &pt; // triple pointer
     // All the above pointers differ in the value they store or point to.
     cout << "i = " << i << "\t" << '\n'
          << "p = " << p << "\t" << '\n'
          << "*p = " << *p << "\t" << '\n'
          << "pt = " << pt << "\t" << '\n'
          << "*pt = " << *pt << "\t" << '\n'
          << "*ptr = " << *ptr << '\n'
          << "ptr = " << ptr << '\n';
     int a = 5; // simple or ordinary variable
     int &S = a;
     int &S0 = S;
     int &S1 = S0;
     cout << "a = " << a << "\t" << '\n'
          << "S = " << S << "\t" << '\n'
          << "S0 = " << S0 << "\t" << '\n'
          << "S1 = " << S1 << '\n';
     // All the above references do not differ in their values
     // as they all refer to the same variable.
}

#include <iostream>
using namespace std;

void swap(char *&str1, char *&str2)
{
     char *temp = str1;
     str1 = str2;
     str2 = temp;
}

int main()
{
     char *str1 = "GEEKS";
     char *str2 = "FOR GEEKS";
     swap(str1, str2);
     cout << "str1 is " << str1 << '\n';
     cout << "str2 is " << str2 << '\n';
     return 0;
}