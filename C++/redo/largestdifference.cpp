/// Thien Nguyen nvktvan@gmail.com
#include <iostream>
#include <ostream>

using namespace std;

// function that does the work for us, like def in python
// this should only take non decresing order array
int maxDiff(int arr[], int arr_size)
{
    // set largest difference 
    int max_diff = 0;
    
    // this is our largest element so far
    int largest_element = arr[0];

    // this loop help find the largest element of the bunch
    for (int i = 0; i < arr_size; i++) 
    {
        for (int j = i+1; j < arr_size; j++) { if (arr[j] > arr[i]) { largest_element = arr[j]; } }
    }

    // this loop help find the largest differnce between the bunch
    for (int i = 0; i < arr_size; i++)
    {
        { if (largest_element - arr[i] > max_diff) { max_diff = largest_element - arr[i]; } }
    }
    
    // return the largest difference;
    return max_diff;
}

/// @paragraph main function wherer we perform the algorithm
int main()
{
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
    cout << "Enter the list of integer you want to find the difference: " << endl;
    for (int i = 0; i < num; i++) { cin >> arr[i]; }

    // Function calling
    cout << "Largest difference between smallest number and biggest number in our array is: "
         << maxDiff(arr, n) << endl;

    return 0;
}
