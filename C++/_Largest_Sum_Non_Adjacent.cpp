/* 
	* Find the largest sum of non adjacent positive array elements
	* Non adjacent mean they separated by at least one element
	* 1 2 3 4 5 6
	* 1 + 3 + 5 = 9
	* 2 + 4 + 6 = 12
	* The larger sum is 12
*/

#include <iostream>
using namespace std;

int sum(int arr[], int size)
{
	int maxSum1 = 0;  // sums elements starting from 0th to size-1th
	int maxSum2 = 0;  // sums elements starting from 1st to sizeth
	int i = 0, j = 0;
	while (i < size - 1)
	{
		maxSum1 += arr[i];
		maxSum2 += arr[i + 1];
		i = i + 2;
	}
	return (maxSum1 > maxSum2 ? maxSum1 : maxSum2);
}

void display(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = {5, 5, 10, 100, 10, 5};
	int size = sizeof(arr) / sizeof(int);

	cout << "Contents :" << endl;
	display(arr, size);

	cout << "Largest sum:" << sum(arr, size);
	return 0;
}
