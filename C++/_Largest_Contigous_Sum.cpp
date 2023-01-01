/* 
	* Finds the largest contigous sum in a array of n elements
	* using Kadane's Algo. 
*/

#include <iostream>

using namespace std;

// finds the largest contigous sum
int largestSum(int arr[], int size)
{
	int maxSoFar = 0;
	int maxHere = 0;
	int maxNegative = 0;
	int countNeg = 0;
	for (int i = 0; i < size; ++i)
	{
		maxHere = maxHere + arr[i];

		if (maxHere < 0)
			maxHere = 0;

		if (maxHere > maxSoFar)
			maxSoFar = maxHere;

		// in case all the numbers are negative
		if (arr[i] < 0)
		{
			// count the no. of negative numbers in the list
			++countNeg;
			if (arr[i] > maxNegative)
				maxNegative = arr[i];
		}
	}
	// if there are only negative numbers in the array
	if (countNeg == size)
		return maxNegative;
	else
		return maxSoFar;
}

int main()
{
	int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

	int size = sizeof(arr) / sizeof(int);
	cout << "Largest Contigous Sum: " << largestSum(arr, size) << endl;
	return 0;
}
