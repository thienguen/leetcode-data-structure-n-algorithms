#ifndef LSTACK_H
#define LSTACK_H

#define SIZE 32000

#include <iostream>

template <typename T>
struct nodeType
{
	T dataSet[SIZE];
	int top;
	nodeType<T> *link;
};

template <typename T>
class linkedStack
{
public:
	/* Default */
	linkedStack();
	~linkedStack();

	/* Helper Funcs */
	int stackCount();
	bool isEmptyStack() const;
	void initializeStack();

	/* Stack Properties */	
	T top() const;
	void push(const T &newItem);
	void pop();

private:
	int count;
	nodeType<T> *stackTop;
};

template <typename T>
linkedStack<T>::linkedStack()
{
	stackTop = nullptr;
	count = 0;
}

template <typename T>
linkedStack<T>::~linkedStack()
{
	// cycle through all existing nodes and free memory
	while (stackTop != nullptr)
	{
		nodeType<T> *toDelete = stackTop;
		stackTop = stackTop->link;
		delete toDelete;
	}
}

template <typename T>
bool linkedStack<T>::isEmptyStack() const
{
	// return true if stack has no items
	return count == 0;
}

template <typename T>
void linkedStack<T>::initializeStack()
{
	// if the list has anything in it, clear
	if (count > 0 || stackTop != nullptr)
	{
		while (stackTop != nullptr)
		{
			nodeType<T> *toDelete = stackTop;
			stackTop = stackTop->link;
			delete toDelete;
		}
	}
	count = 0;
	stackTop = nullptr;
}

template <typename T>
int linkedStack<T>::stackCount()
{
	return count;
}

template <typename T>
void linkedStack<T>::push(const T &newItem)
{
	// if a new node needs to be created
	if (count % SIZE == 0)
	{
		nodeType<T> *newNode = new nodeType<T>;
		newNode->top = 0;
		newNode->link = stackTop;
		stackTop = newNode;
	}
	stackTop->dataSet[stackTop->top] = newItem;
	count++;
	stackTop->top++;
}

template <typename T>
T linkedStack<T>::top() const
{
	return stackTop->dataSet[stackTop->top - 1];
}

template <typename T>
void linkedStack<T>::pop()
{
	stackTop->top--;
	if (stackTop->top == 0)
	{
		nodeType<T> *toDelete = stackTop;
		stackTop = stackTop->link;
		delete toDelete;
	}
	count--;
}

#endif
