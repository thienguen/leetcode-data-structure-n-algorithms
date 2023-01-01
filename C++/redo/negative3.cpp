/// Thien Nguyen nvktvan@gmail.com
/// #Problem 6: Describe an algorithm that takes as input a list of n integers and
/// #finds the number of negative integers in the list

#include <iostream>
#include <ostream>

using namespace std;

int *negative(int arr[], int arr_size) 
{
    // iterator through our negative number
    int iterator = 0;
    
    // the array store our negative numbers
    // using static to initialized all the address
    // we going to pass down function called;
    static int nega[100];

    // the loop that run through our original array then 
    for(int i = 0; i < arr_size; i++) { if(arr[i] < 0) { nega[iterator] = arr[i]; iterator++; } }

    // return how many of negative number
    return nega;
}

int ite(int ar[], int size)
{
    // variable declaration
    int count = 0;

    // the loop again to help us find the iterator
    for(int i = 0; i < size; i++) { if (ar[i] < 0) { count++; }}

    // return the iterator
    return count;
}

/// @paragraph main function wherer we perform the algorithm
int main()
{
    int *p;

    // the total number in our list
    int num;

    // input phase
    cout << "Enter the total integer input ? \n";
    cin >> num;

    // delcare array with 100 elements, could be more
    // but who would enter 100 number like dat
    int arr[num + 1] = {};

    // get the size of our array
    int n = sizeof(arr) / sizeof(arr[0]);

    // input phase 2 - take the input list into our array
    cout << "Enter the list of integer you want to find the negative numbers: " << endl;
    
    // entered -> get in this array
    for (int i = 0; i < num; i++) { cin >> arr[i]; }

    // point to the nega array return;
    p = negative(arr, n);

    // output phase, showing how many numbers of negative number are there.
    for (int i = 0; i < ite(arr, n); i++) { cout << *(p + i) << ' '; }

    cout << endl;
    // return to the operating system.
    return 0;
}
