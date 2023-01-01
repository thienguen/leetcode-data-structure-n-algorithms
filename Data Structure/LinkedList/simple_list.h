/// @file "simple_list.h"
/// @author Thien Nguyen nvktvan@gmail.com
/// @date 3/27/22

#ifndef SIMPLE_LIST_H
#define SIMPLE_LIST_H

#include <cassert>
#include <iostream>
#include <ostream>
#include <utility> 
#include <algorithm>
#include <initializer_list>

struct Node {
    int   info;
    Node* link;
};

/// initializes a list to empty
void list_init(Node*& first, Node*& last);

/// checks whether a list is empty
bool list_is_empty(const Node* first, const Node* last);

/// prints a list in order using {1,2,3} format
void list_print(const Node* first, const Node* last);

/// returns the number of elements (nodes) in a list
size_t list_size(const Node* first, const Node* last);

/// destroys a list
void list_destroy(Node*& first, Node*& last);

/// accesses the front element of a list
int list_front(const Node* first, const Node* last);

/// accesses the back element of a list
int list_back(const Node* first, const Node* last);

/// searches a list for an item, returning true if found
bool list_search(const Node* first, const Node* last, int item);

/// inserts an element to the beginning of a list
void list_insert_first(Node*& first, Node*& last, int item);

/// inserts an element to the end of a list
void list_insert_last(Node*& first, Node*& last, int item);

/// removes the first element from a list
void list_delete_first(Node*& first, Node*& last);

/// removes the last element
void list_delete_last(Node*& first, Node*& last);

/// removes the first occurrence of item from a list
void list_delete_item(Node*& first, Node*& last, int item);

/// creates of copy of the nodes from first1 to last1,
/// the copy beginning at first2 and ending at last2
void list_copy(const Node* first1, const Node* last1, Node*& first2, Node*& last2); 

#endif /* EOF */
