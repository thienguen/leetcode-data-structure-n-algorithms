/// @paragraph 
/// Thien Nguyen nvktvan@gmail.com
/// #Describe an algorithm that takes as input a list of n integers in nondecreasing
/// #order and produces the list of all values that occur more than once

#include <iostream>
using namespace std;

void most_occurred_number(int nums[], int size)
{   
    // max count started at 0
    int max_count = 0;
    // well, the answer
    cout << "\nMost occurred number: ";
    
    // run through the array start at 0 we entered
    int count = 1;
    for (int i = 0; i < size; i++)
    {
        // Set count = 1, then run through the array start at 1 we entered 
        // each number i, we run through the loop with j = i + 1;
        // if the next number is equal to the previous number
        // hence, count added 1
        for (int j = i + 1; j < size; j++) 
        { if (nums[i] == nums[j]) { count++; } }

        // if the number we counting is larger then it's the 
        // most occured numbers
        if (count > max_count) { max_count = count; }
    }

    // now we know the most occured number, but we don't know what position
    // that number is in, so we run through the loop again, start at position 0
    int count = 1;
    for (int i = 0; i < size; i++)
    {
        // run though each and invidual number
        for (int j = i + 1; j < size; j++)  { if (nums[i] == nums[j]) { count++; }}
        
        // the number we are checking is the answer we found above, print it
        if (count == max_count) { cout << nums[i] << endl; }
    }
}

int main()
{
    // declare the arary we wanted to find
    int nums[] = {4, 5, 9, 12, 9, 22, 45, 7, 7 ,8, 10, 9, 12, 11, 22, 45, 12};
    
    // get the size of it
    int n = sizeof(nums) / sizeof(nums[0]);

    // display the original array into the stream/terminal
    cout << "Original array: ";
    for (int i=0; i < n; i++) { cout << nums[i] <<" "; } 

    // use our algorithm
    most_occurred_number(nums, n);
}
