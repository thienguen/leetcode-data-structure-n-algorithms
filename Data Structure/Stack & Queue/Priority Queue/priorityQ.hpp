/// @brief Assignment 8
/// Priority Queue priorityQ.hpp
#ifndef PRIORQ_H_
#define PRIORQ_H_

#include <iostream>
#include <string>
#include <cmath>

template <typename Type>
class priorityQ
{
public:
    /* Default */
    priorityQ(int size = 10);
    priorityQ(const priorityQ<Type> &);
    ~priorityQ();

    /* Overload */
    const priorityQ<Type> &operator=(const priorityQ<Type> &);

    void insert(const Type &);
    void deleteHighestPriority();
    Type getHighestPriority();
    bool isEmpty();
    void bubbleUp(int);
    void bubbleDown(int);
    int getSize() const;

private:
    int capacity;
    int items;
    Type *heapArray;
};

///---------------------------------------
/// class constructor
/// @param int heap size
///---------------------------------------
template <typename Type>
priorityQ<Type>::priorityQ(int size)
{
    this->capacity = size;
    this->items = 0;

    this->heapArray = new Type[this->capacity];

    for (int i = 0; i < this->capacity; i++)
    {
        this->heapArray[i] = Type();
    }
}

///---------------------------------------
/// copy constructor
/// @param priorityQ to copy
/// @note performs a deep copy
///---------------------------------------
template <typename Type>
priorityQ<Type>::priorityQ(const priorityQ<Type> &rhs)
{
    this->capacity = rhs.capacity;
    this->items = rhs.items;

    this->heapArray = new Type[this->capacity];

    for (int i = 0; i < this->capacity; i++)
    {
        this->heapArray[i] = rhs.heapArray[i];
    }
}

///---------------------------------------
/// destructor
///---------------------------------------
template <typename Type>
priorityQ<Type>::~priorityQ()
{
    delete[] this->heapArray;
}

///---------------------------------------
/// assignment operator overload
/// @param priorityQ to copy
/// @note performs a deep copy
///---------------------------------------
template <typename Type>
const priorityQ<Type> &priorityQ<Type>::operator=(const priorityQ<Type> &rhs)
{
    if (this == &rhs)
        return *this;

    if (this->items > 0)
    {
        delete[] this->heapArray;
    }

    this->capacity = rhs.capacity;
    this->items = rhs.items;

    for (int i = 0; i < this->capacity; i++)
    {
        this->heapArray[i] = rhs.heapArray[i];
    }

    return *this;
}

///---------------------------------------
/// func: insert()
/// @param Type data to insert into heap
/// @note inserts into end of visible array and bubbles up
///---------------------------------------
template <typename Type>
void priorityQ<Type>::insert(const Type &data)
{
    if ((this->items + 1) == this->capacity)
    {
        auto big_list = new Type[this->capacity + 1];
        for (int i = 0; i < this->capacity; i++)
        {
            big_list[i] = this->heapArray[i];
        }
        delete[] this->heapArray;
        this->heapArray = big_list;
        this->capacity++;
    }

    this->items++;
    this->heapArray[this->items] = data;
    bubbleUp(this->items);
}

///---------------------------------------
/// func: deleteHighestPriority()
/// @note sets end of heap to front and bubbles down
/// @note ends up resorting entire heap
///---------------------------------------
template <typename Type>
void priorityQ<Type>::deleteHighestPriority()
{
    if (!isEmpty())
    {
        this->heapArray[1] = this->heapArray[this->items];
        this->items--;
        bubbleDown(1);
    }
}

///---------------------------------------
/// func: getHighestPriority()
/// @return gets first value in heap (highest)
///---------------------------------------
template <typename Type>
Type priorityQ<Type>::getHighestPriority()
{
    return this->heapArray[1];
}

///---------------------------------------
/// func: isEmpty()
/// @return true if no visible items in heap
///---------------------------------------
template <typename Type>
bool priorityQ<Type>::isEmpty()
{
    return this->items == 0;
}

///---------------------------------------
/// func: bubbleUp()
/// @param index
/// @note takes element at index and attempts to sort upwards
///---------------------------------------
template <typename Type>
void priorityQ<Type>::bubbleUp(int index)
{
    for (int i = index; i > 0; i = i / 2)
    {
        auto current = this->heapArray[i];
        auto par_ind = ((i / 2) > 0) ? i / 2 : i;
        auto parent = this->heapArray[par_ind];

        if (parent < current)
        {
            this->heapArray[i / 2] = current;
            this->heapArray[i] = parent;
        }
        else
        {
            break;
        }
    }
}

///---------------------------------------
/// func: bubbleDown()
/// @param index
/// @note takes element at index and attempts to sort
///---------------------------------------
template <typename Type>
void priorityQ<Type>::bubbleDown(int index)
{
    // return if leaf node
    if (ceil(log2(index)) >= ceil(log2(this->items)))
        return;

    int left_i;
    int right_i;
    for (int i = index; i <= this->items;)
    {

        auto current = this->heapArray[i];

        bool l_exists = (i * 2 <= this->items);
        left_i = l_exists ? i * 2 : i;
        auto lchild = this->heapArray[left_i];

        bool r_exists = (2 * i + 1 <= this->items);
        right_i = r_exists ? 2 * i + 1 : i;
        auto rchild = this->heapArray[right_i];

        if (!l_exists)
        {
            return; // leaf node
        }
        else
        {
            if (r_exists)
            {
                // current > children
                if (current > lchild && current > rchild)
                    return;

                if (lchild > rchild)
                {
                    this->heapArray[left_i] = current;
                    this->heapArray[i] = lchild;
                    i = left_i;
                }
                else
                {
                    this->heapArray[right_i] = current;
                    this->heapArray[i] = rchild;
                    i = right_i;
                }
            }
            else
            {
                if (current > lchild)
                {
                    return;
                }
                else
                {

                    this->heapArray[left_i] = current;
                    this->heapArray[i] = lchild;
                    i = left_i;
                }
            }
        }
    }
}

///---------------------------------------
/// func: getSize()
/// @return returns amount of usable items in heap
///---------------------------------------
template <typename Type>
int priorityQ<Type>::getSize() const
{
    return this->items;
}

#endif // PRIORQ_H_
