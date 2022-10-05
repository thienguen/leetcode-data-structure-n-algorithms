#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include <string>

/*
    minimal impl of linked list, for use with HashList
*/

class Node
{
    public:
        std::string data;
        Node *next;
        Node(const std::string& d) : data(d), next() {}
        Node(const Node& copynode) : data(copynode.data), next() {}

    private:
        Node& operator=(const Node&);
};

class LinkedList {
    public:
        Node *head;
        Node *tail;

        LinkedList(const LinkedList& LL);
        LinkedList(): head(NULL), tail(NULL), d_nodecount(0) {}
        LinkedList(Node *newnode) : head(newnode), tail(newnode), d_nodecount(1) {}
        ~LinkedList();

        void insertTail(std::string);
        void removeHead();
        void printList() const;
       
        int nodeCount() const; 
        bool search(std::string) const;
    private:
        int d_nodecount;
};


#endif
