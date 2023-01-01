#ifndef UNORDEREDLINKEDLIST_H
#define UNORDEREDLINKEDLIST_H

#include <iostream>
#include "linkedListType.h"

using namespace std;

template <class t>
class unorderedLinkedList : public linkedListType<t>
{
public:
    bool search(const t &) const;
    void insert(const t &);
    void insertLast(const t &);
    void deleteNode(const t &);

protected:
    using linkedListType<t>::count;
    using linkedListType<t>::first;
    using linkedListType<t>::last;
};

template <class t>
bool unorderedLinkedList<t>::search(const t &value) const
{

    for (nodeType<t> *ptr = first; ptr != nullptr; ptr = ptr->link)
    {
        if (ptr->info == value)
            return true;
    }
    return false;
}

template <class t>
void unorderedLinkedList<t>::insert(const t &value)
{
    nodeType<t> *temp;
    temp = new nodeType<t>;

    temp->info = value;
    temp->link = first;
    first = temp;

    if (last == nullptr)
    {
        last = first;
    }

    count++;
}

template <class t>
void unorderedLinkedList<t>::insertLast(const t &value)
{
    nodeType<t> *temp;
    temp = new nodeType<t>;

    temp->info = value;
    temp->link = nullptr;

    if (last == nullptr)
    {
        first = temp;
        last = temp;
    }
    else
    {
        last->link = temp;
        last = temp;
    }

    count++;
}

template <class t>
void unorderedLinkedList<t>::deleteNode(const t &value)
{
    if (first == nullptr)
    {
        cout << "Cannot delete from an empty list.\n";
        return;
    }

    nodeType<t> *temp;
    temp = first;

    if (first->info == value)
    {
        if (first == last)
        {
            first = last = nullptr;
        }
        else
            first = first->link;

        delete temp;
        count--;
    }
    else if (last->info == value)
    {
        while (temp->link != last)
        {
            temp = temp->link;
        }
        delete last;
        last = temp;
        last->link = nullptr;
        count--;
    }
    else
    {
        nodeType<t> *del = nullptr;

        while (temp != last)
        {
            if (temp->link->info == value)
            {
                del = temp->link;
                temp->link = del->link;
                delete del;

                count--;
                return;
            }
            temp = temp->link;
        }
        cout << "The item to be deleted is not in the list.\n";
    }
}

#endif