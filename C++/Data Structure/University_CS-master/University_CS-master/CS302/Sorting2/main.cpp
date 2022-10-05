//  CS 302
//  Provided Main Program

//  Sorting algorithms

//  Implements:
//	bubble sort
//	selection sort
//	quick sort

// ***********************************************************************
//  Includes and prototypes.

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

void	generateRandomValues(int [], int);
void	selectionSort(int [], int, int);
void	swap(int &, int &);
void	bubbleSort(int [], int);
void	quickSort(int [], int);
void	quickSort(int [], int, int);
int	median3(int [], int, int);
bool	verifySorted(int [], int);


// *******************************************************************

int main(int argc, char *argv[])
{
// ------------------------------
//  Declarations and headers.

	const	int	MAXNUMBERS=5000000;

	enum	algorithmOption { SELECTION, QUICK, BUBBLE, NONE };
	string	stars, bars;
	stringstream ss;
	bool	showNumbers=false;

	stars.append(60,'*');
	bars.append(50,'=');

	int	length;

	algorithmOption	userChoice = NONE;

// ------------------------------
//  Verify command line arguments.
//	Error out if bad, select user selection if good.

	if (argc == 1) {
		cout << "Usage: sorts <-ss|-qs|-rs|-p> -n <count>" << endl;
		return 0;
	}

	if (argc < 4 || argc > 5) {
		cout << "Error, invalid command line options." << endl;
		return	0;
	}

	if (string(argv[1]) == "-ss")
		userChoice = SELECTION;

	if (string(argv[1]) == "-qs")
		userChoice = QUICK;

	if (string(argv[1]) == "-bs")
		userChoice = BUBBLE;

	if (userChoice == NONE) {
		cout << "Error, invalid sort option." << endl;
		return	0;
	}

	if (string(argv[2]) != "-n") {
		cout << "Error, invalid count specifier." << endl;
		return	0;
	}

	if (string(argv[2]) != "-n") {
		cout << "Error, invalid count specifier." << endl;
		return	0;
	}

	if (string(argv[3]) != "") {
		ss << argv[3];
		ss >> length;
	}

	if (argc == 5)
		if (string(argv[4]) == "-p")
			showNumbers = true;


// ------------------------------
//  Command line args ok, display initial headers.

	cout << stars << endl;
	cout << "CS 302 - Assignment #3" << endl;
	cout << "Sorting Algorithms Implementation." << endl;
	cout << endl << endl;

// ------------------------------
//  Generate random values.
//	dynamically creates array of required size.

	int * myArr = new int[length];

	generateRandomValues(myArr, length);


// ------------------------------
//  Call select()

	switch (userChoice) {

		case BUBBLE:
			bubbleSort(myArr, length);
			break;

		case SELECTION:
			selectionSort(myArr, 0, length-1);
			break;

		case QUICK:
			quickSort(myArr, length);
			break;
	}

// ------------------------------
//  Verify sort worked correctly...

	if (!verifySorted(myArr, length)) {
		cout << "Error, epic sort fail." << endl;
		cout << "Do not pass go, do not collect score." << endl;
	}

// ------------------------------

	if (showNumbers) {
		if (length < 1000) {
			for (int i=0; i<length; i++) {
				cout << " " << myArr[i];
				if ((i+1)%5 == 0)
					cout << endl;
			}
			cout << endl;
		} else {
			cout << "Printing, I don't think so..." << endl;
		}
	}

// ------------------------------

	return 0;
}

// *******************************************************************
//  Simple routine to verify array is sorted.

bool	verifySorted(int arr[], int len)
{
	for (int i=1; i<len; i++)
		if (arr[i-1] > arr[i])
			return false;

	return true;
}

// *******************************************************************
//  Generate random values.
//	Default seeded rand() function is used, so will always
//	generate the same set of 'random' numbers.
//	Very useful for debugging...

void	generateRandomValues(int arr[], int max)
{
	for (int i=0; i<max; i++)
		arr[i] = rand() % 1000;
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
//  Standard quick sort algorithm.
//  Sorts ascending, small to large.

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

void quickSort(int arr[], int len)
{
	quickSort(arr, 0, len-1);
}

// -------------------------------------------------------------------

void quickSort(int arr[], int left, int right)
{
  if( left + 10 <= right ) {
    const int& pivot = median3(arr, left, right);

    //begin partition
    int i = left, j = right - 1;
    for( ;; ) {
      while( arr[++i] < pivot) {}
      while( pivot < arr[--j] ) {}
      if( i < j )
        swap(arr[i], arr[j]);
      else
        break;
    }

    swap( arr[i], arr[right-1] );

    quickSort(arr, left, i-1);
    quickSort(arr, i+1, right);
  }
  else
    selectionSort(arr, left, right);
}

// *******************************************************************
//  Standard bubble sort algorithm.

void bubbleSort(int arr[], int n)
{
  bool swapped = true;
  int j=0;
	while( swapped ) {
		swapped = false;
		j++;
		for( int i = 0; i < n - j; i++) {
			if( arr[i] > arr[i+1]) {
				swap(arr[i], arr[i+1]);
				swapped=true;
			}
		}
	}
}

void swap (int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
