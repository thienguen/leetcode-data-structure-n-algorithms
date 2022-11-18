#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H

#include <iostream>
#include "linkedListType.h"

using namespace std;

template <class t>
class orderedLinkedList : public linkedListType<t>
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
bool orderedLinkedList<t>::search(const t &value) const
{

    for (nodeType<t> *ptr = first; ptr != nullptr; ptr = ptr->link)
    {
        if (ptr->info == value)
            return true;
    }
    return false;
}

template <class t>
void orderedLinkedList<t>::insert(const t &value)
{

    nodeType<t> *temp;
    temp = new nodeType<t>;
    temp->info = value;
    temp->link = nullptr;

    if (first == nullptr)
    {
        first = temp;
        last = temp;
    }
    else if (value < first->info)
    {
        temp->link = first;
        first = temp;
    }
    else if (value >= last->info)
    {
        last->link = temp;
        last = temp;
    }
    else
    {
        nodeType<t> *iter;
        iter = first;

        for (iter = first; value > iter->link->info; iter = iter->link)
        {
        }
        temp->link = iter->link;
        iter->link = temp;
    }

    count++;
}

template <class t>
void orderedLinkedList<t>::deleteNode(const t &value)
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
            first = nullptr;
            last = nullptr;
        }
        else
        {
            first = first->link;
        }
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
        nodeType<t> *del;
        while (temp != last && value > temp->info)
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

template <class t>
void orderedLinkedList<t>::insertLast(const t &value)
{

    insert(value);
}

#endif