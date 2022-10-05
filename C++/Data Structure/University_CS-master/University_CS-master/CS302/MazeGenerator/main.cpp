//  Main program for testing

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

#include "mazeGen.h"

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

	cout << stars << endl << bold << "CS 302 - Assignment #10" << endl;
	cout << "Maze Generator" << unbold << endl;
	cout << endl;

// ------------------------------------------------------------------
//  Check argument

	if (argc == 2)
		if (string(argv[1]) == "-p")
			doPrint = true;

// ------------------------------------------------------------------
//  Basic error testing...
	int	r, c;

	mazeGen	testMaze1(3, 3);
	testMaze1.getSize(r, c);
	if (r != 5 || c != 5)
		cout << "main: Error, test maze size incorrect." << endl;

	mazeGen	testMaze2(3, -3);
	testMaze2.getSize(r, c);
	if (r != 5 || c != 5)
		cout << "main: Error, test maze size incorrect." << endl;

	{	mazeGen	testMaze3;
		testMaze3.getSize(r, c);
		if (r != 5 || c != 5)
			cout << "main: Error, test maze size incorrect." << endl;
	}

// ------------------------------------------------------------------
//  Initial testing on some small mazes

	mazeGen	smallMaze0(5,5);
	fName = "mazeFile0.txt";

	smallMaze0.generate();

	if (smallMaze0.printMazeData(fName))
		cout << "Maze file " << fName << " created." << endl;
	else
		cout << "Error creating " << fName << "." << endl;

	if (doPrint) {
		cout << dashes << endl << "Small Maze:" << endl << endl;
		smallMaze0.printMazeText();
		cout << endl << dashes << endl;
	}
	
	mazeGen	smallMaze1(5,15);
	fName = "mazeFile1.txt";

	smallMaze1.generate();

	if (smallMaze1.printMazeData(fName))
		cout << "Maze file " << fName << " created." << endl;
	else
		cout << "Error creating " << fName << "." << endl;

	if (doPrint) {
		cout << dashes << endl << "Small Maze:" << endl << endl;
		smallMaze1.printMazeText();
		cout << endl << dashes << endl;
	}

	mazeGen	smallMaze2(15,5);
	fName = "mazeFile2.txt";

	smallMaze2.generate();

	if (smallMaze2.printMazeData(fName))
		cout << "Maze file " << fName << " created." << endl;
	else
		cout << "Error creating " << fName << "." << endl;

	if (doPrint) {
		cout << dashes << endl << "Small Maze:" << endl << endl;
		smallMaze2.printMazeText();
		cout << endl << dashes << endl;
	}

// -----------------
//  Fairly big maze

	mazeGen	bigMaze(50,100);
	fName = "mazeFile3.txt";

	bigMaze.generate();
	if (bigMaze.printMazeData(fName))
		cout << "Maze file " << fName << " created." << endl;
	else
		cout << "Error creating " << fName << "." << endl;

// -----------------
//  Really big maze.

	mazeGen	bigMaze2(500,700);
	fName = "mazeFile4.txt";

	bigMaze2.generate();
	if (bigMaze2.printMazeData(fName))
		cout << "Maze file " << fName << " created." << endl;
	else
		cout << "Error creating " << fName << "." << endl;

// -----------------
//  Super big maze.

	mazeGen	bigMaze3(1000,1500);
	fName = "mazeFile5.txt";

	bigMaze3.generate();
	if (bigMaze3.printMazeData(fName))
		cout << "Maze file " << fName << " created." << endl;
	else
		cout << "Error creating " << fName << "." << endl;

// *****************************************************************
//  All done.

	cout << endl << stars << endl <<
		"Game Over, thank you for playing." << endl;

	return 0;
}
