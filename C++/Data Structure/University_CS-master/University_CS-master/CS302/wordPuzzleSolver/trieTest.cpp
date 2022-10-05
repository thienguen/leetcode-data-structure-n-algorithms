//  Main program for testing

#include <iostream>
#include <string>
#include <cstdlib>

#include "trieTree.h"

using namespace std;

int main()
{

// *****************************************************************
//  Headers...

	string	bars, stars;
	bars.append(30, '-');
	stars.append(65, '*');

	cout << stars << endl << "CS 302 - Assignment #6" << endl;
	cout << endl;

// *****************************************************************
//  Test Trie

	trieTree	myTree0;
	string	words0[10] = {"the", "a", "there", "answer", "any",
				"by", "bye", "their", "ball", "balloon" };
	int	len0 = 10;

	cout << bars << endl << "Test Set #0  (" << len0 << ")"
			<< endl << endl;

	for (int i=0; i<len0; i++)
		myTree0.insert(words0[i]);

	for (int i=0; i<len0; i++)
		if (!myTree0.search(words0[i]))
		cout << "main: Error, word "" " << words0[i]
			<< " "" is lost." << endl;

	cout << "Max Height: " << myTree0.height() << endl;
	cout << "Node Count: " << myTree0.countNodes() << endl;

//	cout << "Tree: " << endl;
//	myTree0.printTree();
	cout << endl;

// *****************************************************************

	trieTree	myTree1;
	string	words1[50] = {"aah", "aahed", "aahing", "aahs", "aal",
			"aalii", "aaliis", "aals", "aardvark",
			"aardwolf", "aargh", "aarrgh", "aarrghh", "aas",
			"aasvogel", "ab", "aba", "abaca", "abacas",
			"abaci", "aback", "abacus", "abacuses", "abaft",
			"abaka", "abakas", "abalone", "abalones", "abamp",
			"abampere", "abamps", "abandon", "abandons",
			"abapical", "abas", "abase", "abased", "abasedly",
			"abaser", "abasers", "abases", "abash", "abashed",
			"abashes", "abashing", "abasia", "abasias",
			"abasing", "abatable", "abate" };
	int	len1 = 50;

	cout << bars << endl << "Test Set #1  (" << len1 << ")"
			<< endl << endl;

	for (int i=0; i<len1; i++)
		myTree1.insert(words1[i]);

	for (int i=0; i<len1; i++)
		if (!myTree1.search(words1[i]))
		cout << "main: Error, word "" " << words1[i]
			<< " "" is lost." << endl;

	cout << "Max Height: " << myTree1.height() << endl;
	cout << "Node Count: " << myTree1.countNodes() << endl;

//	cout << "Tree: " << endl;
//	myTree1.printTree();
	cout << endl;

// *****************************************************************
//  Duplicates should be ignored...

	trieTree	myTree2;
	string	words2[25] = { "a", "ab", "ac", "ad", "ae",
				"af", "aba", "abb", "abc", "abd",
				"abe", "abf", "abaa", "abab", "abac",
				"abad", "abae", "abaf", "abaa", "abab",
				"a", "ab", "ac", "ad", "ae" };
	int	len2 = 25;

	cout << bars << endl << "Test Set #2  (" << len2 << ")"
			<< endl << endl;

	for (int i=0; i<len2; i++)
		myTree2.insert(words2[i]);

	for (int i=0; i<len2; i++)
		if (!myTree2.search(words2[i]))
		cout << "main: Error, word "" " << words2[i]
			<< " "" is lost." << endl;

	cout << "Max Height: " << myTree2.height() << endl;
	cout << "Node Count: " << myTree2.countNodes() << endl;

//	cout << "Tree: " << endl;
//	myTree2.printTree();
	cout << endl;

// *****************************************************************
//  Test for height...

	trieTree	myTree3;
	string	words3[30] = { "a", "aa", "aaa", "aaaa", "aaaaa",
				"aaaaaa",
				"aaaaaaa",
				"aaaaaaaa",
				"aaaaaaaaa",
				"aaaaaaaaaa",
				"aaaaaaaaaaa",
				"aaaaaaaaaaaa",
				"aaaaaaaaaaaaa",
				"aaaaaaaaaaaaaa",
				"aaaaaaaaaaaaaaa",
				"aaaaaaaaaaaaaaaa",
				"aaaaaaaaaaaaaaaaa",
				"aaaaaaaaaaaaaaaaaa",
				"aaaaaaaaaaaaaaaaaaa",
				"aaaaaaaaaaaaaaaaaaaa",
				"aaaaaaaaaaaaaaaaaaaaa",
				"aaaaaaaaaaaaaaaaaaaaaa",
				"aaaaaaaaaaaaaaaaaaaaaaa",
				"aaaaaaaaaaaaaaaaaaaaaaaa",
				"aaaaaaaaaaaaaaaaaaaaaaaaa",
				"aaaaaaaaaaaaaaaaaaaaaaaaaa",
				"aaaaaaaaaaaaaaaaaaaaaaaaaaa",
				"aaaaaaaaaaaaaaaaaaaaaaaaaaaa",
				"aaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
				"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" };
	int	len3 = 30;

	cout << bars << endl << "Test Set #3  (" << len3 << ")"
			<< endl << endl;

	for (int i=0; i<len3; i++)
		myTree3.insert(words3[i]);

	for (int i=0; i<len3; i++)
		if (!myTree3.search(words3[i]))
		cout << "main: Error, word "" " << words3[i]
			<< " "" is lost." << endl;

	cout << "Max Height: " << myTree3.height() << endl;
	cout << "Node Count: " << myTree3.countNodes() << endl;

//	cout << "Tree: " << endl;
//	myTree3.printTree();
	cout << endl;

// *****************************************************************
//  All done.

	cout << bars << endl << "Game Over, thank you for playing." << endl;

	return 0;
}
