#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

template <class T>
struct nodeType
{
    T info;
    nodeType<T> *link;
};

template <class T>
class linkedListType
{
protected:
    int count;
    nodeType<T> *first;
    nodeType<T> *last;

public:
    linkedListType();
    linkedListType(const linkedListType<T> &);
    ~linkedListType();

    int length() const;
    void initializeList();
    bool isEmptyList() const;
    void print() const;
    void reversePrint() const;
    void destroyList();

    T front() const;
    T back() const;
    nodeType<T> *firstPtr() const;

    virtual bool search(const T &) const = 0;
    virtual void insert(const T &) = 0;
    virtual void insertLast(const T &) = 0;
    virtual void deleteNode(const T &) = 0;

private:
    void copyList(const linkedListType<T> &);
    void recursiveReversePrint(nodeType<T> *) const;
};

template <class T>
linkedListType<T>::linkedListType()
{
    first = nullptr;
    last = nullptr;
    count = 0;
}

template <class T>
linkedListType<T>::linkedListType(const linkedListType<T> &rhs)
{
    first = nullptr;
    last = nullptr;
    count = rhs.length();

    if (rhs.length() > 0)
    {
        copyList(rhs);
    }
}

template <class T>
linkedListType<T>::~linkedListType()
{
    destroyList();
}

template <class T>
void linkedListType<T>::initializeList()
{
    destroyList();
}

template <class T>
bool linkedListType<T>::isEmptyList() const
{

    if (first == nullptr)
    {
        return true;
    }
    return false;
}

template <class T>
void linkedListType<T>::print() const
{
    for (nodeType<T> *ptr = first; ptr != nullptr; ptr = ptr->link)
    {
        cout << ptr->info << " ";
    }
}

template <class T>
void linkedListType<T>::reversePrint() const
{
    recursiveReversePrint(first);
}

template <class T>
int linkedListType<T>::length() const
{
    return count;
}

template <class T>
void linkedListType<T>::destroyList()
{

    if (first == nullptr)
    {
        return;
    }
    nodeType<T> *temp;

    while (first != last)
    {
        temp = first->link;
        delete first;
        first = temp;
    }
    delete first;
    first = nullptr;
    last = nullptr;
    count = 0;
}

template <class T>
nodeType<T> *linkedListType<T>::firstPtr() const
{
    return first;
}

template <class T>
T linkedListType<T>::front() const
{
    if (first != nullptr)
    {
        return first->info;
    }
    return 0;
}

template <class T>
T linkedListType<T>::back() const
{
    if (last != nullptr)
    {

        return last->info;
    }

    return 0;
}

template <class T>
void linkedListType<T>::copyList(const linkedListType<T> &list)
{
    first = new nodeType<T>;
    first->link = nullptr;

    nodeType<T> *original = list.first;
    nodeType<T> *copy = first;

    copy->info = original->info;
    original = original->link;

    while (original != nullptr)
    {
        copy->link = new nodeType<T>;
        copy = copy->link;

        copy->info = original->info;
        original = original->link;
    }

    copy->link = nullptr;
    last = first;

    while (last->link != nullptr)
    {
        last = last->link;
    }
}

template <class T>
void linkedListType<T>::recursiveReversePrint(nodeType<T> *list) const
{
    if (list == nullptr)
    {
        return;
    }
    recursiveReversePrint(list->link);
    cout << list->info << " ";
    if (first == list)
    {
        cout << endl;
    }
}

#endif