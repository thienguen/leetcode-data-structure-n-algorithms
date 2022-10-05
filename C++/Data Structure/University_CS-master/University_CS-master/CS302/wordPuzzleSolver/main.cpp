//  Main program for testing

#include <iostream>
#include <string>
#include <cstdlib>

#include "wordPuzzle.h"

using namespace std;

int main()
{

// *****************************************************************
//  Headers...

	string	bars, stars;
	bars.append(65, '-');
	stars.append(65, '*');

	cout << bars << endl << "CS 302 - Assignment #6" << endl;
	cout << "Word Search Puzzle Solver" << endl;
	cout << endl;

// ------------------------------------------------------------------

	wordPuzzle	pzl1;
	if (!pzl1.readDictionary("smallDictionary.txt")) {
		cout << "main: Read dictionary error." << endl;
		exit(1);
	}
	if (!pzl1.readLetters("words1.txt")) {
		cout << "main: Read letters file error." << endl;
		exit(1);
	}

	cout << bars << endl;
	pzl1.showTitle();
	cout << endl;
	pzl1.printLetters();

	pzl1.findWords();
	pzl1.showWords();

	cout << endl;
	cout << "Stats:" << endl;
	pzl1.showWordCount();
	cout << "Trie Max Height: " << pzl1.height() << endl;
	cout << "Trie Node Count: " << pzl1.countNodes() << endl;
	cout << endl;

	cout << sizeof(trieNodeType) * pzl1.countNodes() << endl;
	char c;
	cin >> c;
	pzl1.destroyTree();

// ------------------------------------------------------------------
{
	wordPuzzle	pzl2;

	if (!pzl2.readDictionary("dictionary.txt")) {
		cout << "main: Read dictionary error." << endl;
		exit(1);
	}

	if (!pzl2.readLetters("words2.txt")) {
		cout << "main: Read letters file error." << endl;
		exit(1);
	}

	cout << bars << endl;
	pzl2.showTitle();
	cout << endl;
	pzl2.printLetters();

	pzl2.findWords();
	pzl2.showWords();

	cout << endl;
	cout << "Stats:" << endl;
	pzl2.showWordCount();
	cout << "Trie Max Height: " << pzl2.height() << endl;
	cout << "Trie Node Count: " << pzl2.countNodes() << endl;
	cout << endl;
}

// ------------------------------------------------------------------

	wordPuzzle	pzl3;

	if (!pzl3.readDictionary("dictionary.txt")) {
		cout << "main: Read dictionary error." << endl;
		exit(1);
	}

	if (!pzl3.readLetters("words3.txt")) {
		cout << "main: Read letters file error." << endl;
		exit(1);
	}

	cout << bars << endl;
	pzl3.showTitle();
	cout << endl;
	pzl3.printLetters();

	pzl3.findWords();
	pzl3.showWords();

	cout << endl;
	cout << "Stats:" << endl;
	pzl3.showWordCount();
	cout << "Trie Max Height: " << pzl3.height() << endl;
	cout << "Trie Node Count: " << pzl3.countNodes() << endl;
	cout << endl;

// ------------------------------------------------------------------

	wordPuzzle	pzl4;

	if (!pzl4.readDictionary("dictionary.txt")) {
		cout << "main: Read dictionary error." << endl;
		exit(1);
	}

	if (!pzl4.readLetters("words4.txt")) {
		cout << "main: Read letters file error." << endl;
		exit(1);
	}

	cout << bars << endl;
	pzl4.showTitle();
	cout << endl;
	pzl4.printLetters();

	pzl4.findWords();
	pzl4.showWords();

	cout << endl;
	cout << "Stats:" << endl;
	pzl4.showWordCount();
	cout << "Trie Max Height: " << pzl4.height() << endl;
	cout << "Trie Node Count: " << pzl4.countNodes() << endl;
	cout << endl;

// ------------------------------------------------------------------

	wordPuzzle	pzl5;

	if (!pzl5.readDictionary("dictionary.txt")) {
		cout << "main: Read dictionary error." << endl;
		exit(1);
	}

	if (!pzl5.readLetters("words5.txt")) {
		cout << "main: Read letters file error." << endl;
		exit(1);
	}

	cout << bars << endl;
	pzl5.showTitle();
	cout << endl;
	cout << "  ...standby..." << endl;

	pzl5.findWords();

	cout << endl;
	cout << "Stats:" << endl;
	pzl5.showWordCount();
	cout << endl;

// *****************************************************************
//  All done.
	cout << bars << endl << "Game Over, thank you for playing." << endl;

	return 0;
}
