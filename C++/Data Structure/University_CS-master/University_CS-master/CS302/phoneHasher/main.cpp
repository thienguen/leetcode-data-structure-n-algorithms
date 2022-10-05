//  Main program for testing

#include <iostream>
#include <string>
#include <cstdlib>

#include "phoneHash.h"

using namespace std;

int main(int argc, char *argv[])
{

// *****************************************************************
//  Headers...

	string	stars, bars, dashes;
	stars.append(65, '*');
	bars.append(65, '=');
	dashes.append(40,'-');
	const char* bold   = "\033[1m";
	const char* unbold   = "\033[0m";
	bool	doPrint=false;

	cout << stars << endl << bold << "CS 302 - Assignment #8" << endl;
	cout << "Reverse Phone Number Lookup" << unbold << endl;
	cout << endl;

// ------------------------------------------------------------------
//  Check argument

	if (argc == 2)
		if (string(argv[1]) == "-p")
			doPrint = true;

// ------------------------------------------------------------------
//  Some very basic testing.
//	Order should match the handout.

	phoneHash	phNumSet;

	cout << bars << endl << "Initial Testing" << endl << endl;
	if (phNumSet.readPhonebook("data/test.dat")) {
		phNumSet.insert("702-895-1000", "Jorgensen, Ed");
		phNumSet.insert("555-895-5533", "Doofenshmirtz, Heinz");
		phNumSet.insert("555-895-9a33", "Doofenshmirtz, Vanesa");
		phNumSet.insert("555-8!5-9133", "Fletcher, Ferb");
		phNumSet.insert("555=895-7133", "Fletcher, Phineas");
		phNumSet.insert("555-895-913", "Fletcher, Phineas");
		phNumSet.insert("555-895-21123", "Fletcher, Candice");
		phNumSet.printPhonebook();
		cout << "Entries = " << phNumSet.entries() << endl;
		cout << "Table Size = " << phNumSet.getTablesize() << endl;
		cout << "Hash Test = " << phNumSet.showHash("555-895-5533") << endl;
		cout << "Hash Test = " << phNumSet.showHash("555-895-5532") << endl;
	}

	cout << endl;

// ------------------------------------------------------------------
//  Slightly more extensive testing.

	phoneHash	phNumSet0;

	cout << bars << endl << bold << "Test #0" << unbold << endl << endl;
	if (phNumSet0.readPhonebook("data/small.dat")) {
		if (doPrint)
			phNumSet0.printPhonebook();
		cout << "Entries = " << phNumSet0.entries() << endl;
		cout << "Table Size = " << phNumSet0.getTablesize() << endl;
		cout << "Hash Test = " << phNumSet0.showHash("555-895-5533") << endl;
		cout << "Hash Test = " << phNumSet0.showHash("555-895-5532") << endl;
	}
	cout << endl;

// ------------------------------------------------------------------

	phoneHash	phNumSet1;

	cout << bars << endl << bold << "Test #1" << unbold << endl << endl;
	if (phNumSet1.readPhonebook("data/twoHund.dat")) {
		if (doPrint)
			phNumSet1.printPhonebook();
		cout << "Entries = " << phNumSet1.entries() << endl;
		cout << "Table Size = " << phNumSet1.getTablesize() << endl;
		cout << "Hash Test = " << phNumSet1.showHash("555-895-5533") << endl;
		cout << "Hash Test = " << phNumSet1.showHash("555-895-5532") << endl;
	}
	cout << endl;

// ------------------------------------------------------------------
//  Five hundred numbers/names.
//	Requires expanding hash table once.

	phoneHash	phNumSet2;

	cout << bars << endl << bold << "Test #2" << unbold << endl << endl;
	if (phNumSet2.readPhonebook("data/fiveHund.dat")) {
		if (doPrint)
			phNumSet2.printPhonebook();
		cout << "Entries = " << phNumSet2.entries() << endl;
		cout << "Table Size = " << phNumSet2.getTablesize() << endl;
		cout << "Hash Test = " << phNumSet2.showHash("555-895-5533") << endl;
		cout << "Hash Test = " << phNumSet2.showHash("555-895-5532") << endl;
	}
	cout << endl;

// ------------------------------------------------------------------
//  Larger data set.
//	Requires expanding table twice.

	phoneHash	phNumSet3;

	cout << bars << endl << bold << "Test #3" << unbold << endl << endl;
	if (phNumSet3.readPhonebook("data/sevenHund.dat")) {
		if (doPrint)
			phNumSet3.printPhonebook();
		cout << "Entries = " << phNumSet3.entries() << endl;
		cout << "Table Size = " << phNumSet3.getTablesize() << endl;
		cout << "Hash Test = " << phNumSet3.showHash("555-895-5533") << endl;
		cout << "Hash Test = " << phNumSet3.showHash("555-895-5532") << endl;
	}
	cout << endl;

// ------------------------------------------------------------------
//  Larger data set.
//	Requires expanding table twice

	phoneHash	phNumSet4;

	cout << bars << endl << bold << "Test #4" << unbold << endl << endl;
	if (phNumSet4.readPhonebook("data/thou.dat")) {
		if (doPrint)
			phNumSet0.printPhonebook();
		cout << "Entries = " << phNumSet4.entries() << endl;
		cout << "Table Size = " << phNumSet4.getTablesize() << endl;
		cout << "Hash Test = " << phNumSet4.showHash("555-895-5533") << endl;
		cout << "Hash Test = " << phNumSet4.showHash("555-895-5532") << endl;
	}
	cout << endl;

// ------------------------------------------------------------------
//  Final test, largest data set.
//	Requires expanding hash table size four times.
//	Interactive option.

	phoneHash	phNumSet5;
	string		phNum, name="";

	cout << bars << endl << bold << "Test #5" << unbold << endl << endl;
	if (phNumSet5.readPhonebook("data/unlv.txt")) {
		if (doPrint)
			phNumSet5.printPhonebook();
		cout << "Entries = " << phNumSet5.entries() << endl;
		cout << "Table Size = " << phNumSet5.getTablesize() << endl;
		cout << "Hash Test = " << phNumSet5.showHash("555-895-5533") << endl;
		cout << "Hash Test = " << phNumSet5.showHash("555-895-5532") << endl;
	}

	cout << endl << dashes << endl << bold << "Reverse Lookup"
		<< unbold << endl;
	while (true) {
		cout << "Enter Phone Number (return to exit): ";
		getline(cin, phNum);
		if (phNum == "")
			break;
		name = phNumSet5.search(phNum);
		if (name == "")
			cout << "Number " << phNum << " not found." << endl;
		else
			cout << "Name: " << name << endl;
	}
	cout << endl << endl;

// *****************************************************************
//  All done.

	cout << stars << endl << "Game Over, thank you for playing." << endl;

	return 0;
}
