#include <iostream>
#include <string>
#include "LinkedList.h"

LinkedList::LinkedList(const LinkedList& LL): 
head(NULL), 
tail(NULL),
d_nodecount(0)
{
    const Node * curr = LL.head;

    if(!head && curr) {
        head = new Node(curr->data);
        tail = head;
        curr = curr->next;
    }

    while(curr) {
        Node *newnode = new Node(curr->data);
        tail->next = newnode;
        tail = newnode;
        curr = curr->next;
    }
}

LinkedList::~LinkedList() 
{
    Node * curr = head;
    while(head) {
        head = head->next;
        delete curr;
        curr = head;
    }
}

void LinkedList::insertTail(std::string key)
{
    Node *newnode = new Node(key);
    if(tail == NULL) {
        newnode->next = tail;
        tail = newnode;
        head = newnode;
        d_nodecount++;
        return;
    }
    tail->next = newnode;
    tail = tail->next;
    d_nodecount++;
}

void LinkedList::removeHead()
{
    Node *delnode = head;
    head = head->next;
    delete delnode;
}

void LinkedList::printList() const
{
    Node *curr = head;
    while(curr) {
        std::cout << curr->data << std::endl;
        curr = curr->next;
    }
}

bool LinkedList::search(std::string key) const
{
    Node *curr = head;
    while(curr) {
        if(curr->data == key)
            return true;
        curr = curr->next;
    }
    return false;
}

int LinkedList::nodeCount() const
{
    return d_nodecount;
}
