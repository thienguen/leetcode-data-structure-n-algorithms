//  Main program for testing

#include <iostream>
#include <string>
#include <cstdlib>

#include "graphMST.h"

using namespace std;

int main(int argc, char *argv[])
{

// *****************************************************************
//  Headers...

	string	stars, bars, dashes;
	string	fName;
	stars.append(65, '*');
	bars.append(65, '=');
	dashes.append(40,'-');
	const char* bold   = "\033[1m";
	const char* unbold   = "\033[0m";
	bool	doPrint=false;

	cout << stars << endl << bold << "CS 302 - Assignment #12" << endl;
	cout << "Graph Algorithms" << unbold << endl;
	cout << endl;

// ------------------------------------------------------------------
//  Check argument

	if (argc == 2)
		if (string(argv[1]) == "-p")
			doPrint = true;

// ------------------------------------------------------------------
//  Basic error testing...

	cout << bars << endl;
	cout << "Error testing: " << endl << endl;

	graphMST	myGraphErr;

	if (myGraphErr.readEdges("noFile.txt"))
		cout << "Error, readEdges() read non-existing file." << endl;

	if (myGraphErr.readEdges("graphErr1.txt"))
		cout << "Error, readEdges() read invalid file." << endl;

	if (myGraphErr.readEdges("graphErr2.txt"))
		cout << "Error, readEdges() read invalid file." << endl;

	cout << endl;

// ------------------------------------------------------------------
//  Simple graph

	cout << bars << endl;
	cout << "Simple Graph: " << endl << endl;

	graphMST	myGraph1;
	string	gFile1 = "graph1.txt";

	if (myGraph1.readEdges(gFile1)) {
		if (doPrint) {
			myGraph1.printEdges();
			myGraph1.kruskals();
			myGraph1.printMST();
		}
	} else {
		cout << "main: Error reading " << gFile1 << "." << endl;
	}

	if (!doPrint)
		cout << "  Simple Test Graph Completed." << endl;

	cout << endl;

// ------------------------------------------------------------------
//  Simple graph 2

	cout << bars << endl;
	cout << "Simple Graph 2: " << endl << endl;

	graphMST	myGraph2;
	string	gFile2 = "graph2.txt";

	if (myGraph2.readEdges(gFile2)) {
		if (doPrint) {
			myGraph2.printEdges();
			myGraph2.kruskals();
			myGraph2.printMST();
		}
	} else {
		cout << "main: Error reading " << gFile2 << "." << endl;
	}

	if (!doPrint)
		cout << "  Simple Test Graph 2 Completed." << endl;

	cout << endl;

// ------------------------------------------------------------------
//  Graph 3

	cout << bars << endl;
	cout << "Test Graph 3: " << endl << endl;

	graphMST	myGraph3;
	string	gFile3 = "graph3.txt";

	if (myGraph3.readEdges(gFile3)) {
		if (doPrint) {
			myGraph3.printEdges();
			myGraph3.kruskals();
			myGraph3.printMST();
		}
	} else {
		cout << "main: Error reading " << gFile3 << "." << endl;
	}

	if (!doPrint)
		cout << "  Test Graph 3 Completed." << endl;

	cout << endl;

// ------------------------------------------------------------------
//  Graph 4

	cout << bars << endl;
	cout << "Graph 4: " << endl << endl;

	graphMST	myGraph4;
	string	gFile4 = "graph4.txt";

	if (myGraph4.readEdges(gFile3)) {
		if (doPrint) {
			myGraph4.printEdges();
			myGraph4.kruskals();
			myGraph4.printMST();
		}
	} else {
		cout << "main: Error reading " << gFile4 << "." << endl;
	}

	if (!doPrint)
		cout << "  Test Graph 4 Completed." << endl;

	cout << endl;

// ------------------------------------------------------------------
//  Graph 5

	cout << bars << endl;
	cout << "Test Graph 5: " << endl << endl;

	graphMST	myGraph5;
	string	gFile5 = "graph5.txt";

	if (myGraph5.readEdges(gFile5)) {
		if (doPrint) {
			myGraph5.printEdges();
			myGraph5.kruskals();
			myGraph5.printMST();
		}
	} else {
		cout << "main: Error reading " << gFile5 << "." << endl;
	}

	if (!doPrint)
		cout << "  Test Graph 5 Completed." << endl;

	cout << endl;

// *****************************************************************
//  All done.

	cout << endl << stars << endl <<
		"Game Over, thank you for playing." << endl;

	return 0;
}

