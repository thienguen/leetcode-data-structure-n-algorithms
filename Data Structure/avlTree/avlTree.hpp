#pragma once

#include <math.h>
#include <iostream>

template <typename T>
struct Node
{
	T keyValue;
	int nodeHeight;
	Node<T> *left;
	Node<T> *right;
};

enum OPTIONS
{
	INORDER,
	PREORDER,
	POSTORDER,
	LEVELORDER,
	NONE
};

template <typename T>
class avlTree
{
public:
	avlTree<T>();
	~avlTree<T>();
	int countNodes() const;
	int height() const;
	bool search(T) const;
	void destroyTree();
	void printTree(OPTIONS) const;
	void insert(T);
	void deleteNode(T);

protected:
	int countNodes(Node<T> *) const;
	int height(Node<T> *) const;
	int getBalance(Node<T> *) const;
	void destroyTree(Node<T> *&);
	void printTree(Node<T> *, OPTIONS) const;
	void printGivenLevel(Node<T> *, int) const;
	Node<T> *search(T, Node<T> *) const;
	Node<T> *insert(T, Node<T> *);
	Node<T> *rightRotate(Node<T> *);
	Node<T> *leftRotate(Node<T> *);
	Node<T> *deleteNode(T, Node<T> *);
	Node<T> *minValueNode(Node<T> *) const;

private:
	Node<T> *root;
};

template <typename T>
avlTree<T>::avlTree()
{
	root = nullptr;
}

template <typename T>
avlTree<T>::~avlTree<T>()
{
	destroyTree(root);
}

template <typename T>
int avlTree<T>::countNodes() const
{
	return countNodes(root);
}

template <typename T>
void avlTree<T>::destroyTree()
{
	destroyTree(root);
}

template <typename T>
int avlTree<T>::height() const
{
	return height(root);
}

template <typename T>
bool avlTree<T>::search(T key) const
{
	Node<T> *result = search(key, root);
	if (result == nullptr)
		return false;
	return true;
}

template <typename T>
void avlTree<T>::printTree(OPTIONS options) const
{
	printTree(root, options);
}

template <typename T>
void avlTree<T>::insert(T nodeValue)
{
	root = insert(nodeValue, root);
}

template <typename T>
void avlTree<T>::deleteNode(T nodeValue)
{
	Node<T> *find = search(nodeValue, root);
	if (find != nullptr)
		root = deleteNode(nodeValue, root);
}

template <typename T>
void avlTree<T>::destroyTree(Node<T> *&node)
{
	if (node != nullptr)
	{
		destroyTree(node->left);
		destroyTree(node->right);
		delete node;
	}
	node = nullptr;
}

template <typename T>
int avlTree<T>::countNodes(Node<T> *node) const
{
	if (node == nullptr)
		return 0;
	return 1 + countNodes(node->left) + countNodes(node->right);
}

template <typename T>
int avlTree<T>::height(Node<T> *node) const
{
	if (node == nullptr)
		return 0;

	// if tree is not empty height is 1 + max of either path
	return 1 + std::max(height(node->left), height(node->right));
}

template <typename T>
Node<T> *avlTree<T>::search(T key, Node<T> *node) const
{
	if (node == nullptr)
		return nullptr;
	else if (key < node->keyValue)
		return search(key, node->left);
	else if (key > node->keyValue)
		return search(key, node->right);
	else
		return node;
}

template <typename T>
void avlTree<T>::printTree(Node<T> *node, OPTIONS options) const
{
	if (node == nullptr)
		return;

	switch (options)
	{
	case INORDER:
		printTree(node->left, options);
		std::cout << node->keyValue << " ";
		printTree(node->right, options);
		break;
	case PREORDER:
		std::cout << node->keyValue << " ";
		printTree(node->left, options);
		printTree(node->right, options);
		break;
	case POSTORDER:
		printTree(node->left, options);
		printTree(node->right, options);
		std::cout << node->keyValue << " ";
		break;
	case LEVELORDER:
		for (int i = 1; i <= height(node); i++)
		{
			printGivenLevel(node, i);
			std::cout << "\n";
		}
		break;
	case NONE:
		return;
	}
}

