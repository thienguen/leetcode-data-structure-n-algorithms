#include "Circular_Linked_List.h"
#include "Node.h"
#include <iostream>

Circular_Linked_Lists::Circular_Linked_Lists(int data) : data(data)
{
    Node *new_node = new Node(data);
    head = tail = new_node;
}

void Circular_Linked_Lists::add_node_head(int data)
{
    Node *new_node = new Node(data, head);
    head = new_node;
    tail->next_node = head;

}

void Circular_Linked_Lists::add_node_tail(int data)
{
    Node *new_node = new Node(data);
    tail->next_node = new_node;
    tail = new_node;
    tail->next_node = head;

}

void Circular_Linked_Lists::add_after_node(int data, int data_after)
{
    Node *curr_node = head;
    while (curr_node->data != data_after)
    {
        curr_node = curr_node->next_node;
    }

    Node *new_node = new Node(data, curr_node->next_node);

    curr_node->next_node = new_node;

    if (curr_node == tail)
    {
        tail = new_node;
        tail->next_node = head;
    }

}

void Circular_Linked_Lists::add_before_node(int data, int data_before)
{
    Node *curr_node = head;
    if (head->data != data_before)
    {
        while ((curr_node->next_node)->data != data_before)
        {
            curr_node = curr_node->next_node;
        }
        Node *new_node = new Node(data, curr_node->next_node);
        curr_node->next_node = new_node;
    }
    else
        add_node_head(data);
}

void Circular_Linked_Lists::remove_node_head()
{
    Node *curr_node = head;
    head = curr_node->next_node;
    delete curr_node;
    tail->next_node = head;

}

void Circular_Linked_Lists::remove_node_tail()
{
    Node *curr_node = head;
    while (curr_node->next_node != tail)
    {
        curr_node = curr_node->next_node;
    }
    delete tail;
    tail = curr_node;
    tail->next_node = head;
}

void Circular_Linked_Lists::remove_after_node(int data_after)
{
    Node *curr_node = head;
    while (curr_node->data != data_after)
    {
        curr_node = curr_node->next_node;

    }
    Node *node_remove = curr_node->next_node;
    curr_node->next_node = (node_remove)->next_node;

    if (curr_node == tail)
    {
        head = curr_node->next_node;
    }

    delete node_remove;
}

void Circular_Linked_Lists::remove_before_node(int data_before)
{
    Node *curr_node = head;

    while (((curr_node->next_node)->next_node)->data != data_before)
    {
        curr_node = curr_node->next_node;
    }
    Node *node_remove = curr_node->next_node;

    curr_node->next_node = node_remove->next_node;

    if (node_remove == head)
    {
        head = node_remove->next_node;
    }
    else if (node_remove == tail)
    {
        tail = curr_node;
    }

    delete node_remove;
}

void Circular_Linked_Lists::remove_node_data(int data_remove)
{
    Node *curr_node = head;
    while ((curr_node->next_node)->data != data_remove)
    {
        curr_node = curr_node->next_node;
    }

    Node *node_remove = curr_node->next_node;
    curr_node->next_node = node_remove->next_node;

    delete node_remove;
}

void Circular_Linked_Lists::remove_numbered_node(int node_no)
{
    Node *curr_node = head;
    int node = 1;
    while (node != (node_no - 1))
    {
        curr_node = curr_node->next_node;
        ++node;
    }

    Node *node_remove = curr_node->next_node;
    curr_node->next_node = node_remove->next_node;
    delete node_remove;

}

int Circular_Linked_Lists::total_nodes()
{
    Node *curr_node = head;
    int counter = 0;

    while (curr_node != 0)
    {
        ++counter;
        curr_node = curr_node->next_node;
    }
    delete curr_node;
    return counter;
}

int Circular_Linked_Lists::total_nodes_given_data(int given_data)
{
    Node *curr_node = head;
    int counter = 0;

    while (curr_node != 0)
    {
        if (curr_node->data == given_data)
            ++counter;
        curr_node = curr_node->next_node;
    }

    delete curr_node;
    return counter;
}

void Circular_Linked_Lists::display_linked_list()
{
    std::cout << "\nLinked list : ";
    Node *curr_node = head;

    while (curr_node != 0)
    {
        std::cout << "\n"
                  << curr_node << "   " << curr_node->data << "   " << curr_node->next_node;
        curr_node = curr_node->next_node;
    }

    delete curr_node;
}

void Circular_Linked_Lists::reverse_linked_list()
{
    if (head)
        if (head != tail)
        {
            Node *curr_node;
            Node *temp_node = head;
            tail = head;
            curr_node = temp_node->next_node;
            head->next_node = 0;
            while (temp_node != 0)
            {
                temp_node = curr_node->next_node;
                curr_node->next_node = head;
                head = curr_node;
                curr_node = temp_node;
            }
        }

}

void Circular_Linked_Lists::selection_sort()
{
    if (head != 0)
        if (head != tail)
            for (Node *i = head; i != 0; i = i->next_node)
                for (Node *j = i->next_node; j != 0; j = j->next_node)
                    if (j->data < i->data)
                    {
                        int temp = i->data;
                        i->data = j->data;
                        j->data = temp;
                    }
}

void Circular_Linked_Lists::join_linked_lists(Circular_Linked_Lists *obj)
{
    tail->next_node = obj->head;
    this->tail = obj->tail;
    std::cout << "\n"
              << tail->data 
              << "   " 
              << tail 
              << "\n";

}

Circular_Linked_Lists::~Circular_Linked_Lists()
{
    std::cout << "\nlinked list destroyed...";
}