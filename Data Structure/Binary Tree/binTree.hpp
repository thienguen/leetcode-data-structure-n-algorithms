/// @brief Assignment 5
/// Header file for Binary Search Tree
#ifndef BINTREE_H_
#define BINTREE_H_

#include <iostream>
#include <vector>

// node
struct visibilityType
{
	int id;
	bool camera;
	bool seen;

	bool operator==(int x)
	{
		return id == x;
	}
};

// binary tree class
template <typename T>
class binTree
{
	struct binTreeNode
	{
		T data;
		binTreeNode *left;
		binTreeNode *right;
	};

private:
	binTreeNode *root;

public:
	class binTreeIterator
	{
	public:
		friend class binTree;
		binTreeIterator();
		binTreeIterator(binTreeNode *);
		binTreeIterator leftChild() const;
		binTreeIterator rightChild() const;
		T &operator*() const;
		bool operator==(const binTreeIterator &) const;
		bool operator!=(const binTreeIterator &) const;

	private:
		binTreeNode *binTreeNodePointer;
	};

	/* Default */
	~binTree();
	binTree();
	binTree(const binTree<T> &);

	/*  */
	void buildTree(std::vector<T>);
	const binTree &operator=(const binTree<T> &);
	binTreeIterator rootIterator() const;

private:
	void destroyTree(binTreeNode *);
	void copyTree(binTreeNode *, binTreeNode *);
	void buildTree(std::vector<T>, binTreeNode *, int);
};

///---------------------------------------
/// binTree() Constructor
/// Called when object is instantiated
/// Sets root to nullptr
///---------------------------------------
template <typename T>
binTree<T>::binTree()
{
	root = nullptr;
}

///---------------------------------------
/// Copy Constructor
/// @param binTree tree to copy
/// Creates a deep copy of a binTree object
///---------------------------------------
template <typename T>
binTree<T>::binTree(const binTree<T> &rhs)
{
	// allocates new node
	root = new binTreeNode;
	root->data = rhs.root->data;

	// sets left and right pointers to nullptr
	// done to nullify zombie values
	root->left = nullptr;
	root->right = nullptr;

	// copies subtrees recursively
	copyTree(root, rhs.root);
}

///---------------------------------------
/// Assignment Operator Overlaod
/// @param binTree binTree to copy
/// @return Instantiated object with rhs's values
/// Creates a deep copy of a binTree object
///---------------------------------------
template <typename T>
const binTree<T> &binTree<T>::operator=(const binTree<T> &rhs)
{
	// we need an empty tree
	// destroy if theres stuff
	if (root != nullptr)
	{
		destroyTree(root);
	}

	// same as copy constructor
	root = new binTreeNode;
	root->data = rhs.root->data;
	root->left = nullptr;
	root->right = nullptr;

	copyTree(root, rhs.root);

	return *this;
}

///---------------------------------------
/// Destructor
/// Called when object goes out of scope
///---------------------------------------
template <typename T>
binTree<T>::~binTree()
{
	destroyTree(root);
}

///---------------------------------------
/// func: buildTree()
/// @param vector values of nodes
/// Constructs a tree out of values of vector
///---------------------------------------
template <typename T>
void binTree<T>::buildTree(std::vector<T> treeValues)
{
	if (root != nullptr)
		destroyTree(root);

	auto *node = new binTreeNode;
	node->data = treeValues[0];
	node->left = nullptr;
	node->right = nullptr;
	root = node;

	buildTree(treeValues, root, 0);
}

///---------------------------------------
/// func: buildTree()
/// @param vector values of nodes
/// @param binTreeNode current node
/// @param int current index
/// Constructs right and left subtrees of current node
///---------------------------------------
template <typename T>
void binTree<T>::buildTree(std::vector<T> treeValues, binTreeNode *r, int index)
{
	if (index > treeValues.size() - 1)
		return;
	// calculate left and right indexes
	// base case: end of vector reached
	int leftIndex = 2 * index + 1;
	int rightIndex = 2 * (index + 1);

	if (leftIndex > treeValues.size() - 1)
		return;

	// if value is -1, no subtree in that direction
	if (treeValues[leftIndex] == -1)
	{
		r->left = nullptr;
	}
	else
	{
		r->left = new binTreeNode;
		r->left->data = treeValues[leftIndex];
		r->left->left = nullptr;
		r->left->right = nullptr;
		buildTree(treeValues, r->left, leftIndex);
	}

	if (rightIndex > treeValues.size() - 1)
		return;

	if (treeValues[rightIndex] == -1)
	{
		r->right = nullptr;
	}
	else
	{
		r->right = new binTreeNode;
		r->right->data = treeValues[rightIndex];
		r->right->left = nullptr;
		r->right->right = nullptr;
		buildTree(treeValues, r->right, rightIndex);
	}
}

