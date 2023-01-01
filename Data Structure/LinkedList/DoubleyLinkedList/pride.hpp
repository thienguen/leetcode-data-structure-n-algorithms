/// @author: Thien Nguyen
/// @date: Finished by 
/// @note: Time spent in debugging: 

#ifndef PRIDE_HPP
#define PRIDE_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

template <typename T>
class DoublyLinkedList
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node* prev;
    };

protected:
    Node* head;
    Node* tail;
    size_t size;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~DoublyLinkedList() 
    {
        if (head == nullptr)
        {
            tail = nullptr;
        }
        else
        {
            Node *temp;

            while (head != tail)
            {
                temp = head->next;
                delete head;
                head = temp;
            }

            delete head;
            tail = head = nullptr;
            size = 0;
        }
    }

    void insert(T data)
    {
        // traverse the list and insert the new node in the correct position
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            Node* temp = head;
            while (temp != nullptr)
            {
                if (temp->data >= data)
                {
                    if (temp == head)
                    {
                        newNode->next = head;
                        head->prev = newNode;
                        head = newNode;
                        break;
                    }
                    else
                    {
                        newNode->next = temp;
                        newNode->prev = temp->prev;
                        temp->prev->next = newNode;
                        temp->prev = newNode;
                        break;
                    }
                }
                else if (temp->next == nullptr)
                {
                    temp->next = newNode;
                    newNode->prev = temp;
                    tail = newNode;
                    break;
                }
                temp = temp->next;
            }
        }
    }

    void print()
    {
        if (!isEmpty())
        {
            Node* temp = head;
            int count = 0;
            while (temp != tail->next)
            {
                if (count % 5 == 0 && count != 0)
                {
                    std::cout << std::endl;
                }
                count++;
                if (temp == tail)
                {
                    std::cout << temp->data;
                }
                else
                {
                    std::cout << temp->data << " -> ";
                }
                temp = temp->next;
            }
            std::cout << std::endl;
        }
    }

    void backwardsPrint()
    {
        if (!isEmpty())
        {
            Node* temp = tail;
            int count = 0;
            while (temp != head->prev)
            {
                if (count % 5 == 0 && count != 0)
                {
                    std::cout << std::endl;
                }
                count++;
                if (temp == head)
                {
                    std::cout << temp->data;
                }
                else
                {
                    std::cout << temp->data << " -> ";
                }
                temp = temp->prev;
            }
            std::cout << std::endl;
        }
    }

    // find and delete all target in the list
    void searchDelete(T target)
    {
        if (head == nullptr)
            return;
        
        Node* temp = head;
        
        while (temp != nullptr)
        {
            if (temp->data == target)
            {
                if (temp == head)
                {
                    head = temp->next;

                    if (head != nullptr)
                        head->prev = nullptr;
                    delete temp;
                    temp = head;
                    size--;
                }
                else if (temp == tail)
                {
                    tail = temp->prev;
                    tail->next = nullptr;
                    delete temp;
                    temp = nullptr;
                    size--;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;

                    Node* temp2 = temp;
                    temp = temp->next;
                    delete temp2;
                    size--;
                }
                continue;
            }
            temp = temp->next;
        }
    }

    bool findTarget(T target)
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            if (temp->data == target)
                return true;
            temp = temp->next;
        }
        return false;
    }

    bool isEmpty()
    {
        return (head == nullptr);
    }


    size_t getSize()
    {
        return size;
    }
};

void readData(DoublyLinkedList<std::string>& DLL)
{
    std::ifstream file;
    std::string fileName = "pronouns.txt";
    file.open(fileName);

    if (file.is_open())
    {
        std::string line;
        while (file >> line)
        {
            DLL.insert(line);
        }
        file.close();
    }
}

#endif  // PRIDE_HPP