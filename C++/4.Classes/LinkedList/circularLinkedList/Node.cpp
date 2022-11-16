#include "Node.h"
#include <iostream>

Node::Node(int data, Node *next_node) : data(data), next_node(next_node)
{
    std::cout << "\nNew node is created with data : " << data << "\n";
}

Node::~Node()
{
    std::cout << "\nNode with data " << data << " is destroyed";
}