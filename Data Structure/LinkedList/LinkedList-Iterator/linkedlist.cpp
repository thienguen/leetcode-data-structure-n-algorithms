#include "linkedlist.hpp"

///---------------------------------------
/// LL() Constructor
/// Called when object is instantiated
/// Sets head and tail members to nullptr
///---------------------------------------
template <typename type>
LL<type>::LL()
{
	head = tail = nullptr;
}

///---------------------------------------
/// Copy Constructor
/// @param LL Linked list to copy
/// Creates a deep copy of a LL object
///---------------------------------------
template <typename type>
LL<type>::LL(const LL<type> &rhs)
{
	for (auto walk = rhs.begin(); walk != nullptr; walk++)
		this->tailInsert(*walk);
}

///---------------------------------------
/// Assignment Operator Overlaod
/// @param LL Linked list to copy
/// @return Instantiated object with rhs's values
/// Creates a deep copy of a LL object
///---------------------------------------
template <typename type>
const LL<type> &LL<type>::operator=(const LL<type> &rhs)
{
	if (this->head == nullptr)
	{
		// if 'this' is empty, start filling
		for (auto walk = rhs.begin(); walk != nullptr; walk++)
			this->tailInsert(*walk);
	}
	else
	{
		// case for 'this' being not empty
		// delete all contents of 'this'
		node *deletion = this->head;
		node *traversal = deletion->next;
		while (deletion != this->tail)
		{
			delete deletion;
			deletion = traversal;
			traversal = traversal->next;
		}
		// deletes tail
		traversal = nullptr;
		delete traversal;

		// then fill list with rhs elements
		for (auto walk = rhs.begin(); walk != nullptr; walk++)
			this->tailInsert(*walk);
	}

	return *this;
}

///---------------------------------------
/// Destructor
/// Called when object goes out of scope
///---------------------------------------
template <typename type>
LL<type>::~LL()
{
	auto begin = this->begin();
	LL<type>::iterator nil = nullptr;
	while (begin != nil)
	{
		delete begin.current;
		begin++;
	}
}

///---------------------------------------
/// Method: headInsert()
/// @param type value to insert
/// Creates a new node at the head with value rhs
///---------------------------------------
template <typename type>
void LL<type>::headInsert(const type &rhs)
{
	node *something = new node;
	something->data = rhs;
	something->next = nullptr;
	something->prev = nullptr;

	// if list is empty, set head
	if (this->tail == nullptr)
	{
		this->head = something;
		this->tail = something;
	}
	else
	{
		// if list isnt empty
		// set something as new head
		// and push previous head to 'not head'
		something->next = this->head;
		something->next->prev = something;
		this->head = something;
	}
}

///---------------------------------------
/// Method: tailInsert()
/// @param type value to insert
/// Creates a new node at the tail with value rhs
///---------------------------------------
template <typename type>
void LL<type>::tailInsert(const type &rhs)
{
	node *something = new node;
	something->data = rhs;
	something->next = nullptr;
	something->prev = nullptr;

	// if list is empty, set tail
	if (this->head == nullptr)
	{
		this->tail = something;
		this->head = something;
	}
	else
	{
		// if list isnt empty
		// set something as new head
		// and push previous head to 'not head'
		something->prev = this->tail;
		something->prev->next = something;
		this->tail = something;
	}
}

///---------------------------------------
/// Method: begin()
/// @return head of list
/// Returns an iterator object with a pointer to head of list
///---------------------------------------
template <typename type>
typename LL<type>::iterator LL<type>::begin() const
{
	return this->head;
}

///---------------------------------------
/// Method: end()
/// @return last node of list
/// Returns an iterator object with a pointer to tail of list
///---------------------------------------
template <typename type>
typename LL<type>::iterator LL<type>::end() const
{
	return this->tail;
}

///---------------------------------------
/// Iterator constructor
/// Instantiates iterator object, sets node member to nullptr
///---------------------------------------
template <typename type>
LL<type>::iterator::iterator()
{
	current = nullptr;
}

///---------------------------------------
/// Iterator copy constructor
/// @param node node address to copy
/// Instantiates iterator object, sets node address to ptr
///---------------------------------------
template <typename type>
LL<type>::iterator::iterator(node *ptr)
{
	current = ptr;
}

