//  Main program for testing

#include <iostream>
#include <string>
#include <cstdlib>

#include "graphAlgorithms.h"

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

	cout << stars << endl << bold << "CS 302 - Assignment #11" << endl;
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

	graphAlgorithms	badGraph1(-1);
	graphAlgorithms	badGraph2(3);
	graphAlgorithms	badGraph3(10);

	badGraph3.newGraph(-2);
	badGraph3.newGraph(2);
	badGraph3.newGraph(20);
	badGraph3.addEdge(11, -11, 100);
	badGraph3.addEdge(51, 11, 100);
	badGraph3.addEdge(-11, 11, 100);
	badGraph3.addEdge(3, 3, 10);
	badGraph3.addEdge(5, 7, 100);		// ok
	badGraph3.setTitle("Unused Example");

	if (badGraph3.getTitle() != "Unused Example")
		cout << "main: title functions do not work." << endl;

	cout << endl;
	badGraph2.topoSort();

	cout << endl;
	badGraph2.printMatrix();

	cout << endl;
	badGraph2.dijkstra(0);

	cout << endl;
	badGraph3.dijkstra(40);

	cout << endl;

// ------------------------------------------------------------------
//  Create graph form quiz

	cout << bars << endl;
	cout << "Simple Example Graph: " << endl << endl;

	graphAlgorithms	myGraph1;
	string	gFile1 = "graph1.txt";

	if (myGraph1.readGraph(gFile1)) {
		if (doPrint) {
			myGraph1.printMatrix();
			myGraph1.topoSort();
			myGraph1.dijkstra(0);
		}
	} else {
		cout << "main: Error reading " << gFile1 << "." << endl;
	}

	if (!doPrint)
		cout << "  Simple Example Completed." << endl;

	cout << endl;

// ------------------------------------------------------------------
//  Create simple unweighted graph to test topo sort
//	uses example, fig 9.4, from text.

	cout << bars << endl;
	cout << "Topo Sort Graph (unweighted): " << endl << endl;

	graphAlgorithms	myGraph2;
	string	gFile2 = "graph2.txt";

	if (myGraph2.readGraph(gFile2)) {
		if (doPrint) {
			myGraph2.printMatrix();
			myGraph2.topoSort();
			myGraph2.dijkstra(0);
		}
	} else {
		cout << "main: Error reading " << gFile2 << "." << endl;
	}

	if (!doPrint)
		cout << "  Topo Sort Graph (unweighted) Completed." << endl;

	cout << endl;

// ------------------------------------------------------------------
//  Create graph (weighted)

	cout << bars << endl;
	cout << "Test Graph: " << endl << endl;

	graphAlgorithms	myGraph3;
	string	gFile3 = "graph3.txt";

	if (myGraph3.readGraph(gFile3)) {
		if (doPrint) {
			myGraph3.printMatrix();
			myGraph3.topoSort();
			myGraph3.dijkstra(0);
		}
	} else {
		cout << "main: Error reading " << gFile3 << "." << endl;
	}

	if (!doPrint)
		cout << "  Test Graph Completed." << endl;

	cout << endl;

// ------------------------------------------------------------------
//  Create graph (weighted)

	cout << bars << endl;
	cout << "Larger Test Graph: " << endl << endl;

	graphAlgorithms	myGraph4;
	string	gFile4 = "graph4.txt";

	if (myGraph4.readGraph(gFile4)) {
		if (doPrint) {
			myGraph4.printMatrix();
			myGraph4.topoSort();
			myGraph4.dijkstra(0);
		}
	} else {
		cout << "main: Error reading " << gFile4 << "." << endl;
	}

	if (!doPrint)
		cout << "  Larger Test Graph Completed." << endl;

	cout << endl;

// *****************************************************************
//  All done.

	cout << endl << stars << endl <<
		"Game Over, thank you for playing." << endl;

	return 0;
}

