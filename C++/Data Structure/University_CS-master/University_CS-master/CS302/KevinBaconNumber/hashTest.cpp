#include <iostream>
#include <string>
#include "HashList.h"

int main() 
{
    std::cout << "Testing HashList: ";
    HashList myList(503);
    myList.insert("ok");
    myList.insert("this");
    myList.insert("not this");
    myList.insert("again");

    std::cout << "finding: ok, this:\n";
    std::cout << myList.find("ok") << std::endl;
    std::cout << myList.find("this") << std::endl;
    std::cout << "viewing hash for: not this, test, temp:\n";
    return 0; 
}
