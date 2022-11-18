/*
	* C++ Program to Arrange Even and Odd Numbers
	given an array of numbers .arrange in such a away that 
	all the even nos. comes first and 
	all the odd nos. comes in the end
*/

#include <iostream>
#include <vector>

using namespace std;

void arrangeNum(vector<int> &arr)
{
	int i = 0;				// for keeping track of even nos.
	int j = arr.size() - 1; // for keeping track of odd nos.
	int t = 0;

	while (i < j)
	{
		// when the num is odd swap it with the odd index
		if (arr[i] % 2 != 0)
		{
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
			j--;
		}
		else
		{
			// when the num is even
			i++;
		}
	}
}

void disp(vector<int> &arr)
{
	for (size_t i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	arrangeNum(arr);
	disp(arr);

	return 0;
}