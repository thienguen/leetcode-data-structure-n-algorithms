#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include "Node.h"

class Circular_Linked_Lists
{
    int data;
    Node *head;
    Node *tail;

public:
    Circular_Linked_Lists(int data);
    void add_node_head(int);
    void add_node_tail(int);
    void add_after_node(int, int);
    void add_before_node(int, int);
    void remove_node_head();
    void remove_node_tail();
    void remove_after_node(int);
    void remove_before_node(int);
    void remove_node_data(int);
    void remove_numbered_node(int);
    int total_nodes();
    int total_nodes_given_data(int);
    void display_linked_list();
    void reverse_linked_list();
    void selection_sort();
    void insertion_sort();
    void join_linked_lists(Circular_Linked_Lists *);
    ~Circular_Linked_Lists();
};

#endif