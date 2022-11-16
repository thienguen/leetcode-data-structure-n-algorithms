// Simple C++ program to remove duplicates
#include <iostream>
#include <vector>

using namespace std;

// Function to remove duplicate elements
// This function returns new size of modified array.
int removeDuplicates(int *arr, int n)
{
    // Return, if array is empty
    // or contains a single element
    if (n == 0 || n == 1)
        return n;

    int *temp = new int[n];

    // Start traversing elements
    int newSize = 0;
    for (int i = 0; i < n - 1; i++)
        if (arr[i] != arr[i + 1]) { temp[newSize++] = arr[i]; }
        // If current element is not equal
        // to next element then store that
        // current element

    temp[newSize++] = arr[n - 1];
    // Store the last element as whether
    // it is unique or repeated, it hasn't
    // stored previously

    for (int i = 0; i < newSize; i++) { arr[i] = temp[i]; }
    // Modify original array

    return newSize;
}

// Driver code
int main()
{
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // removeDuplicates() returns new size of array.
    n = removeDuplicates(arr, n);

    // Print updated array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return EXIT_SUCCESS;
}
