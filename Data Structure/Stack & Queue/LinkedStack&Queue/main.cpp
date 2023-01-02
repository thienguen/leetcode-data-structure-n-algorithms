//  Main program for testing
//	Test the stack and queue implementations

#include <iostream>
#include <fstream>
#include <string>
#include "Lstack.h"
#include "Lqueue.h"

using namespace std;

int main()
{
	// *****************************************************************
	//  Headers...

	string bars, stars;
	bars.append(65, '-');
	stars.append(65, '*');

	cout << bars << endl
		 << "CS 302 - Assignment #4" << endl;
	cout << "Basic Testing for Linked Stacks and "
		 << "Queues Data Structures" << endl;

	// *****************************************************************
	//  Test basic queue operations.
	//	Create some integer queues, add items, delete items,
	//	display queues, etc...

	cout << endl
		 << stars << endl
		 << "Test Queue Operations "
		 << "- Integers:" << endl
		 << endl;

	linkedQueue<int> queue0, queue1;
	linkedQueue<int> queue2;
	int j;

	for (int i = 1; i <= 20; i++)
		queue0.addItem(i);

	cout << "Queue 0 (original): ";
	queue0.printQueue();
	cout << endl;
	cout << "Queue 0 (count): " << queue0.queueCount();
	cout << endl
		 << endl;

	for (int i = 1; i <= 20; i += 2)
	{
		j = queue0.front();
		queue0.deleteItem();
		queue1.addItem(j);
		j = queue0.front();
		queue0.deleteItem();
		queue2.addItem(j);
	}

	cout << "Queue 1 (odds):     ";
	queue1.printQueue();
	cout << endl;
	cout << "Queue 1 (count): " << queue1.queueCount();
	cout << endl
		 << endl;

	cout << "Queue 2 (evens):    ";
	queue2.printQueue();
	cout << endl;
	cout << "Queue 2 (count): " << queue2.queueCount();
	cout << endl
		 << endl;

	// --------------------------------------
	//  Floating point tests
	//	Create some queues for floating point items.

	cout << bars << endl
		 << "Test Queue Operations "
		 << "- Floats:" << endl
		 << endl;

	linkedQueue<double> queue3;

	for (int i = 1; i <= 7; i++)
		queue3.addItem(static_cast<double>(i) + 0.5);

	cout << "Queue 3 (floats, original): ";
	queue3.printQueue();
	cout << endl;

	cout << "Queue 3 (floats, modified): ";
	queue3.printQueue();
	cout << endl
		 << endl;

	cout << "Queue 3 (count): " << queue3.queueCount();
	cout << endl;
	cout << "Queue 3 (first item): " << queue3.front();
	cout << endl;
	cout << "Queue 3 (last item): " << queue3.back();
	cout << endl
		 << endl;

	// --------------------------------------
	//  Many entries testing

	cout << bars << endl
		 << "Test Queue Operations "
		 << "- Many Items:" << endl
		 << endl;
	bool worked = true;

	linkedQueue<int> queue4;
	int testSize = 400000;

	for (int i = 1; i <= testSize; i++)
	{
		queue4.addItem(i);
	}

	if (queue4.queueCount() != testSize)
		cout << "main: error, incorrect queue size." << endl;

	for (int i = 1; i <= testSize; i++)
	{
		if (queue4.front() != i)
		{
			std::cout << queue4.front() << "," << i << endl;
			worked = false;
		}
		queue4.deleteItem();
	}
	if (queue4.queueCount() != 0)
	{
		worked = false;
		std::cout << queue4.queueCount() << endl;
	}

	if (worked)
		cout << "Many items, test passed." << endl;
	else
		cout << "Many items, test failed." << endl;

	cout << endl;

	// *****************************************************************
	//  Basic tests for linked stack implementation.
	//	Reservse number in a list by pushing each item on stack and then poping.

	cout << endl
		 << stars << endl
		 << "Test Stack Operations "
			"- Reversing:"
		 << endl
		 << endl;

	// ---------------------
	//  Integers

	linkedStack<int> istack;
	int inums[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
	int ilen = (sizeof(inums) / sizeof(inums[0]));

	istack.initializeStack();
	linkedStack<int> istackA;

	cout << "Original List:     ";
	for (int i = 0; i < ilen; i++)
	{
		istack.push(inums[i]);
		cout << inums[i] << " ";
	}

	cout << endl
		 << "Reverse List:      ";
	for (int i = 0; i < ilen; i++)
	{
		cout << istack.top() << " ";
		istackA.push(istack.top());
		istack.pop();
	}

	cout << endl
		 << "Copy A (original): ";
	for (int i = 0; i < ilen; i++)
	{
		cout << istackA.top() << " ";
		istackA.pop();
	}

	cout << endl
		 << endl;

	// ---------------------
	//  Doubles
	//	Create some stacks for doubles.

	linkedStack<double> dstack;
	linkedStack<double> dstackA;

	double dnums[] = {1.1, 3.3, 5.5, 7.7, 9.9, 11.11, 13.13, 15.15};
	int dlen = (sizeof(dnums) / sizeof(dnums[0]));

	dstack.push(1000.0);
	dstack.initializeStack();

	cout << bars << endl
		 << "Test Stack Operations "
		 << "- Doubles:" << endl
		 << endl;

	cout << "Original List:     ";
	for (int i = 0; i < dlen; i++)
	{
		dstack.push(dnums[i]);
		cout << dnums[i] << " ";
	}

	cout << endl
		 << "Reverse List:      ";
	for (int i = 0; i < dlen; i++)
	{
		cout << dstack.top() << " ";
		dstackA.push(dstack.top());
		dstack.pop();
	}

	cout << endl
		 << "Copy A (original): ";
	for (int i = 0; i < dlen; i++)
	{
		cout << dstackA.top() << " ";
		dstackA.pop();
	}

	cout << endl
		 << endl;

	// --------------------------------------
	//  Many entries testing

	cout << bars << endl
		 << "Test Stack Operations "
		 << "- Many Items:" << endl
		 << endl;
	bool workedStk = true;

	linkedStack<int> iStackBig;
	int testSize2 = 400000;

	for (int i = 1; i <= testSize2; i++)
	{
		iStackBig.push(i);
	}

	if (iStackBig.stackCount() != testSize2)
		cout << "main: error, incorrect queue size." << endl;

	for (int i = testSize2; i > 0; i--)
	{
		if (iStackBig.top() != i)
		{
			workedStk = false;
		}
		iStackBig.pop();
	}

	if (iStackBig.stackCount() != 0)
	{
		workedStk = false;
	}

	if (workedStk)
		cout << "Many items, test passed." << endl;
	else
		cout << "Many items, test failed." << endl;

	cout << endl;

	// *****************************************************************
	//  All done.

	cout << bars << endl
		 << "Game Over, thank you for playing." << endl;

	return 0;
}
