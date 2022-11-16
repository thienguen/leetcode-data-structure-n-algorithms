#ifndef LIST_HPP
#define LIST_HPP

/// include libs, I have everything within powa now
#include <iostream>
#include <ostream>
#include <algorithm>
#include <initializer_list>
#include <stdexcept>
#include <utility>
#include <iterator>
#include <cstddef>
#include <cstdlib>
#include <cassert>

/// comments should come after this

template <class T>
class List
{
private:
    struct Node
    {
        T data{};     ///< value stored in the Node
        Node *prev{}; ///< pointer to the previous Node
        Node *next{}; ///< pointer to the next Node
    };

public:
    class Iterator
    {
    public:
        // member types
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = Node *;
        using reference = value_type &;

        Iterator(pointer ptr = nullptr)
            : current(ptr)
        {
        }

        reference operator*() const
        {
            if (current == nullptr)
            {
                throw std::logic_error("error: dereferencing nullptr");
            }
            return current->data;
        }

        pointer operator->()
        {
            return current;
        }

        Iterator &operator++()
        {
            if (current == nullptr)
            {
                throw std::logic_error("error: dereferencing nullptr");
            }
            current = current->next;
            return *this;
        }

        // postfix
        Iterator operator++(int)
        {
            if (current == nullptr)
            {
                throw std::logic_error("error: dereferencing nullptr");
            }
            Iterator tmp = *this;
            current = current->next;
            return tmp;
        }

        Iterator &operator--()
        {
            if (current == nullptr)
            {
                throw std::logic_error("error: dereferencing nullptr");
            }
            current = current->prev;
            return *this;
        }

        // postfix
        Iterator operator--(int)
        {
            if (current == nullptr)
            {
                throw std::logic_error("error: dereferencing nullptr");
            }
            Iterator tmp = *this;
            current = current->prev;
            return tmp;
        }

        friend bool operator==(const Iterator &lhs, const Iterator &rhs)
        {
            return lhs.current == rhs.current;
        }

        friend bool operator!=(const Iterator &lhs, const Iterator &rhs)
        {
            return lhs.current != rhs.current;
        }

    private:
        pointer current{};
    };

    // Member types
    using value_type = T;
    using size_type = std::size_t;
    using reference = value_type &;
    using iterator = Iterator;

    // default ctor
    List() = default;

    // copy ctor
    List(const List &other);

    // move ctor
    List(List &&other);

    // initializer list ctor
    List(const std::initializer_list<value_type> &ilist);

    // destructor
    // delete the object
    virtual ~List();

    // copy assignment operator
    List &operator=(const List &rhs);

    // move assignment operator
    List &operator=(List &&rhs);

    // access the first node
    reference front();

    // access the last node, a reference to a last node
    reference back();

    // iterator to the beigining of our linked list
    iterator begin() const { return iterator(head); }

    // iterator to the end, encapsulate the Node characteristics
    iterator end() const { return iterator(); }

    // meh
    bool empty() const { return begin() == end(); }

    // meh
    size_type size() const { return count; }

    // clear the list
    // keep using the object but erase the characteristic of its
    void clear();

    // find the node (iterator) then insert a particular position
    iterator insert(iterator pos, const value_type &value);

    // opposite delete at a particular item/ pos
    iterator erase(iterator pos);

    // swap head, tail, count
    // handle this object class/
    void swap(List &other);

    // huh
    void copyList(const List<T> &other);

protected:
    Node *head{};      ///< pointer to the head node
    Node *tail{};      ///< pointer to the tail node
    size_type count{}; ///< number of nodes in list
};

/** NON-MEMBER TEMPLATE FUNCTIONS **/

/// Overloaded function see two List<T> is equal
/// @param lhs the list being check with a value
/// @param rhs the list check the lhs value

template <class T>
bool operator==(const List<T> &lhs, const List<T> &rhs);

/// Overloaded function see two List<T> is not equal
/// @param lhs the list being check with a value
/// @param rhs the list check the lhs value

template <class T>
bool operator!=(const List<T> &lhs, const List<T> &rhs);

