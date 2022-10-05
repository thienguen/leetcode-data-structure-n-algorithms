//  CS 302
//  Provided Main Program

//  Selection pronlem -> selects kth smallest number from
//  a group of N numbers.

//  Implements two approachs:
//	selection sort
//	recursive quick select (based on quicksort)

// ***********************************************************************
//  Includes and prototypes.

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int	readVal(const string, const int);
void	generateRandomValues(int [], int);
void	selectionSort(int [], int, int);
int	median3(int [], int, int);
void	quickSelect(int [], int, int);
void	quickSelect(int [], int, int, int);
void	swap(int &, int &);


// *******************************************************************

int main(int argc, char *argv[])
{


// ------------------------------
//  Declarations and headers.
	enum	algorithmOption { SORTSELECT, QUICKSELECT, PRINT, NONE };
	string	stars, bars;
	stars.append(60,'*');
	bars.append(50,'=');
	string	pmpt1 = "Enter number of values to generate: ";
	string	pmpt2 = "Enter kth value to find: ";

	const	int	MAXNUMBERS=5000000;
	int	k, len;
	algorithmOption	userChoice = NONE;

// ------------------------------
//  Verify command line arguments.
//	Error out if bad, select user selection if good.

	if (argc == 1) {
		cout << "Usage: findkth <-s|-qs>" << endl;
		return 0;
	}

	if (argc != 2) {
		cout << "Error, invalid command line options." << endl;
		return	0;
	}

	if (string(argv[1]) == "-s")
		userChoice = SORTSELECT;

	if (string(argv[1]) == "-qs")
		userChoice = QUICKSELECT;

	if (string(argv[1]) == "-p")
		userChoice = PRINT;

	if (userChoice == NONE) {
		cout << "Error, invalid command line options." << endl;
		return	0;
	}

// ------------------------------
//  Command line args ok, display initial headers.

	cout << stars << endl;
	cout << "CS 302 - Assignment #1" << endl;
	cout << "Selection Problem Implementation." << endl;
	cout << endl << endl;

// ------------------------------
//  Read values from user.

	len = readVal(pmpt1, MAXNUMBERS);

	k = readVal(pmpt2, len);
	cout << endl << endl;

// ------------------------------
//  Generate random values.
//	dynamically creates array of required size.

	int * arr1 = new int[len];

	generateRandomValues(arr1, len);


// ------------------------------
//  Call select()
	switch (userChoice) {

		case PRINT:
			if (len < 1000) {
				selectionSort(arr1, 0, len-1);
				for (int i=0; i<len; i++) {
					cout << " " << arr1[i];
					if ((i+1)%5 == 0)
						cout << endl;
				}
				cout << endl;
			} else {
				cout << "I don't think so..." << endl;
			}
			break;

		case SORTSELECT:
			selectionSort(arr1, 0, len-1);
			cout << "Select: " << arr1[k]
				<< endl << endl;
			break;

		case QUICKSELECT:
			quickSelect(arr1, len, k);
			cout << "Quick Select: " << arr1[k]
				<< endl << endl;
			break;
	}

// ------------------------------
	return 0;
}

// *******************************************************************
//  Generate random values.
//	Default seeded rand() function is used, so will always
//	generate the same set of 'random' numbers.
//	Very useful for debugging...

void	generateRandomValues(int arr[], int max)
{
	for (int i=0; i<max; i++) {
		arr[i] = rand();
	}
}

// *******************************************************************
//  Basic routine read input from user.
//	prompt with passed string
//	read input
//	verify input is between 1 and max (inclusive)
//	if bad input, display error and re-prompt

int readVal(const string pmpt, const int max)
{
  int input;
  while(true) {
    cout << pmpt << endl;
    cin >> input;
    if(input < 1 || input > max) {
      cout << "Error, input cannot be less than 1 or greater than " << max << endl;
    } else {
      break;
		}
  }
}

// *******************************************************************
//  Standard selection sort algorithm.
//  Sorts ascending, small to large.

//	Note, indexes are passed which allow sorting
//	a subset of the array.
//	For full sort, 0 and len-1 are the correct indexes.

void selectionSort(int arr[], int b, int e)
{
  int iMin;
  for (int j=b; j<e; j++) {
    //find the min element in the unsorted arr[i..e]
    iMin = j;
    for( int i=j+1; i<e+1; i++) {
      if(arr[i] < arr[iMin]) {
        iMin = i;
      }
    }

    if(iMin != j) {
      swap(arr[j], arr[iMin]);
    }
  }
}

// *******************************************************************
//  Selection problem, method 2 -> Quick selection algorithm.
//  See text, Chapter 7, 7.7.6 (pg 323).
//  Note, helper function, just calls recursive quickSelect()

//	* Places the kth smallest item in arr[k-1]
//	* k is the desired rank in the comlpete array


void quickSelect(int arr[], int len, int k)
{
	quickSelect( arr, 0, len-1, k);
}

// -------------------------------------------------------------------
// Return median of left, center, and right.
//	Order these and hide the pivot.

int median3(int arr[], int left, int right)
{
	int center = ( left + right ) / 2;
	if( arr[center] < arr[left] )
		swap( arr[left], arr[center] );
	if( arr[right] < arr[left] )
		swap( arr[left], arr[right] );
	if( arr[right] < arr[center] )
		swap( arr[center], arr[right] );

	swap( arr[center], arr[right - 1] );
	return arr[right-1];
}

// -------------------------------------------------------------------
//  Barrsic recursive quick select fucntion.
//	NOTE, changes order to array elements.
//	Places the kth smallest item in arr[k-1]

//	* Uses median-of-three partitioning and a cutoff of 10
//	* left is the left-most index of the subarray
//	* right is the right-most index of the subarray
//	* k is the desired rank in the entire array.

void quickSelect(int arr[], int left, int right, int k)
{
	if(left + 10 <= right) {
		const int & pivot = median3(arr, left, right);
		//begin partition
		int i = left;
		int j = right-1;
		for( ; ; ) {
			while( arr[++i] < pivot ) {}
			while( pivot < arr[--j] ) {}
			if( i < j )
				swap( arr[i], arr[j] );
			else
				break;
		}

		swap( arr[i], arr[right-1] ); //restore pivot

		if( k <= i )
			quickSelect( arr, left, i-1, k);
		else if ( k > i + 1 )
			quickSelect( arr, i+1, right, k);
	}
	else
		selectionSort( arr, left, right );
}

// -------------------------------------------------------------------
//  Basic swap function (used by recursive quickselect).

void swap (int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}
