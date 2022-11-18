// Given 'n'.Print Pascal's triangle
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// prints pascal's triangle
void printPascalTriangle(int n)
{
	vector< vector<int> > arr(n, vector<int>(n, 0));
	arr[0][0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				arr[i][j] = 1;
			else
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n - i; k++)
			cout << setw(3) << " ";

		for (int j = 0; j <= i; j++)
			cout << setw(3) << arr[i][j] 
				 << setw(3) << " ";
		cout << endl;
	}
}

int main()
{
	int n = 10;
	printPascalTriangle(n);
}
