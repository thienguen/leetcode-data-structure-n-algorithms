//  CS 202 Provided Main
//  Uses various functions for linked lists (unordered)

#include <iostream>
#include "unorderedLinkedList.h"

using namespace std;

int main()
{
	// ----------------------------------------------------------------------
	//  Simple header.

	string bars;
	bars.append(70, '-');

	cout << endl;
	cout << "CS 202 - Assignment #9" << endl;
	cout << "Unordered Linked Lists" << endl
		 << endl;

	// ----------------------------------------------------------------------
	//  Initializations used on the following series of tests.

	int inums[] = {22, 34, 56, 4, 19, 2, 89, 90, 3, 14, 32,
				   88, 125, 56, 11, 43, 55};
	double dnums[] = {22.1, 34.5, 56.6, 4.3, 19.2, 2.5, 89.4,
					  90.8, 3.14, 14.3, 32.9, 88.1, 125.3, 56.7,
					  11.5, 43.8, 55.2};

	unorderedLinkedList<int> ilist1u;
	unorderedLinkedList<int> ilist2u;
	unorderedLinkedList<double> dlist3u;

	int ilen = (sizeof(inums) / sizeof(inums[0]));
	int iitem;

	int dlen = (sizeof(dnums) / sizeof(dnums[0]));
	double ditem;

	// ----------------------------------------------------------------------
	//  Test Set #1

	cout << bars << endl;
	cout << "List 1 - Integers" << endl
		 << endl;

	ilist1u.deleteNode(1); // will fail

	cout << endl
		 << "Insertions..." << endl;
	for (int i = 0; i < ilen; i++)
		ilist1u.insert(inums[i]);

	cout << "List 1 - Unordered: " << endl;
	ilist1u.print();
	cout << endl;

	cout << endl
		 << "List 1 Unordered, in reverse order: " << endl;
	ilist1u.reversePrint();
	cout << endl;

	ilist1u.deleteNode(73); // will fail

	// ----------------------------------------------------------------------
	//  Test Set #2

	cout << bars << endl;
	cout << "List 2 - Integers:" << endl
		 << endl;

	for (int i = 0; i < ilen; i++)
		ilist2u.insertLast(inums[i]);

	cout << "List 2 length: " << ilist2u.length() << endl;
	cout << "List 2 Unordered: " << endl;
	ilist2u.print();
	cout << endl
		 << endl;

	ilist2u.deleteNode(3);
	ilist2u.deleteNode(14);
	ilist2u.deleteNode(32);

	cout << endl
		 << "List 2 Unordered New Length: " << ilist2u.length() << endl;
	cout << "List 2 Unordered -> With nodes removed:  0  14  32" << endl;
	ilist2u.print();
	cout << endl
		 << endl;

	cout << "List 2 Unordered -> Search tests (for 14 and 90): " << endl;

	iitem = 14;
	if (ilist2u.search(iitem))
		cout << "List 2: item " << iitem << " was found." << endl;
	else
		cout << "List 2: item " << iitem << " was not found." << endl;

	iitem = 90;
	if (ilist2u.search(iitem))
		cout << "List 2: item " << iitem << " was found." << endl;
	else
		cout << "List 2: item " << iitem << " was not found." << endl;
	cout << endl;

	// ----------------------------------------------------------------------
	//  Test Set #3

	cout << bars << endl;
	cout << "List 3 - Doubles:" << endl
		 << endl;

	for (int i = 0; i < dlen; i++)
		dlist3u.insertLast(dnums[i]);

	// Unordered
	cout << "List 3 Unordered: " << endl;
	dlist3u.print();
	cout << endl
		 << endl;

	cout << "List 3 Unordered (reverse order): " << endl;
	dlist3u.reversePrint();
	cout << endl;

	cout << "List 3 Unordered -> Search tests (for 11.5 and 19.2): " << endl;

	ditem = 11.5;
	if (dlist3u.search(ditem))
		cout << "List 3: item " << ditem << " was found." << endl;
	else
		cout << "List 3: item " << ditem << " was not found." << endl;

	ditem = 19.2;
	if (dlist3u.search(iitem))
		cout << "List 3: item " << ditem << " was found." << endl;
	else
		cout << "List 3: item " << ditem << " was not found." << endl;
	cout << endl;

	// ----------------------------------------------------------------------
	//  Test Set #4

	cout << bars << endl;
	cout << "List 4 - Doubles:" << endl
		 << endl;

	{
		unorderedLinkedList<double> dlist4u(dlist3u);

		// Unordered tests...
		cout << "List 4 Unordered (original list): " << endl;
		dlist4u.print();
		cout << endl
			 << endl;

		cout << "List 4 Unordered Delete Testing..." << endl;
		dlist4u.deleteNode(55.2);
		dlist4u.deleteNode(34.0);
		dlist4u.deleteNode(43.8);
		dlist4u.deleteNode(22.1);
		dlist4u.deleteNode(3.14);
		dlist4u.deleteNode(34.5);
		cout << endl;

		cout << "List 4 Unordered (modified): " << endl;
		dlist4u.print();
		cout << endl
			 << endl;

		cout << "List 4 Unordered - first item: ";
		cout << dlist4u.front() << endl;

		cout << "List 4 Unordered - last item: ";
		cout << dlist4u.back() << endl
			 << endl;
	}

	// ----------------------------------------------------------------------
	//  Test Set #5

	cout << bars << endl;
	cout << "List 5 - Short's (0-4):" << endl
		 << endl;

	unorderedLinkedList<short> ilist5u;

	if (ilist5u.isEmptyList())
		cout << "List is initially empty, adding 4, 3, 2, 1 and 0."
			 << endl
			 << endl;

	for (int i = 4; i >= 0; i--)
		ilist5u.insertLast(i);

	// unordered
	cout << "List 5 Unordered: " << endl;
	ilist5u.print();
	cout << endl
		 << endl;

	cout << "List 5 Unordered - first item: ";
	cout << ilist5u.front() << endl;

	cout << "List 5 Unordered - last item: ";
	cout << ilist5u.back() << endl;

	// ----------------------------------------------------------------------
	//  Test Set #6

	unorderedLinkedList<short> ilist6u(ilist5u);
	unorderedLinkedList<short> ilist7u(ilist5u);

	cout << bars << endl;
	cout << "Lists 6 and 7 - Even Short's (2-20)" << endl;
	cout << "Copy of list 5 with 5, 6, 7, 8, and 9 added." << endl
		 << endl;

	for (int i = 5; i < 10; i++)
	{
		ilist6u.insertLast(i);
		ilist7u.insertLast(i);
	}

	// unordered
	cout << "List 6 Unordered (length=" << ilist6u.length() << ") : ";
	ilist6u.print();
	cout << endl;
	cout << "List 7 Unordered (length=" << ilist7u.length() << ") : ";
	ilist7u.print();
	cout << endl
		 << endl;

	cout << "Destroying List 6 Unordered..." << endl;
	ilist6u.destroyList();
	cout << "List 6 Unordered (should be empty): ";
	ilist6u.print();
	cout << endl
		 << endl;

	cout << "Initializing List 7 Unordered..." << endl;
	ilist7u.initializeList();
	cout << "List 7 Unordered (should be empty): " << endl;
	ilist7u.print();
	cout << endl
		 << endl;

	// ----------------------------------------------------------------------
	//  Testing with strings.

	unorderedLinkedList<string> slistu;

	string words[] = {"enters", "green", "in", "a", "jumps", "big",
					  "familiar", "dog", "hills"};
	int sLen = sizeof(words) / sizeof(string);

	cout << bars << endl;
	cout << "String List:" << endl
		 << endl;

	if (slistu.isEmptyList())
		cout << "String List is initially empty, adding words..."
			 << endl
			 << endl;

	for (int i = 0; i < sLen; i++)
		slistu.insert(words[i]);

	// unordered
	cout << "String List Unordered: " << endl;
	slistu.print();
	cout << endl
		 << endl;

	cout << "String List Unordered - first item: ";
	cout << slistu.front() << endl;

	cout << "String List Unordered - last item: ";
	cout << slistu.back() << endl;

	slistu.destroyList();

	if (slistu.isEmptyList())
		cout << endl
			 << "String List Unordered is now empty." << endl;
	cout << endl;

	// ----------------------------------------------------------------------
	//  Done, end the program.

	cout << bars << endl;
	cout << endl
		 << "Game Over, thank you for playing." << endl
		 << endl;

	return EXIT_SUCCESS;
}
