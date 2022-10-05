#ifndef STACK_H_
#define STACK_H_

#define SIZE 32000
#include <iostream>

template <class myType>
struct nodeType {
  myType dataSet[SIZE];
  int top;
  nodeType<myType> *link;
};

template <class myType>
class linkedStack {
  public:
    linkedStack();
    ~linkedStack();
    bool isEmptyStack() const;
    void initializeStack();
    int stackCount();
    void push(const myType& newItem);
    myType top() const;
    void pop();
  private:
    nodeType<myType> *stackTop;
    int count;
};

template <class myType>
linkedStack<myType>::linkedStack()
{
  stackTop = NULL;
  count = 0;
}

template <class myType>
linkedStack<myType>::~linkedStack()
{
  //cycle through all existing nodes and free memory
  while(stackTop != NULL) {
    nodeType<myType>* toDelete = stackTop;
    stackTop = stackTop->link;
    delete toDelete;
  }
}

template <class myType>
bool linkedStack<myType>::isEmptyStack() const
{
  //return true if stack has no items
  return count == 0;
}

template <class myType>
void linkedStack<myType>::initializeStack()
{
  //if the list has anything in it, clear
  if(count > 0 || stackTop != NULL) {
    while(stackTop != NULL) {
      nodeType<myType>* toDelete = stackTop;
      stackTop = stackTop->link;
      delete toDelete;
    }
  }
  count = 0;
  stackTop = NULL;
}

template <class myType>
int linkedStack<myType>::stackCount()
{
  return count;
}

template <class myType>
void linkedStack<myType>::push(const myType& newItem)
{
    //if a new node needs to be created
    if(count % SIZE == 0) {
      nodeType<myType> *newNode = new nodeType<myType>;
      newNode->top = 0;
      newNode->link = stackTop;
      stackTop = newNode;
    }
    stackTop->dataSet[stackTop->top] = newItem;
    count++;
    stackTop->top++;
}

template <class myType>
myType linkedStack<myType>::top() const
{
  return stackTop->dataSet[stackTop->top-1];
}

template <class myType>
void linkedStack<myType>::pop()
{
  stackTop->top--;
  if(stackTop->top == 0) {
    nodeType<myType> *toDelete = stackTop;
    stackTop = stackTop->link;
    delete toDelete;
  }
  count--;
}

#endif
