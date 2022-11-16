/// @file "simple_list.cpp"
/// @author Thien Nguyen nvktvan@gmail.com
/// @date 3/27/22

#include <algorithm>
#include "simple_list.h"
#include "simple_list.h"

/// initialize an empty list, we have a list !
/// @param first the first node in the list
/// @param last the last node in the list

void list_init(Node *&first, Node *&last)
{
    // they both not null or nullptr then we take them
    assert((first && last) || (!first && !last));
    list_destroy(first, last);
}

/// @param first the first node in the list
/// @param last the last node in the list
/// @return true if the list is empty, false otherwise

bool list_is_empty(const Node *first, const Node *last)
{
    assert((first && last) || (!first && !last));
    return first == nullptr;
}

/// prints a list in order using {1,2,3} format
void list_print(const Node *first, const Node *last)
{
    assert((first && last) || (!first && !last));

    char separator[2]{};

    std::cout << '{';

    for (auto current = first; current != nullptr; current = current = current->link)
    {
        std::cout << separator << current->info;
        *separator = ',';
    }

    std::cout << "}\n";
}

size_t list_size(const Node *first, const Node *last)
{
    size_t count = 0;
    while (first != nullptr)
    {
        count++;
        first = first->link;
    }
    return count;
}

/// destroys a list
void list_destroy(Node *&first, Node *&last)
{
    // we only destroy if it's something inside
    while (first != nullptr)
    {
        Node *temp = first;
        first = first->link;
        delete temp;
    }
    last = nullptr;
}

/// accesses the front element of a list
int list_front(const Node *first, const Node *last)
{
    assert(first != nullptr);
    return first->info;
}

/// accesses the back element of a list
int list_back(const Node *first, const Node *last)
{
    assert(last != nullptr);
    return last->info;
}

/// searches a list for an item, returning true if found
bool list_search(const Node *first, const Node *last, int item)
{
    // flag control toward return statement
    bool found = false;
    const Node *i = first;

    // found from something
    while (i != nullptr && !found)
    {
        // if we found it
        if (i->info == item)
        {
            found = true;
        }

        // traverse to the next Node
        i = i->link;
    }
    return found;
}

/// inserts an element to the beginning of a list
void list_insert_first(Node *&first, Node *&last, int item)
{
    // create a new Node, assign its link to what first is pointin
    // then assign first to that new head Node
    // if nothing in the list the first place, must leave the list
    // in a stable form

    assert((first && last) || (!first && !last));

    first = new Node{item, first};
    if (last == nullptr)
    {
        last = first;
    }
}

/// inserts an element to the end of a list
void list_insert_last(Node *&first, Node *&last, int item)
{
    if (first == nullptr)
    {
        list_insert_first(first, last, item);
    }
    else
    {
        last->link = new Node{item, nullptr};
        last = last->link;
    }
}

/// removes the first element from a list
void list_delete_first(Node *&first, Node *&last)
{
    // delete from somthing
    if (first != nullptr)
    {
        const Node *temp = first;
        first = first->link;
        delete temp;

        // if delete to nothing, leave its stable so we can re-use
        if (first == nullptr)
        {
            last = nullptr;
        }
    }
}

/// removes the last element
void list_delete_last(Node *&first, Node *&last)
{
    if (first == last)
    {
        list_delete_first(first, last);
    }
    else
    {
        Node *current = first;
        Node *prev = nullptr;

        for (; current->link; prev = current, current = current->link) {}
        delete current;
        prev->link = nullptr;
        last = prev;
    }
}

/// removes the first occurrence of item from a list
void list_delete_item(Node *&first, Node *&last, int item)
{

    Node *current = first;
    Node *prev = nullptr;

    // traverse to the second-last element, if exists
    while (current != nullptr && current->info != item)
    {
        prev = current;
        current = current->link;
    }

    // make sure the Node exits in the list
    if (current != nullptr)
    {
        if (current == first)
        {
            first = current->link;
        }
        else if (current != first)
        {
            prev->link = current->link;
        }

        delete current;
    }
}

/// creates of copy of the nodes from first1 to last1,
/// the copy beginning at first2 and ending at last2
void list_copy(const Node *first1, const Node *last1,
               Node *&first2, Node *&last2)
{
    // run through the loop to see we have any thing to copy
    // pointer to a const variable so it's ok to change the pointer
    // insert_last...huh
    for (const Node *i = first1; i != nullptr; i = i->link)
    {
        list_insert_last(first2, last2, i->info);
    }
}

/// @note
// When writing linked list algorithms,
// always look at special cases:

// Empty list
// List with 1 element
// Activity at the beginning of the list
// Activity at the end of the list
// Activity will not occur (ex: The item is not in the list)
