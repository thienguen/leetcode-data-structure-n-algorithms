#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>

template <typename T>
class BinarySearchTree
{
public:
    // EFFECTS:  Constructs an empty BST.
    BinarySearchTree();

    // EFFECTS:  Constructs a copy of the given tree.
    BinarySearchTree(const BinarySearchTree &other);

    // EFFECTS:  Replaces the contents of this tree with a copy of the
    //           given tree.
    BinarySearchTree &operator=(const BinarySearchTree &other);

    // EFFECTS:  Destructs this tree.
    ~BinarySearchTree();

    // EFFECTS:  Returns whether this tree is empty.
    bool empty() const;

    // EFFECTS:  Returns the number of elements in this tree.
    int size() const;

    // EFFECTS:  Returns whether the given item is contained in this
    //           tree.
    bool contains(const T &value) const;

    // REQUIRES: value is not in this tree
    // EFFECTS:  Inserts the given item into this tree.
    void insert(const T &value);

    // REQUIRES: value, and the damn node
    // EFFECTS:  Insert the exact location in the tree
    void insert(const T &value, BinarySearchTree &node);

    // REQUIRES: value is in this tree
    // EFFECTS:  Removes the given item from this tree.
    void remove(const T &value);

    /// REQUIRES: value is in this tree, and the damn node
    // EFFECTS:  Removes the given item from this tree.
    void remove(const T &value, BinarySearchTree &node);

    // EFFECTS:  Prints the contents of this tree.
    void print() const;

    // EFFECTS:  Prints the contents of this tree, from this nodedown
    void print(BinarySearchTree &node) const;

    // EFFECTS:  Prints the contents of this tree.
    void print(BinarySearchTree &node, int level) const;

    /// REQUIRES: Node to be copy and the damn node
    // EFFECTS:  Copies the contents of this tree from the node given to down
    void copy(BinarySearchTree &other, BinarySearchTree &node);

private:
    // Represents a single node of a tree.
    struct Node
    {
        T data;
        Node *left;
        Node *right;
        // INVARIANTS: left and right are either null or pointers to
        //             valid Nodes
        Node(const T &data) : data(data), left(nullptr), right(nullptr) {}
    };

    // The root node of this tree.
    Node *root;
    // INVARIANTS: root is either null or a pointer to a valid Node
};

/// ---------------------- Implementation ---------------------- ///
/// ---------------------- Implementation ---------------------- ///
/// ---------------------- Implementation ---------------------- ///

/// @tparam T
/// EFFECT: Default constructor
template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr){};

/// @tparam T
/// EFFECT: Copy constructor
/// @param other
template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree &other) : root(nullptr)
{
    /// TODO: Copy the contents of the other tree into this tree.

}

/// @tparam T
/// EFFECT: Destructor
template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    if (root != nullptr)
    {
        std::vector<Node *> nodes;
        nodes.push_back(root);
        while (!nodes.empty())
        {
            Node *node = nodes.back();
            nodes.pop_back();
            if (node->left != nullptr)
            {
                nodes.push_back(node->left);
            }
            if (node->right != nullptr)
            {
                nodes.push_back(node->right);
            }
            delete node;
        }
    }
}

/// @tparam T
/// EFFECT: Copy assignment operator
/// @return
template <typename T>
int BinarySearchTree<T>::size() const
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + size(root->left) + size(root->right);
    }
}

/// @tparam T
/// EFFECT:
/// @return
template <typename T>
bool BinarySearchTree<T>::empty() const
{
    return (root == nullptr);
}

/// @tparam T
/// @param value
/// @return returns whether the given item is contained in this
template <typename T>
bool BinarySearchTree<T>::contains(const T &value) const
{
    Node *current = root;
    while (current != nullptr)
    {
        if (value == current->data)
        {
            return true;
        }
        else if (value < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    return false;
}

/// @tparam T
/// EFFECT: insert a new node into the tree
/// @param value
template <typename T>
void BinarySearchTree<T>::insert(const T &value)
{
    if (root == nullptr)
    {
        root = new Node;
        root->data = value;
        root->left = nullptr;
        root->right = nullptr;
    }
    else
    {
        insert(value, root);
    }
}

/// @tparam T
/// EFFECT: Copy the data below the specifies node into newNodes
/// @param other
/// @param node
template <typename T>
void BinarySearchTree<T>::copy(BinarySearchTree &other, BinarySearchTree &node)
{
    // Recursive call to copy the left side of the tree
    // return back where we left off, preorder.
    if (node == nullptr)
        return;
    else
    {
        // first copy the data from the node
        other.insert(node->data);

        // then recur to the left side of the subtree
        copy(other, node->left);

        // then recur to the right side of the subtree
        copy(other, node->right);
    }
}


template <typename T>
void BinarySearchTree<T>::print() const
{
    if (root != nullptr)
    {
        std::cout << root->data << std::endl;
        print(root->left);
        print(root->right);
    }
}

template <typename T>
void BinarySearchTree<T>::print(BinarySearchTree &node) const
{
    if (node != nullptr)
    {
        std::cout << node->data << std::endl;
        print(node->left);
        print(node->right);
    }
}












#endif


