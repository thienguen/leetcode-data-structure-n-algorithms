#include <iostream>
#include "LinkedList.h"
#include <string>

int main()
{
    LinkedList myList;
    myList.insertTail("ok");
    myList.insertTail("another");
    std::cout << "Searching for 'ok': " << myList.search("ok") << std::endl;
    std::cout << "Searching for 'notfound' : " << myList.search("notfound") << std::endl;
    return 0;
}
