/// @paragraph this program calculate the total of n 
/// number in natural positive integer
/// Thien Nguyen nvktvan@gmail.com

#include <iostream>
using namespace std;

int main() {
    int n;
    int sum = 0;

    cout << "Enter a positive integer: ";
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    cout << "Sum of "<< n << " numbers are = " << sum << endl;
    return 0;
}
