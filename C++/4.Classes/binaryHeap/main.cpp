//  Main program for testing

#include <iostream>
#include <string>
#include <cstdlib>

#include "binaryHeap.h"

using namespace std;

int main(int argc, char *argv[])
{

	// *****************************************************************
	//  Headers...

	string stars, bars, dashes;
	stars.append(65, '*');
	bars.append(65, '=');
	dashes.append(40, '-');
	const char *bold = "\033[1m";
	const char *unbold = "\033[0m";
	bool doPrint = false;

	int currPriority;
	string currName;

	cout << stars << endl
		 << bold << "CS 302 - Assignment #9" << endl;
	cout << "Binary Heap Job Scheduler" << unbold << endl;
	cout << endl;

	// ------------------------------------------------------------------
	//  Check argument

	if (argc == 2)
		if (string(argv[1]) == "-p")
			doPrint = true;

	// ------------------------------------------------------------------
	//  Initial testing, very small heap.
	//	Always prints...

	binaryHeap myHeap0;

	cout << endl
		 << bars << endl
		 << bold << "Test Set #0" << unbold << endl;

	myHeap0.insert("google", 1);
	myHeap0.insert("amazon", 2);
	myHeap0.insert("newegg", 3);
	myHeap0.insert("apple", 4);
	myHeap0.insert("dell", 5);
	myHeap0.insert("oracle", 6);
	myHeap0.insert("cisco", 7);
	myHeap0.insert("jupiter", 8);
	myHeap0.insert("belkin", 9);
	myHeap0.insert("ebay", 10);

	cout << dashes << endl
		 << "Job Heap (level order):" << endl;
	myHeap0.printJobHeap();

	cout << dashes << endl
		 << "Heap Size: " << myHeap0.entries() << endl;
	cout << "Job Priority Order:" << endl;
	while (!myHeap0.isEmpty())
	{
		myHeap0.deleteMax(currName, currPriority);
		cout << currName << "  " << currPriority << endl;
	}

	// ------------------------------------------------------------------
	//  Some very basic testing.

	binaryHeap myHeap1;

	cout << endl
		 << bars << endl
		 << bold << "Test Set #1" << unbold << endl;

	myHeap1.readJobs("jobs1.txt");

	if (doPrint)
	{
		cout << dashes << endl
			 << "Job Heap:" << endl;
		myHeap1.printJobHeap();
	}

	cout << dashes << endl
		 << "Heap Size: " << myHeap1.entries() << endl;
	cout << "Job Priority Order:" << endl;
	while (!myHeap1.isEmpty())
	{
		myHeap1.deleteMax(currName, currPriority);
		if (doPrint)
			cout << currName << "  " << currPriority << endl;
	}
	// ------------------------------------------------------------------
	//  Some very basic testing.

	binaryHeap myHeap2;

	cout << endl
		 << bars << endl
		 << bold << "Test Set #2" << unbold << endl;

	myHeap2.readJobs("jobs2.txt");

	if (doPrint)
	{
		cout << dashes << endl
			 << "Heap Size: " << myHeap2.entries() << endl;
		cout << "Top 10 Jobs:" << endl;
		for (int i = 0; i < 10; i++)
		{
			myHeap2.deleteMax(currName, currPriority);
			cout << currName << "  " << currPriority << endl;
		}
	}

	// ------------------------------------------------------------------
	//  Some very basic testing.

	binaryHeap myHeap3;

	cout << endl
		 << bars << endl
		 << bold << "Test Set #3" << unbold << endl;

	myHeap3.readJobs("jobs3.txt");
	myHeap3.insert("OverTheTop1", 1);
	myHeap3.insert("ReSizeMe", 25);
	myHeap3.insert("ForceHeapResize", 75);
	myHeap3.insert("JustOneMore", 100);
	myHeap3.insert("LastOne", 50);

	if (doPrint)
	{
		cout << dashes << endl;
		cout << "Original Heap Size: " << myHeap3.entries() << endl;
		cout << "Test #3, 50 jobs processed..." << endl;
		cout << "New Heap Size: " << myHeap3.entries() << endl;
	}

	for (int i = 0; i < 50; i++)
		myHeap3.deleteMax(currName, currPriority);

	if (doPrint)
	{
		cout << endl
			 << "Top 10 Jobs (after processing first 50):" << endl;
		for (int i = 0; i < 10; i++)
		{
			myHeap3.deleteMax(currName, currPriority);
			cout << currName << "  " << currPriority << endl;
		}
	}

	// ------------------------------------------------------------------
	//  Some very basic testing.

	binaryHeap myHeap4;

	cout << endl
		 << bars << endl
		 << bold << "Test Set #4" << unbold << endl;

	myHeap4.readJobs("jobs4.txt");

	if (doPrint)
	{
		cout << dashes << endl;
		cout << "Original Heap Size: " << myHeap4.entries() << endl;
		cout << "Test #4, 2000 jobs processed..." << endl;
		cout << "New Heap Size: " << myHeap4.entries() << endl;
	}

	for (int i = 0; i < 4000; i++)
		myHeap4.deleteMax(currName, currPriority);

	if (doPrint)
	{
		cout << endl
			 << "Top 10 Jobs (after processing first 4000):" << endl;
		for (int i = 0; i < 10; i++)
		{
			myHeap4.deleteMax(currName, currPriority);
			cout << currName << "  " << currPriority << endl;
		}
	}

	// *****************************************************************
	//  All done.

	cout << endl
		 << stars << endl
		 << "Game Over, thank you for playing." << endl;

	return 0;
}
