/// Thien Nguyen nvktvan@gmail.com
#include<iostream>
using namespace std;
int main()
{
    // variable declaration(s)
    int i, n, number;
    int sum = 0;

    // ask for input
    cout << "How many numbers you want to enter ? ";
    cin  >> n;
    cout << "Enter "<<n<<" numbers: \n";

    // for loop that run through the total we entered
    for(i=0; i<n; i++) {
        cin >> number;
        sum += number;
    }

    // the result
    cout <<"Sum of "<<n<<" numbers you entered is "<<sum;
    cout <<endl;
    return 0;
}
