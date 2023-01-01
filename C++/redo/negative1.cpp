/// Thien Nguyen nvktvan@gmail.com
/// #Problem 6: Describe an algorithm that takes as input a list of n integers and
/// #finds the number of negative integers in the list

#include <iostream>
#include <ostream>

using namespace std;

int negative(int arr[], int arr_size) 
{
    // iterator through our negative number
    int iterator  = 0;

    // the loop that run through our original array then 
    for(int i = 0; i < arr_size; i++) { if(arr[i] < 0) { iterator++; } }

    // return how many of negative number
    return iterator;
}

/// @paragraph main function wherer we perform the algorithm
int main()
{

    // size of our otiginal array
    int size = 0;

    // ask for how many elements we will be doing
    cout << "Enter your size of array:" << endl;
    cin  >> size;

    // delcare array with 100 elements, could be more
    // but who would enter 100 number like dat
    int arr[size + 1] = {};

    // get the size of our array
    int n = sizeof(arr) / sizeof(arr[0]);

    // the total number in our list
    int num;

    // input phase
    cout << "Enter the total integer input ? \n";
    cin >> num;

    // input phase 2 - take the input list into our array
    cout << "Enter the list of integer you want to find the negative numbers: " << endl;
    for (int i = 0; i < num; i++) { cin >> arr[i]; }

    // output phase, showing how many numbers of negative number are there.
    cout << "There are " << negative(arr, n) << "numbers in your list\n"; 

    return 0;
}
