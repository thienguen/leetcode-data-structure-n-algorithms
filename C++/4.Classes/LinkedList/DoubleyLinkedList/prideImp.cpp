
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

template <class T>

class Node
{
    T data;
    Node *next;
    Node *prev;

public:
    Node<T>()
    {
        prev = next = nullptr;
    }

    Node<T>(T item)
    {
        data = item;
        prev = next = nullptr;
    }
};

template <class T>
class DoublyLinkedList
{

    Node<T> *head;
    Node<T> *tail;

public:
    DoublyLinkedList<T>()
    {
        head = tail = nullptr;
    }

    void insert(T item)
    {
        Node<T> *newNode = new Node<T>(item);

        if (head == nullptr && tail == nullptr)
        {
            head = tail = newNode;
            return;
        }

        if (item < head->data)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;

            return;
        }

        Node<T> *curr = head;
        while (curr->next != nullptr)
        {
            if (item < curr->next->data)
            {
                newNode->prev = curr;
                newNode->next = curr->next;
                curr->next->prev = newNode;
                curr->next = newNode;
                return;
            }

            curr = curr->next;
        }

        newNode->prev = curr;
        curr->next = newNode;
        tail = newNode;

        curr->next = newNode;
    }

    void searchDelete(T search_item)
    {
        if (head == nullptr)
            return;

        Node<T> *temp = head;

        while (temp != nullptr)
        {
            if (temp->data == search_item)
            {
                if (temp == head)
                {
                    head = temp->next;
                    if (head != nullptr)
                        head->prev = nullptr;
                    else
                        tail = nullptr;

                    delete temp;
                    temp = head;
                }
                else if (temp == tail)
                {
                    tail = tail->prev;
                    if (tail != nullptr)
                        tail->next = nullptr;

                    delete temp;
                    temp = nullptr;
                }
                else
                {
                    if (temp->next != nullptr)
                        temp->next->prev = temp->prev;
                    if (temp->prev != nullptr)
                        temp->prev->next = temp->next;

                    Node<T> *tmp = temp->next;
                    delete temp;
                    temp = tmp;
                }
                continue;
            }

            if (temp != nullptr)
                temp = temp->next;
        }
    }

    void print()
    {

        if (head == nullptr)
        {
            std::cout << ".\n";
            return;
        }

        Node<T> *curr = head;
        while (curr->next != nullptr)
        {
            cout << curr->data << " -> ";
            curr = curr->next;
        }

        cout << curr->data << " -> ." << endl;
    }

    void backwardsPrint()
    {

        if (tail == nullptr)
        {
            std::cout << ".\n";
            return;
        }

        Node<T> *curr = tail;
        while (curr->prev != nullptr)
        {
            cout << curr->data << " -> ";
            curr = curr->prev;
        }

        cout << curr->data << " -> ." << endl;
    }

    ~DoublyLinkedList<T>()
    {
        Node<T> *temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

template <class T>
void readData(DoublyLinkedList<T> &DLL)
{
    ifstream iFile("pronouns.txt");

    string input = "";
    while (iFile >> input)
    {
        if (input == "Source:")
        {
            return;
        }
        DLL.insert(input);
    }
}
