#include <iostream>
#include <fstream>
#include "stack.h"
#include "lqueue.h"

int main(int argc, char* argv[])
{
  if(argc != 3) {
    std::cout << "invalid arguments" << std::endl;
    return 1;
  }

  std::ifstream inFile(argv[1]);
  std::ofstream outFile(argv[2]);
  if(!inFile.is_open()) {
    std::cout << "invalid input file" << std::endl;
  }
  if(!outFile.is_open()) {
    std::cout << "invalid output file" << std::endl;
  }

  std::string col1, col2, junk1, junk2;
  std::getline(inFile,junk1);
  std::getline(inFile,junk2);
  linkedQueue<std::string> column1;
  linkedStack<std::string> column2;
  linkedQueue<std::string> column2rev;
  inFile >> col1 >> col2;
  while(inFile) {
    column1.addItem(col1);
    column2.push(col2);
    inFile >> col1 >> col2;
  }
  while(!column2.isEmptyStack()) {
    column2rev.addItem(column2.top());
    column2.pop();
  }

  outFile << junk1 << std::endl << junk2 << std::endl;
  while(!column2rev.isEmptyQueue() && !column1.isEmptyQueue()) {
    outFile << column1.front() << " " << column2rev.front() << std::endl;
    column1.deleteItem();
    column2rev.deleteItem();
  }
  outFile.close();
}
