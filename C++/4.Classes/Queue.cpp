#include "List.hpp"

/// why protected?
/// to make sure that the class is only used within the class
/// and not outside of it
/// prevent the client to use it
template <class T>
class Queue : protected List<T>
{
public:
    using reference  = typename List<T>::reference;
    using value_type = typename List<T>::value_type;

    reference front();
    reference  back();
    bool empty() const;
    void push(const value_type& value);
    void pop();
};

int main() 
{
    Queue<int> q;

    for (int i = 0; i < 10; ++i)
    {
        q.push(i);
    }

    std::cout << "front: " << q.front() << std::endl;

    while (!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }

    return EXIT_SUCCESS;
}

template <class T>
typename Queue<T>::reference Queue<T>::front()
{
    return List<T>::front();
}

template <class T>
typename Queue<T>::reference Queue<T>::back()
{
    return List<T>::back();
}

template <class T>
bool Queue<T>::empty() const
{
    return List<T>::empty();
}

template <class T>
void Queue<T>::push(const value_type& value)
{
    List<T>::insert(List<T>::end(), value);
}

template <class T>
void Queue<T>::pop()
{
    List<T>::erase(List<T>::begin());
}