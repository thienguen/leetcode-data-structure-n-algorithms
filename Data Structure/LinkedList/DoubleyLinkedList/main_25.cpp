#include <iostream>
#include <string>
#include <fstream>
#include "pride.hpp"

using namespace std;

int main()
{
    DoublyLinkedList<string> DLL;
    DLL.insert("ge");
    DLL.insert("ge");
    DLL.insert("gg");
    DLL.print(); // should do ge -> ge -> gg
    DLL.searchDelete("ge");
    DLL.print();          // empty
    DLL.searchDelete("gg");
    // deletes all instances so both ge are gone, also gg
    DLL.print();          // empty

    std::cout << "Done" << std::endl;
    DLL.backwardsPrint(); // empty

    readData(DLL);          // read in pronouns.txt   

    std::cout << "FORWARD" << std::endl;
    DLL.print();            // should print pronouns sorted alphabeticall a->z
    cout << endl
         << endl;
    std::cout << "BACKWARD" << std::endl;
    DLL.backwardsPrint();                       // z->a reverse alphabetical
    cout << "\nPride is for everyone." << endl; // <3
    return 0;
}
