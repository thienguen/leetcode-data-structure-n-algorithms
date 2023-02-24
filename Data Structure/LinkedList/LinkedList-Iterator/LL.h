/// @note please spare me if you see a lot of comments, its my psedocode
/// @note The interface of the LL class is implemented here
#include <algorithm>
#include <iterator>

template <typename T>
class LL
{
    // contents of each node
    struct Node
    {
        T data;
        Node *prev;
        Node *next;
    };

private:
    Node *head;
    Node *tail;

    // iterator class to allow access of each node in main
public:
    class Iterator
    {
    public:
        friend class LL;
        Iterator();
        Iterator(Node *);
        T operator*() const;
        const Iterator &operator++(int);
        const Iterator &operator--(int);
        bool operator==(const Iterator &) const;
        bool operator!=(const Iterator &) const;

    private:
        Node *current;
    };

    /* Default */
    LL();
    ~LL();
    LL(const LL<T> &);

    /* Overload */
    const LL<T> &operator=(const LL<T> &);

    /* Characteristics */
    void headInsert(const T &);
    void tailInsert(const T &);
    Iterator begin() const;
    Iterator end() const;
    void swapNodes(Iterator &, Iterator &);
    void swapNodes2(Iterator &, Iterator &);
};

/// ---------------------------------------------------------------
/// ---------------------------------------------------------------
/// @note: This is the implementation of the Iterator Class

/// @paragraph: Default constructor for Iterator class
/// EFFECT: sets current with NULL or nullptr

template <typename T>
LL<T>::Iterator::Iterator()
{
    current = nullptr;
}

/// @paragraph: Copy constructor for Iterator class
/// EFFECT: constructor that sets current = ptr

template <typename T>
LL<T>::Iterator::Iterator(Node *node)
{
    current = node;
}

/// @paragraph: Overloads the dereferencing operator
/// EFFECT: returns the data field of the current node

template <typename T>
T LL<T>::Iterator::operator*() const
{
    return current->data;
}

/// @paragraph: Overloads the postfix ++ operator
/// EFFECT: moves the Iterator object one node over to the right

template <typename T>
const typename LL<T>::Iterator &LL<T>::Iterator::operator++(int)
{
    current = current->next;
    return *this;
}

/// @paragraph: Overloads the postfix -- operator
/// EFFECT: moves the Iterator object one node over to the left

template <typename T>
const typename LL<T>::Iterator &LL<T>::Iterator::operator--(int)
{
    current = current->prev;
    return *this;
}

/// @paragraph: Overloads the comparison operator ==
/// EFFECT: compare if *this Iterator and the rhs Iterator
///         are pointing to the same Node

template <typename T>
bool LL<T>::Iterator::operator==(const Iterator &other) const
{
    return current == other.current;
}

/// @paragraph: Overloads the inequality operator !=
/// EFFECT: compare if *this Iterator and the rhs Iterator
///         are pointing to different Nodes

template <typename T>
bool LL<T>::Iterator::operator!=(const Iterator &other) const
{
    return current != other.current;
}

/// ---------------------------------------------------------------
/// ---------------------------------------------------------------
/// @note: Implementation of the LL class

/// @paragraph: Default constructor for LL class
/// EFFECT: Initialized a LL object

template <typename T>
LL<T>::LL()
{
    head = tail = nullptr;
}

/// @paragraph : Copy constructor for LL class
/// EFFECT: deep copies the copy object into the *this

template <typename T>
LL<T>::LL(const LL<T> &other)
{
    head = tail = nullptr;
    auto it = other.begin();
    while (it != nullptr)
    {
        this->tailInsert(*it);
        it++;
    }
    // *this = other;
}

// / @paragraph : Destructor for LL class
// / EFFECT: Deaalocate the current object

template <typename T>
LL<T>::~LL()
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

/// @paragraph: Copy ssignment operator for LL class
/// EFFECT: deep copies the copy object into the lhs object

