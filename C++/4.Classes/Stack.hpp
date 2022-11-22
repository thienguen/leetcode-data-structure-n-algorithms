/// file "Stack.hpp"
/// @author Thien Nguyen thiennguyen@.csn.edu

#include "List.hpp"

template <class T>
class Stack : protected List<T>
{
public:
    // member types
    using value_type = T;
    using reference = T &;

    reference top() { return List<T>::front(); }
    bool empty() const { return List<T>::empty(); }

    void push(const value_type &value)
    {
        List<T>::insert(List<T>::begin(), value);
    }

    void pop()
    {
        if (!empty())
        {
            List<T>::erase(List<T>::begin());
        }
    }
};

/// ouput our linked list
/// @param output pass by reference to output
/// @param list the list contain the data

template <class T>
std::ostream &operator<<(std::ostream &output, Stack<T> stack);

/// @paragraph This function will write ouput the entire stack
/// @param output pass by reference to output
/// @param stack the stack contain the data
/// @return output

template <class T>
std::ostream &operator<<(std::ostream &output, Stack<T> stack)
{
    std::string separator[2]{};

    output << "top -> ";

    while (!stack.empty())
    {
        std::cout << *separator << stack.top();
        stack.pop();
        *separator = " -> ";

        if (stack.empty())
        {
            output << " -> ";
        }
    }

    return output << "nullptr";
}
