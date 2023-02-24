#ifndef VERTEX_H_
#define VERTEX_H_

template <class T>
class vertex
{
	struct node
	{
		T item;
		node *link;
	};

public:
	class edgeIterator
	{
	public:
		friend class vertex;
		edgeIterator();
		edgeIterator(node *);
		edgeIterator operator++(int);
		T operator*();
		bool operator==(const edgeIterator &);
		bool operator!=(const edgeIterator &);

	private:
		node *current;
	};

	/* Default */
	vertex();
	~vertex();
	vertex(const vertex<T> &);

	/* Overload */
	const vertex &operator=(const vertex<T> &);
	
	/* Characteristics */
	edgeIterator begin();
	edgeIterator end();
	void addEdge(const T &);

private:
	node *neighbors;
};

template <class T>
vertex<T>::vertex()
{
	neighbors = nullptr;
}

template <class T>
vertex<T>::vertex(const vertex<T> &copy)
{
	neighbors = new node;
	neighbors->item = copy.neighbors->item;
	neighbors->link = new node;

	auto *current = neighbors->link;
	auto *current_copy = copy.neighbors->link;
	while (current != nullptr)
	{

		current->item = current_copy->item;

		current_copy = current_copy->link;

		if (current_copy != nullptr)
		{
			current->link = new node;
		}
		else
		{
			current->link = nullptr;
		}
		current = current->link;
	}
}

template <class T>
const vertex<T> &vertex<T>::operator=(const vertex<T> &rhs)
{
	if (neighbors != nullptr)
	{
		auto it = this->begin();
		while (it != nullptr)
		{
			delete it.current;
			it++;
		}
	}

	neighbors = new node;
	neighbors->item = rhs.neighbors->item;
	neighbors->link = new node;

	auto current = neighbors->link;
	auto current_copy = rhs.neighbors->link;
	while (current != nullptr)
	{

		current->item = current_copy->item;

		current_copy = current_copy->link;

		if (current_copy != nullptr)
		{
			current->link = new node;
		}
		else
		{
			current->link = nullptr;
		}
		current = current->link;
	}

	return *this;
}

template <class T>
vertex<T>::~vertex()
{
	auto it = this->begin();
	while (it != nullptr)
	{
		delete it.current;
		it++;
	}
}

template <class T>
typename vertex<T>::edgeIterator vertex<T>::begin()
{
	return this->neighbors;
}

template <class T>
typename vertex<T>::edgeIterator vertex<T>::end()
{
	return nullptr;
}

template <class T>
void vertex<T>::addEdge(const T &data)
{
	node *new_node = new node;

	new_node->item = data;
	new_node->link = nullptr;
	if (this->neighbors == nullptr)
	{
		this->neighbors = new_node;
	}
	else
	{
		new_node->link = this->neighbors;
		this->neighbors = new_node;
	}
}

template <class T>
vertex<T>::edgeIterator::edgeIterator()
{
	current = nullptr;
}

template <class T>
vertex<T>::edgeIterator::edgeIterator(node *rhs)
{
	current = rhs;
}

template <class T>
typename vertex<T>::edgeIterator vertex<T>::edgeIterator::operator++(int)
{
	current = current->link;
	return *this;
}

template <class T>
T vertex<T>::edgeIterator::operator*()
{
	return this->current->item;
}

template <class T>
bool vertex<T>::edgeIterator::operator==(const edgeIterator &rhs)
{
	return (this->current == rhs.current);
}

template <class T>
bool vertex<T>::edgeIterator::operator!=(const edgeIterator &rhs)
{
	return (this->current != rhs.current);
}

#endif // VERTEX_H_
