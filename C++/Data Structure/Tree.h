#ifndef TREE_H
#define TREE_H
#include <iostream>

template <typename T>
class Tree
{
    class TreeNode
    {
    public:
        T data;
        TreeNode *leftChild = nullptr;
        TreeNode *rightChild = nullptr;
        TreeNode(T _data) : data(_data){};
    };

    TreeNode *root = nullptr; // root of the tree
public:
    Tree() {}

    Tree(const Tree<T> &tree)
    { // copy constructor
        copyNodesBelow(tree.root, root);
    }

    Tree<T> &operator=(const Tree<T> &other)
    { // assignment operator
        if (&other != this)
        {
            deleteNodesBelow(root);
            copyNodesBelow(other.root, root);
        }
        return *this;
    }
    ~Tree()
    { // destructor
        deleteNodesBelow(root);
    }
    void add(T newData)
    { // add data to the tree
        insertBelow(newData, root);
    }
    void print()
    { // print nodes in increasing order
        printBelow(root);
    }
    
private:
    // copy the data below the specifies node into new nodes
    void copyNodesBelow(const TreeNode *oldNode, TreeNode *&newNode)
    {
        if (oldNode == nullptr)
            return;
        newNode = new TreeNode(oldNode->data);                    // copy current node
        copyNodesBelow(oldNode->leftChild, newNode->leftChild);   // copy left subtree
        copyNodesBelow(oldNode->rightChild, newNode->rightChild); // copy right subtree
    }

    // delete the nodes below the specified node
    void deleteNodesBelow(TreeNode *&n)
    {
        if (n == nullptr)
            return;
        deleteNodesBelow(n->leftChild);  // delete left subtree
        deleteNodesBelow(n->rightChild); // delete right subtree
        delete n;                        // delete current node
        n = nullptr;
    }
    // insert a new node below the specified node
    void insertBelow(T newData, TreeNode *&n)
    {
        // we have found a leaf of the tree, add new node here
        if (n == nullptr)
            n = new TreeNode(newData);
        // If newData has smaller value than n, look in the left subtree
        else if (n->data > newData)
            insertBelow(newData, n->leftChild);
        // Otherwise, look in the right subtree
        else
            insertBelow(newData, n->rightChild);
    }
    // print data below the specified node
    void printBelow(TreeNode *&n)
    {
        if (n == nullptr)
            return;
        printBelow(n->leftChild);    // print left subtree
        std::cout << n->data << " "; // print current node
        printBelow(n->rightChild);   // print right subtree
    }
};

#endif