///---------------------------------------
/// Dereference operator overload for iterator object
/// @return current's 'data' value
/// Returns value inside the data member of current
///---------------------------------------
template <typename type>
type LL<type>::iterator::operator*() const
{
	return this->current->data;
}

///---------------------------------------
/// Iterator post increment operator overload
/// @return current's linked 'next' node
/// Advances iterator to next node in list
///---------------------------------------
template <typename type>
const typename LL<type>::iterator &LL<type>::iterator::operator++(int)
{
	current = this->current->next;
	return *this;
}

///---------------------------------------
/// Iterator post decrement operator overload
/// @return current's linked 'prev' node
/// Advances iterator to prev node in list
///---------------------------------------
template <typename type>
const typename LL<type>::iterator &LL<type>::iterator::operator--(int)
{
	current = this->current->prev;
	return *this;
}

///---------------------------------------
/// Equality comparison operator overload
/// @param iterator ptr to compare
/// @return if ptr 'current' address match with rhs
/// Checks if current iterator location matchs with rhs ptr
///---------------------------------------
template <typename type>
bool LL<type>::iterator::operator==(const iterator &rhs) const
{
	return this->current == rhs.current;
}

///---------------------------------------
/// Not equality comparison operator overload
/// @param iterator ptr to compare
/// @return if ptr 'current' address doesnt match with rhs
/// Checks if current iterator location doesn't match with rhs ptr
///---------------------------------------
template <typename type>
bool LL<type>::iterator::operator!=(const iterator &rhs) const
{
	return this->current != rhs.current;
}

///---------------------------------------
/// Method: swapNodes()
/// @param iterator ptr to swap
/// @param iterator ptr to swap
/// Swaps geographical location of ptr's in list
///---------------------------------------
template <typename type>
void LL<type>::swapNodes(iterator &it1, iterator &it2)
{
	// if head/tail are the same
	// or if any iterators are set to nullptr
	if ((it1.current == it2.current) ||
		(it1.current == nullptr || it2.current == nullptr))
		return;

	// need to check if pointer belongs to list
	// and orientation of iterators
	bool valid1 = false;
	bool valid2 = false;
	bool right = false;

	LL<type>::iterator nil = nullptr;
	LL<type>::iterator check = this->begin();
	// passes through list once
	// to check the validity of iterators
	while (check != nil)
	{
		if (check.current == it1.current)
			valid1 = true;

		if (check.current == it2.current)
			valid2 = true;
		// marks orientation. right = iterators go left to right
		if (valid1 == true && valid2 == false)
			right = true;

		check++;
	}
	// if element doesn't exist within list, then exit
	if (valid1 == false || valid2 == false)
		return;

	node *node1;
	node *node1p;
	node *node1n;
	node *node2;
	node *node2p;
	node *node2n;

	if (right)
	{
		// 'right' oritentation
		// surrounding nodes will be marked 'correctly'
		node1 = it1.current;
		node2 = it2.current;
	}
	else
	{
		// 'wrong' orientation
		// it2 is masked as it1
		// essentially reflips order and operates normally
		node1 = it2.current;
		node2 = it1.current;
	}

	node1p = node1->prev;
	node1n = node1->next;
	node2p = node2->prev;
	node2n = node2->next;

	// One direction at a time
	// starting with prev links

	// if node1 is the head
	if (node1->prev == nullptr)
	{
		node2->prev = nullptr;
		this->head = node2;
	}
	else
	{
		// if not, it has a prev and needs to be switched
		node2->prev = node1->prev;
		node2->prev->next = node2;
	}
	// adjacency case
	if (node1->next == node2)
	{
		node1p = node1->prev;
		node1->prev = node2;
		node1->prev->next = node1;
	}
	else
	{
		node1->prev = node2p;
		node2p->next = node1;
	}

	// after prev links, modify next links

	// if node2 is tail
	if (node2n == nullptr)
	{
		node1->next = nullptr;
		this->tail = node1;
	}
	else
	{
		node1->next = node2n;
		node1->next->prev = node1;
	}
	// more adjacency case
	if (node2p == node1)
	{
		node2->next = node1;
		node2->next->prev = node2;
	}
	else
	{
		node2->next = node1n;
		node2->next->prev = node2;
	}
}