///---------------------------------------
/// func: destroyTree()
/// @param binTreeNode root node to tree to destroy
/// @note code yoinked from class discord
/// Creates a new node at the head with value rhs
///---------------------------------------
// note: code yoinked from class discord
template <typename T>
void binTree<T>::destroyTree(binTreeNode *r)
{
	if (r != nullptr)
	{
		destroyTree(r->left);
		destroyTree(r->right);

		delete r;
		r = nullptr;
	}
}

///---------------------------------------
/// func: copyTree()
/// @param binTreeNode current node
/// @param binTreeNode current node to copy
/// copies j left and right
///---------------------------------------
template <typename T>
void binTree<T>::copyTree(binTreeNode *i, binTreeNode *j)
{
	if (j->left != nullptr)
	{
		auto lnode = new binTreeNode;
		lnode->data = j->left->data;
		lnode->left = nullptr;
		lnode->right = nullptr;
		i->left = lnode;
		copyTree(i->left, j->left);
	}

	if (j->right != nullptr)
	{
		auto rnode = new binTreeNode;
		rnode->data = j->right->data;
		rnode->left = nullptr;
		rnode->right = nullptr;
		i->right = rnode;
		copyTree(i->right, j->right);
	}
}

///---------------------------------------
/// func: rootIterator()
/// returns iterator object with pointer pointing to root
///---------------------------------------
template <typename T>
typename binTree<T>::binTreeIterator binTree<T>::rootIterator() const
{
	return binTree<T>::binTreeIterator(root);
}

//------------//
// iterator	  //
//------------//

///---------------------------------------
/// binTreeIterator() Constructor
/// Creates binTreeIterator object and sets iterator's member pointer to nullptr
///---------------------------------------
template <typename T>
binTree<T>::binTreeIterator::binTreeIterator()
{
	this->binTreeNodePointer = nullptr;
}

///---------------------------------------
/// binTreeIterator() Copy Constructor
/// @param binTreeNode ptr to set iterator object
/// sCreates binTreeIterator object and sets iterator's member pointer to ptr
///---------------------------------------
template <typename T>
binTree<T>::binTreeIterator::binTreeIterator(binTreeNode *ptr)
{
	this->binTreeNodePointer = ptr;
}

///---------------------------------------
/// func: leftChild()
/// @return binTreeIterator
/// returns left subtree of current pointer;
///---------------------------------------
template <typename T>
typename binTree<T>::binTreeIterator binTree<T>::binTreeIterator::leftChild() const
{
	return binTreeNodePointer->left;
}

///---------------------------------------
/// func: rightChild()
/// @return binTreeIterator
/// returns right subtree of current pointer;
///---------------------------------------
template <typename T>
typename binTree<T>::binTreeIterator binTree<T>::binTreeIterator::rightChild() const
{
	return binTreeNodePointer->right;
}

///---------------------------------------
/// Dereference Operator Overload
/// @return data
/// returns data contained in node
///---------------------------------------
template <typename T>
T &binTree<T>::binTreeIterator::operator*() const
{
	return this->binTreeNodePointer->data;
}

///---------------------------------------
/// Equivalence Operator Overload
/// @return bool
/// returns true if rhs is equal to this
///---------------------------------------
template <typename T>
bool binTree<T>::binTreeIterator::operator==(const binTree<T>::binTreeIterator &rhs) const
{
	return this->binTreeNodePointer == rhs.binTreeNodePointer;
}

///---------------------------------------
/// Inequivalence Operator Overload
/// @return bool
/// returns true if rhs is not equal to this
///---------------------------------------
template <typename T>
bool binTree<T>::binTreeIterator::operator!=(const binTree<T>::binTreeIterator &rhs) const
{
	return this->binTreeNodePointer != rhs.binTreeNodePointer;
}

#endif // BINTREE_H_
