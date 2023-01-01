/* 
	1 2 3 
	8 9 4 
	7 6 5

	For dumbass reason, gotta format the output too
	But that sound like tmw me problem.
*/

#include <iostream>
#include <iomanip>
#include <vector>

using std::cout;
using std::vector;
using std::endl;

template <class T>
void disp(T arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << std::setw(2) << arr[i][j] << " ";
		cout << endl;
	}
}

/*
	* generates the matrix
	* Just do the spiral traversal
*/

vector<vector<int>> spiralMatrix(int d)
{
	// allocate space for dXd matrix
	vector<vector<int>> arr(d, vector<int>(d));

	int k = 1;
	bool right = true, left = false, up = false, down = false;
	int rs = 0, re = d - 1, cs = 0, ce = d - 1;

	while (rs <= re && cs <= ce)
	{
		if (right)
		{
			right = false;
			down = true;

			for (int i = cs; i <= ce; i++)
				arr[rs][i] = k++;
			rs++;
		}
		else if (down)
		{
			down = false;
			left = true;

			for (int i = rs; i <= re; i++)
				arr[i][ce] = k++;
			ce--;
		}
		else if (left)
		{
			left = false;
			up = true;

			for (int i = ce; i >= cs; i--)
				arr[re][i] = k++;
			re--;
		}
		else if (up)
		{
			up = false;
			right = true;

			for (int i = re; i >= rs; i--)
				arr[i][cs] = k++;
			cs++;
		}
	}
	return arr;
}

int main()
{
	int d = 5;
	vector<vector<int>> D = spiralMatrix(d);
	disp(D, d);
}
