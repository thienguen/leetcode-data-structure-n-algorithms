/// Thien Nguyen nvktvan@gmail.com
/// #Problem 6: Describe an algorithm that takes as input a list of n integers and
/// #finds the number of negative integers in the list

#include <iostream>
#include <ostream>

using namespace std;

/// @paragraph main function wherer we perform the algorithm
int main()
{

    // the total number in our list
    int num;

    // input phase
    cout << "Enter the total integer input ? \n";
    cin  >> num;

    // delcare array with 100 elements, could be more
    // but who would enter 100 number like dat
    int arr[num + 1] = {};

    // get the size of our array
    int n = sizeof(arr) / sizeof(arr[0]);

    // input phase 2 - take the input list into our array
    cout << "Enter the list of integer you want to find the negative numbers: " << endl;
    for (int i = 0; i < num; i++) { cin >> arr[i]; }

    // declare the array store our negative numbers
    static int nega[100] = {};

    // iterator through our negative arary
    int iterator = 0;

    // the loop that run through our original array then 
    for(int i = 0; i < num; i++) { if(arr[i] < 0) { nega[iterator] = arr[i]; ++iterator; } }
    
    cout << "The negative numbers in your list: ";

    // the loop of answer?
    for (size_t i = 0; i < iterator; i++) 
    { cout << nega[i] << ' '; }

    cout << endl;
    // return 0
    return 0;
}