/// ouput our linked list
/// @param output pass by reference to output
/// @param list the list contain the data

template <class T>
std::ostream &operator<<(std::ostream &output, const List<T> &list);


/// --------------------------------------------------------
///             @note NON - MEMBER definitions 
/// --------------------------------------------------------

/// @brief operator== see two List<T> is equal
/// @tparam T the type of the data
/// @param lhs  the list being check with a value
/// @param rhs  the list check the lhs value
/// @return  true if the two list are equal, false otherwise

template <class T>
bool operator==(const List<T>& lhs, const List<T>& rhs)
{ return &lhs == &rhs || std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }

/// @brief operator!= see two List<T> is not equal
/// @tparam T the type of the data
/// @param lhs  the list being check with a value
/// @param rhs  the list check the lhs value
/// @return  true if the two list are not equal, false otherwise

template <class T>
bool operator!=(const List<T> &lhs, const List<T> &rhs)
{
    return !(lhs == rhs);
}

/// @brief output our linked list
/// @tparam T the type of the data
/// @param output pass by reference to output
/// @param list the list contain the data
/// @return  the output

template <class T>
std::ostream &operator<<(std::ostream &output, const List<T> &list)
{
    char separator[2]{};

    output << '{';
    // it returning an iterator so for type of current
    // my gut telling me typename::List<T>::iterator current
    for (auto c = list.begin(); c != nullptr; c++)
    {
        output << separator << c->data;
        *separator = ',';
    }

    return output << "}";
}

/// --------------------------------------------------------
///     @note Functions definition - THE RULE OF FIVE
/// --------------------------------------------------------

/// copy constructor
/// @param other A list of class List
template <class T>
List<T>::List(const List<T> &other)
{
    head = tail = nullptr;

    if (other.size() > 0)
    {
        copyList(other);
        count = other.size();
    }
}

/// @paragraph second-approach
// template <class T>
// List<T>::List(const List& other) { *this = other; }

/// move constructor
template <class T>
/// @param other A list of class List
List<T>::List(List<T> &&other)
    : head(other.head), tail(other.tail), count(other.count)
{
    // leave other in stable state
    other.head = other.tail = nullptr;

    other.count = 0;
}

/// @paragraph seconf-approach
// template <class T>
// List<T>::List(List<T>&& other)
// :  head(std::exchange(other.head,  nullptr)),
//    tail(std::exchange(other.tail,  nullptr)),
//   count(std::exchange(other.count, 0)) {}

/// @note comeback to fix later 4/2/2022
/// initializer list
/// @param ilist type initializer list at the same time we declare it
/// @attention & is a reference so we don't have to copy it
template <class T>
List<T>::List(const std::initializer_list<value_type> &ilist)
{
    for (auto &item : ilist)
    {
        insert(end(), item);
    }
}

/// destructor
/// EFFECT: dynamically delete any list class object

template <class T>
List<T>::~List() { clear(); }

/// copy assignment operator
template <class T>
/// @param rhs an object being copy but keep it a live

List<T> &List<T>::operator=(const List<T> &rhs)
{
    // self-guard
    if (this != &rhs)
    {
        clear();

        // use the copy constructor
        List<T> temp(rhs);

        // since temp is going to be destroy or go out of scope
        // this get its members and then return *this
        this->swap(temp);
    }

    // return *this
    return *this;
}

/// move assignment operator
/// @param rhs an object that soon be delete

template <class T>
List<T> &List<T>::operator=(List<T> &&rhs)
{
    if (this != &rhs)
    {
        clear();

        head = std::exchange(rhs.head, nullptr);
        tail = std::exchange(rhs.tail, nullptr);
        count = std::exchange(rhs.count, 0);
    }

    // return this*
    return *this;
}

/// ------------------------------------------------------------
/// @note Functions definition - member function perform action
/// ------------------------------------------------------------

/// front element data
/// EFFECT: access the data of the first element

template <class T>
T &List<T>::front()
{
    if (head == nullptr)
    {
        throw std::logic_error("HELP ME_front");
    }
    return head->data;
}

