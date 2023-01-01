#include <iostream>
#include "pride.hpp"

int main()
{
    DoublyLinkedList<int> DLL;
    DLL.insert(5);
    DLL.insert(2);
    DLL.insert(8);
    DLL.insert(7);
    DLL.insert(7);
    DLL.insert(8);
    DLL.insert(9);
    DLL.print();
    DLL.searchDelete(2);
    DLL.print();
    DLL.searchDelete(9);
    DLL.print();
    DLL.searchDelete(7);
    DLL.print();
    DLL.insert(7);
    DLL.searchDelete(7);
    DLL.searchDelete(5);
    DLL.searchDelete(8);
    DLL.insert(7);
    DLL.print();
    DLL.backwardsPrint();
    return 0;
}
