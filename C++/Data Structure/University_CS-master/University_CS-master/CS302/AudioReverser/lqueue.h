#ifndef LQUEUE_H_
#define LQUEUE_H_

template <class myType>
struct queueNode {
  myType dataSet[SIZE];
  int front, back;
  queueNode<myType> *link;
};

template <class myType>
class linkedQueue {
  public:
    linkedQueue();
    ~linkedQueue();
    bool isEmptyQueue() const;
    void initializeQueue();
    void addItem(const myType& newItem);
    myType front() const;
    myType back() const;
    void deleteItem();
    int queueCount();
    void printQueue();
  private:
    queueNode<myType> *queueFront;
    queueNode<myType> *queueRear;
    int count;
};

template <class myType>
linkedQueue<myType>::linkedQueue()
{
  queueFront = NULL;
  queueRear = NULL;
  count = 0;
}

template <class myType>
linkedQueue<myType>::~linkedQueue()
{
  while(queueFront != NULL) {
    queueNode<myType> *toDelete = queueFront;
    queueFront = queueFront->link;
    delete toDelete;
  }
}

template <class myType>
bool linkedQueue<myType>::isEmptyQueue() const
{
  return count == 0;
}

template <class myType>
void linkedQueue<myType>::initializeQueue()
{
  if(count > 0) {
    while(queueFront != NULL) {
      queueNode<myType> *toDelete = queueFront;
      queueFront = queueFront->link;
      delete toDelete;
    }
  }
  count = 0;
  queueFront = NULL;
  queueRear = NULL;
}

template <class myType>
void linkedQueue<myType>::addItem(const myType& newItem)
{
  if(count % SIZE == 0 && count != 0) {
    queueNode<myType> *newNode = new queueNode<myType>;
    newNode->front = 0;
    newNode->back = 0;
    newNode->link = NULL;
    queueRear->link = newNode;
    queueRear = newNode;
  }else if(queueRear == NULL){
    queueNode<myType> *newNode = new queueNode<myType>;
    newNode->front = 0;
    newNode->back = 0;
    newNode->link = NULL;
    if(queueFront == NULL) {
      queueFront = newNode;
    } else {
      queueRear->link = newNode;
    }
    queueRear = newNode;
  }
  queueRear->dataSet[queueRear->back%SIZE] = newItem;
  count++;
  queueRear->back++;
}

template <class myType>
myType linkedQueue<myType>::front() const
{
  return queueFront->dataSet[queueFront->front%SIZE];
}

template <class myType>
myType linkedQueue<myType>::back() const
{
  return queueRear->dataSet[(queueRear->back-1)%SIZE];
}

template <class myType>
void linkedQueue<myType>::deleteItem()
{
  queueFront->front++;
  if(queueFront->front%SIZE == queueFront->back%SIZE) {
    queueNode<myType> *toDelete;
    toDelete = queueFront;
    queueFront = queueFront->link;
    delete toDelete;
  }
  count--;
}

template <class myType>
int linkedQueue<myType>::queueCount()
{
  return count;
}

template <class myType>
void linkedQueue<myType>::printQueue()
{
  queueNode<myType> *iterNode = queueFront;
  while(iterNode != NULL) {
      for(int i = iterNode->front; i < (iterNode->back - iterNode->front); i++) {
        std::cout << iterNode->dataSet[i%SIZE];
      }
      iterNode = iterNode->link;
  }
}

#endif
