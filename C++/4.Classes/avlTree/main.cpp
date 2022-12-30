//  Main program for testing
#include <iostream>
#include <fstream>
#include <string>
#include "avlTree.hpp"

using namespace std;

int main()
{

// *****************************************************************
//  Headers...

	string	bars, stars;
	bars.append(65, '-');
	stars.append(65, '*');

	cout << bars << endl << "CS 302 - Assignment #5" << endl;
	cout << endl;

// *****************************************************************
/*  Test Tree:
			         10
			     /      \
			    6       14
			   / \     /  \
			  5   8   11  18

	Results:
	In-order traversal:
	5  6  8  10  11  14  18

	Pre-order traversal:
	10  6  5  8  14  11  18

	Post-order traversal:
	5  8  6  11  18  14  10

	BFS traversal:
	10
	6 14
	5 8 11 18
*/

	avlTree<int> myTree0;

	int	arr0[] = { 10, 6, 14, 5, 8, 11, 18 };
	int	len0 = sizeof(arr0) / sizeof(arr0[1]);

	for (int i=0; i<len0; i++)
		myTree0.insert(arr0[i]);

	cout << bars << endl << "Test Set #0" << endl;
	cout << "\tNodes:  " << myTree0.countNodes() << endl;
	cout << "\tHeight: " << myTree0.height() << endl << endl;

	cout << "In-order traversal: " << endl;
	myTree0.printTree(INORDER);
	cout << endl;

	cout << "Pre-order traversal: " << endl;
	myTree0.printTree(PREORDER);
	cout << endl;

	cout << "Post-order traversal: " << endl;
	myTree0.printTree(POSTORDER);
	cout << endl;

	cout << "BFS traversal: " << endl;
	myTree0.printTree(LEVELORDER);
	cout << endl;

	if (!myTree0.search(5))
		cout << "main: search error" << endl;
	if (!myTree0.search(14))
		cout << "main: search error" << endl;
	if (myTree0.search(42))
		cout << "main: search error" << endl;

	myTree0.destroyTree();
	myTree0.printTree(LEVELORDER);

	if (myTree0.search(5))
		cout << "main: destroy tree error" << endl;
	if (myTree0.search(14))
		cout << "main: destroy tree error" << endl;


// *****************************************************************

/*  Test Tree:

Results:
	In-order traversal:
	1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16
		17  18  19  20  21  22  23  24

	Pre-order traversal:
	16  8  4  2  1  3  6  5  7  12  10  9  11  14
		13  15  20  18  17  19  22  21  23  24

	Post-order traversal:
	1  3  2  5  7  6  4  9  11  10  13  15  14  12
		8  17  19  18  21  24  23  22  20  16

	BFS traversal:
	16
	8 20
	4 12 18 22
	2 6 10 14 17 19 21 23
	1 3 5 7 9 11 13 15 24
*/

	avlTree<int>	myTree1;
	for (int i=1; i<=24; i++)
		myTree1.insert(i);

	cout << bars << endl << "Test Set #1" << endl;
	cout << "\tNodes:  " << myTree1.countNodes() << endl;
	cout << "\tHeight: " << myTree1.height() << endl << endl;

	cout << "In-order traversal: " << endl;
	myTree1.printTree(INORDER);
	cout << endl;

	cout << "Pre-order traversal: " << endl;
	myTree1.printTree(PREORDER);
	cout << endl;

	cout << "Post-order traversal: " << endl;
	myTree1.printTree(POSTORDER);
	cout << endl;

	cout << "BFS traversal: " << endl;
	myTree1.printTree(LEVELORDER);
	cout << endl;

	myTree1.deleteNode(5);

	cout << "BFS traversal: " << endl;
	myTree1.printTree(LEVELORDER);
	cout << endl;

	if (myTree1.search(5))
		cout << "main: search error, 5" << endl;
	if (!myTree1.search(14))
		cout << "main: search error, 14" << endl;
	if (myTree1.search(42))
		cout << "main: search error, 42" << endl;


// *****************************************************************
//  Test Tree:

	avlTree<int>	myTree2;

	int	arr2[] = { 44, 17, 88, 32, 65, 97, 28, 54, 82,
				29, 76, 80, 3, 11, 21 };
	int	len2 = sizeof(arr2) / sizeof(arr2[1]);

	for (int i=0; i<len2; i++)
		myTree2.insert(arr2[i]);

	cout << bars << endl << "Test Set #2" << endl;
	cout << "\tNodes:  " << myTree2.countNodes() << endl;
	cout << "\tHeight: " << myTree2.height() << endl << endl;

	cout << "In-order traversal: " << endl;
	myTree2.printTree(INORDER);
	cout << endl;

	cout << "Pre-order traversal: " << endl;
	myTree2.printTree(PREORDER);
	cout << endl;

	cout << "Post-order traversal: " << endl;
	myTree2.printTree(POSTORDER);
	cout << endl;

	cout << "BFS traversal: " << endl;
	myTree2.printTree(LEVELORDER);
	cout << endl;

	myTree2.deleteNode(5);		// does not exist
	myTree2.deleteNode(78);		// does not exist
	myTree2.deleteNode(28);

	myTree2.printTree(LEVELORDER);

	myTree2.deleteNode(17);
	myTree2.deleteNode(65);
	myTree2.deleteNode(82);

	cout << endl << "Modified Tree:" << endl;
	cout << "\tNodes:  " << myTree2.countNodes() << endl;
	cout << "\tHeight: " << myTree2.height() << endl << endl;

	cout << "BFS traversal: " << endl;
	myTree2.printTree(LEVELORDER);
	cout << endl;

	if (myTree2.search(78))
		cout << "main: search error, 78" << endl;
	if (myTree2.search(28))
		cout << "main: search error, 28" << endl;
	if (myTree2.search(17))
		cout << "main: search error, 17" << endl;
	if (myTree2.search(65))
		cout << "main: search error, 65" << endl;
	if (myTree2.search(82))
		cout << "main: search error, 82" << endl;
	if (!myTree2.search(44))
		cout << "main: search error, 44" << endl;
	if (!myTree2.search(97))
		cout << "main: search error, 97" << endl;

// *****************************************************************
//  Large Test Tree

	avlTree<int>	myTree3;

	for (int i=1; i<10000; i+=2)
		myTree3.insert(i);

	cout << bars << endl << "Test Set #3" << endl;
	cout << "\tNodes:  " << myTree3.countNodes() << endl;
	cout << "\tHeight: " << myTree3.height() << endl << endl;

	// Too much to print...
	cout << "BFS traversal: " << endl;
	myTree3.printTree(LEVELORDER);
	cout << endl;

	for (int i=29; i<9955; i+=2)
		myTree3.deleteNode(i);

	cout << endl << "Modified Tree:" << endl;
	cout << "\tNodes:  " << myTree3.countNodes() << endl;
	cout << "\tHeight: " << myTree3.height() << endl << endl;

	cout << "BFS traversal: " << endl;
	myTree3.printTree(LEVELORDER);
	cout << endl;

	myTree3.destroyTree();
	myTree3.printTree(LEVELORDER);

	if (myTree0.search(15))
		cout << "main: destroy tree error" << endl;
	if (myTree0.search(9955))
		cout << "main: destroy tree error" << endl;

// *****************************************************************
//  All done.

	cout << bars << endl << "Game Over, thank you for playing." << endl;

	return 0;
}