/// back element data
/// EFFECT: access the data of the last element

template <class T>
T &List<T>::back()
{
    return !empty() ? tail->data : throw std::logic_error("Help me_back")
}

/// clear the list
/// EFFECT: technically delete the list

template <class T>
void List<T>::clear()
{
    // return if first is nullptr b/c there's no list to destroy
    if (head == nullptr)
    {
        tail = nullptr;
    }

    // if there is something
    else
    {
        // if (head == nullptr) { return; }
        Node *temp;

        // delete till the tail
        while (head != tail)
        {
            temp = head->next;
            delete head;
            head = temp;
        }

        // delete the tail
        delete head;
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
}

/// insert item at any position [I REPEAT - POSiSTION]
/// @param pos the position where we want to insert - disguise as iterator
/// @param value the data for that position

template <class T>
typename ::List<T>::iterator
List<T>::insert(List<T>::iterator pos, const value_type &value)
{
    Node *const newNode = new Node{value};
    // account for if the list was empty
    if (empty())
    {
        head = tail = newNode;
    }
    //  if pos was the beginning
    else if (pos == begin())
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    // if pos was the end of the list
    else if (pos == end())
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    // if it's in the middle of the list
    else
    {
        newNode->next = pos->prev->next;
        newNode->prev = pos->prev;

        pos->prev->next = newNode;
        pos->prev = newNode;
    }

    count++;

    return iterator(newNode);
} // end insert

/// erase the stuff at the exact position we want
/// @param pos the position where we want to delete - disguise as iterator
template <class T>
typename ::List<T>::iterator List<T>::erase(List<T>::iterator pos)
{
    auto following = List<T>::iterator();

    if (head == nullptr)
    {
        throw std::logic_error("empty, like my soul_erase");
    }
    // position is at beginning of the list
    else if (pos == begin())
    {
        // skip the node
        head = head->next;

        // more than 1 node, then just the back being fixed
        if (head != nullptr)
        {
            head->prev = nullptr;
        }

        // there is exactly 1 node, must leave tail in stable state
        else
        {
            tail = nullptr;
        }
    }
    // position is from second node to tail of node
    else
    {
        // skip the node we want to delete
        pos->prev->next = pos->next;

        // if the value in the middle of the list
        if (pos->next != nullptr)
        {
            pos->next->prev = pos->prev;
        }

        // if it's the tail of the list or pos->next == nullptr
        else if (pos == tail)
        {
            tail = pos->prev;
        }
    }

    // delete the node;

    following = pos->next;

    delete pos.operator->();

    --count;

    return following;
}

/// swap private member of class List<T>
/// @param other swap this object with other

template <class T>
void List<T>::swap(List &other)
{
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    std::swap(count, other.count);
}

// copy list for the copy constructor
/// @paragraph this is a reference to the text-book, I found it to be
///            quite useful since it doesn't use iterator. I compare the two

template <class T>
void List<T>::copyList(const List<T> &other)
{
    Node *newNode; // pointer to create a node
    Node *current; // pointer to traverse the list

    // if its not empty, make it empty
    if (head != nullptr)
    {
        clear();
    }

    if (other.head == nullptr)
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    else
    {
        current = other.head;

        // list to be copied
        count = other.count;

        // copy the first node
        head = new Node{current->data, nullptr};
        // head->data = current->data;
        // head->next = nullptr;

        // we just only copy the first node, so tail also head
        tail = head;

        current = current->next;

        // make current point to
        // the next node
        // copy the remaining list
        while (current != nullptr)
        {
            newNode = new Node{current->data, nullptr};

            // attach newNode after last
            tail->next = newNode; 
            
            // make last point to the actual last node
            tail = newNode;       
            
            current = current->next;
        }  
    }  
}

#endif /* EOF */

/// @note
// When writing linked list algorithms,
// always look at special cases:

// Empty list
// List with 1 element
// Activity at the beginning of the list
// Activity at the end of the list
// Activity will not occur (ex: The item is not in the list)