template <typename T>
void avlTree<T>::printGivenLevel(Node<T> *node, int level) const
{
	if (node == nullptr)
		return;

	if (level == 1)
	{
		std::cout << node->keyValue << " ";
	}
	else if (level > 1)
	{
		printGivenLevel(node->left, level - 1);
		printGivenLevel(node->right, level - 1);
	}
}

template <typename T>
Node<T> *avlTree<T>::insert(T key, Node<T> *node)
{
	if (node == nullptr)
	{
		Node<T> *newNode = new Node<T>;
		newNode->left = nullptr;
		newNode->right = nullptr;
		newNode->keyValue = key;
		return newNode;
	}
	else if (key < node->keyValue)
	{
		node->left = insert(key, node->left);
	}
	else if (key > node->keyValue)
	{
		node->right = insert(key, node->right);
	}

	if (node != nullptr)
	{
		if (height(node->left) - height(node->right) > 1)
		{
			if (height(node->left->left) >= height(node->left->right))
			{
				node = leftRotate(node);
			}
			else
			{
				node->left = rightRotate(node->left);
				node = leftRotate(node);
			}
		}
		else if (height(node->right) - height(node->left) > 1)
		{
			if (height(node->right->right) >= height(node->right->left))
			{
				node = rightRotate(node);
			}
			else
			{
				node->right = leftRotate(node->right);
				node = rightRotate(node);
			}
		}

		// * update height of node
		node->nodeHeight = std::max(height(node->left), height(node->right)) + 1;
	}

	return node;
}

template <typename T>
Node<T> *avlTree<T>::leftRotate(Node<T> *node)
{
	Node<T> *otherNode;

	otherNode = node->left;
	node->left = otherNode->right;
	otherNode->right = node;

	node->nodeHeight = std::max(height(node->left), height(node->right)) + 1;
	otherNode->nodeHeight = std::max(height(otherNode->left), height(otherNode->right)) + 1;

	node = otherNode;

	return node;
}

template <typename T>
Node<T> *avlTree<T>::rightRotate(Node<T> *node)
{
	Node<T> *otherNode;

	otherNode = node->right;
	node->right = otherNode->left;
	otherNode->left = node;

	node->nodeHeight = std::max(height(node->left), height(node->right)) + 1;
	otherNode->nodeHeight = std::max(height(otherNode->left), height(otherNode->right)) + 1;

	node = otherNode;

	return node;
}

template <typename T>
int avlTree<T>::getBalance(Node<T> *node) const
{
	if (node == nullptr)
	{
		return 0;
	}
	int lh = height(node->left);
	int rh = height(node->right);

	return lh - rh;
}

template <typename T>
Node<T> *avlTree<T>::deleteNode(T key, Node<T> *node)
{
	if (node == nullptr)
		return node;

	if (key < node->keyValue)
		node->left = deleteNode(key, node->left);
	else if (key > node->keyValue)
		node->right = deleteNode(key, node->right);
	else
	{
		if ((node->left == nullptr) || (node->right == nullptr))
		{
			Node<T> *oldNode = (node->left != nullptr) ? node->left : node->right;

			if (oldNode == nullptr)
			{
				oldNode = node;
				node = nullptr;
			}
			else
				*node = *oldNode;

			delete oldNode;
		}
		else
		{
			Node<T> *oldNode = minValueNode(node->right);

			node->keyValue = oldNode->keyValue;

			node->right = deleteNode(oldNode->keyValue, node->right);
		}
	}

	if (node == nullptr)
		return node;

	if (height(node->left) - height(node->right) > 1)
	{
		if (height(node->left->left) >= height(node->left->right))
		{
			node = leftRotate(node);
		}
		else
		{
			node->left = rightRotate(node->left);
			node = leftRotate(node);
		}
	}
	else if (height(node->right) - height(node->left) > 1)
	{
		if (height(node->right->right) >= height(node->right->left))
		{
			node = rightRotate(node);
		}
		else
		{
			node->right = leftRotate(node->right);
			node = rightRotate(node);
		}
	}
	// update height of node
	node->nodeHeight = std::max(height(node->left), height(node->right)) + 1;

	return node;
}

template <typename T>
Node<T> *avlTree<T>::minValueNode(Node<T> *node) const
{
	Node<T> *current = node;

	while (current->left != nullptr)
		current = current->left;

	return current;
}