template <typename T>
const LL<T> &LL<T>::operator=(const LL<T> &other)
{ // self assignment
    if (this != &other)
    {
        while (head != nullptr)
        { // deaalocate the current lhs object
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;

        if (other.begin() != nullptr)
        {
            auto it = other.begin();
            while (it != nullptr)
            {
                this->tailInsert(*it);
                it++;
            }
        }
    }
    return *this;
}

/// @paragraph: begin() iterator object
/// EFFECT: returns an Iterator object whose current field contains this->head

template <typename T>
typename LL<T>::Iterator LL<T>::begin() const
{
    return Iterator(this->head);
}

/// @paragraph: end() iterator object
/// EFFECT: returns an Iterator object whose current field contains this->tail

template <typename T>
typename LL<T>::Iterator LL<T>::end() const
{
    return Iterator(this->tail);
}

/// @paragraph: headInsert() of LL clas
/// EFFECT: insert a new node to the front of the linked list and this
/// node’s data field must contain the contents in the item parameter

template <typename T>
void LL<T>::headInsert(const T &item)
{
    Node *const newNode = new Node{item};

    if (head == nullptr)
    { // empty list
        head = tail = newNode;
        newNode->next = nullptr;
        newNode->prev = nullptr;
    }
    else
    { // non-empty list
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = nullptr;
        head = newNode;
    }
}

/// @paragraph: tailInsert() of LL class
/// EFFECT: insert a new node to the back of the linked list and this
/// node’s data field must contain the contents in the item parameter

template <typename T>
void LL<T>::tailInsert(const T &item)
{
    Node *const newNode = new Node{item};

    if (tail == nullptr)
    { // empty list
        head = tail = newNode;
        newNode->next = nullptr;
        newNode->prev = nullptr;
    }
    else
    { // non-empty list
        newNode->next = nullptr;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

/// @paragraph: swapNodes() of LL class
/// EFFECT:  swap the location of the node it1.current
///          with the location it2.current

template <typename T>
void LL<T>::swapNodes(Iterator &it1, Iterator &it2)
{ // edge cases
    if (it1 == it2 || head->next == nullptr || head == nullptr)
        return;

    if (it1.current == head)
    { // if it1 is the head
        head = it2.current;
    }

    if (it2.current == tail)
    { // if it2 is the tail
        tail = it1.current;
    }

    // This will swap their next link
    Node *temp = it1.current->next;
    it1.current->next = it2.current->next;
    it2.current->next = temp;

    if (it1.current->next != nullptr)
    { // if it1's next is not null
        it1.current->next->prev = it1.current;
    }
    if (it2.current->next != nullptr)
    { // if it2's next is not null
        it2.current->next->prev = it2.current;
    }

    // This will swap their prev link
    temp = it1.current->prev;
    it1.current->prev = it2.current->prev;
    it2.current->prev = temp;

    if (it1.current->prev != nullptr)
    { // if it1's prev is not null
        it1.current->prev->next = it1.current;
    }
    if (it2.current->prev != nullptr)
    { // if it2's prev is not null
        it2.current->prev->next = it2.current;
    }

    // Swapping it1 and it2
    // This will swap the current pointers
    Node *tmp = it1.current;
    it1.current = it2.current;
    it2.current = tmp;
}

template <typename T>
void LL<T>::swapNodes2(Iterator& it1, Iterator& it2) {
    // Change head target if necessary
    if (it1 == begin()) {
        head = it2.current;
    }

    // Change tail target if necessary
    if (it2 == end()) {
        tail = it1.current;
    }

    Node* it1_left  = it1.current->prev;  // pointer to previous of it1 for swap
    Node* it2_right = it2.current->next;  // pointer to next of it2 for swap

    it1.current->prev = it2.current;
    it1.current->next = it2_right;

    if (it1_left != nullptr) {
        it1_left->next = it2.current;
    }

    it2.current->prev = it1_left;
    it2.current->next = it1.current;

    if (it2_right != nullptr) {
        it2_right->prev = it1.current;
    }

    // Swap targets of it1 and it2 so it1 is in before it2 again
    Node* tmp = it1.current;
    it1.current = it2.current;
    it2.current = tmp;
}

/// @note
// When writing linked list algorithms,
// always look at special cases:

// Empty list
// List with 1 element
// Activity at the beginning of the list
// Activity at the end of the list
// Activity will not occur (ex: The item is not in the list)
