#ifndef LQUEUE_H
#define LQUEUE_H

#define SIZE 32000

template <typename T>
struct queueNode
{
	T dataSet[SIZE];
	int front, back;
	queueNode<T> *link;
};

template <typename T>
class linkedQueue
{
public:
	/* Default */
	linkedQueue();
	~linkedQueue();

	/* Helper Funcs */
	int queueCount();
	void initializeQueue();
	bool isEmptyQueue() const;
	void addItem(const T &newItem);
	void deleteItem();
	
	/* Queue Properties */
	T front() const;
	T back() const;
	
	/* Print */
	void printQueue();

private:
	int count;
	queueNode<T> *queueFront;
	queueNode<T> *queueRear;
};

template <typename T>
linkedQueue<T>::linkedQueue()
{
	queueFront = nullptr;
	queueRear = nullptr;
	count = 0;
}

template <typename T>
linkedQueue<T>::~linkedQueue()
{
	while (queueFront != nullptr)
	{
		queueNode<T> *toDelete = queueFront;
		queueFront = queueFront->link;
		delete toDelete;
	}
}

template <typename T>
bool linkedQueue<T>::isEmptyQueue() const
{
	return count == 0;
}

template <typename T>
void linkedQueue<T>::initializeQueue()
{
	if (count > 0)
	{
		while (queueFront != nullptr)
		{
			queueNode<T> *toDelete = queueFront;
			queueFront = queueFront->link;
			delete toDelete;
		}
	}
	count = 0;
	queueFront = nullptr;
	queueRear = nullptr;
}

template <typename T>
void linkedQueue<T>::addItem(const T &newItem)
{
	if (count % SIZE == 0 && count != 0)
	{
		queueNode<T> *newNode = new queueNode<T>;
		newNode->front = 0;
		newNode->back = 0;
		newNode->link = nullptr;
		queueRear->link = newNode;
		queueRear = newNode;
	}
	else if (queueRear == nullptr)
	{
		queueNode<T> *newNode = new queueNode<T>;
		newNode->front = 0;
		newNode->back = 0;
		newNode->link = nullptr;
		if (queueFront == nullptr)
		{
			queueFront = newNode;
		}
		else
		{
			queueRear->link = newNode;
		}
		queueRear = newNode;
	}
	queueRear->dataSet[queueRear->back % SIZE] = newItem;
	count++;
	queueRear->back++;
}

template <typename T>
T linkedQueue<T>::front() const
{
	return queueFront->dataSet[queueFront->front % SIZE];
}

template <typename T>
T linkedQueue<T>::back() const
{
	return queueRear->dataSet[(queueRear->back - 1) % SIZE];
}

template <typename T>
void linkedQueue<T>::deleteItem()
{
	queueFront->front++;
	if (queueFront->front % SIZE == queueFront->back % SIZE)
	{
		queueNode<T> *toDelete;
		toDelete = queueFront;
		queueFront = queueFront->link;
		delete toDelete;
	}
	count--;
}

template <typename T>
int linkedQueue<T>::queueCount()
{
	return count;
}

template <typename T>
void linkedQueue<T>::printQueue()
{
	queueNode<T> *iterNode = queueFront;
	while (iterNode != nullptr)
	{
		for (int i = iterNode->front; i < (iterNode->back - iterNode->front); i++)
		{
			std::cout << iterNode->dataSet[i % SIZE];
		}
		iterNode = iterNode->link;
	}
}

#endif
