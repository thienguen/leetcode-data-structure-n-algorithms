#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "avlTree.h"
#include "wordPuzzle.h"

wordPuzzle::wordPuzzle()
{
  //init private variables
  title = "";
  order = 0;
  letters = NULL;
}

wordPuzzle::~wordPuzzle()
{
  //free dynamically allocated memory
  if(letters != NULL) {
    for(int i = 0; i < sizeof(letters) / sizeof(std::string *); i++) {
        delete [] letters[i];
    }
    delete [] letters;
  }
}

bool wordPuzzle::readLetters(const std::string word)
{
  std::ifstream inFile(word.c_str());
  if(!inFile.is_open())
    return false;
  //get title and order
  std::getline(inFile, title);
  inFile >> order;
  //allocate letters
  letters = new std::string*[order];
  for(int i = 0; i < order; i++)
    letters[i] = new std::string[order];
  //read in letters to dynamic array
  for(int i = 0; i < order; i++) {
    for(int j = 0; j < order; j++) {
      inFile >> letters[i][j];
    }
  }
  inFile.close();
  return true;
}

bool wordPuzzle::readDictionary(const std::string word)
{
  //read every line in dictionary and place in trie
  //data structure
  std::ifstream inFile(word.c_str());
  if(!inFile.is_open())
    return false;
  //create temp string to read in dictionary
  std::string tempRead;
  while(inFile >> tempRead) {
    //ensure only lowercase words are grabbed
    if(islower(tempRead[0]))
      insert(tempRead);
  }
  inFile.close();
  return true;
}

void wordPuzzle::findWords()
{
  //find all possible words in puzzle
  for(int i = 0; i < order; i++)
    for(int j = 0; j < order; j++)
      findWords(i,j,"");
}

void wordPuzzle::showTitle() const
{
  //display title
  std::cout << title << std::endl;
}

void wordPuzzle::showWordCount() const
{
  //diplay word count
  std::cout << "Word Count: " <<
    wordsFound.countNodes() << std::endl;
}

void wordPuzzle::showWords() const
{
  //call private print function
  wordsFound.printTree(INORDER);
}

void wordPuzzle::printLetters() const
{
  std::cout << std::endl;
  //each cell will be 3 spaces wide, and 3 long.
  for(int i = 0; i < order*3 + 1; i++) {
    for(int j = 0; j < order*4 + 1; j++) {
      if(i == 0) {
        if(j == 0 || j == order*4){
          std::cout << " ";
        }else{
          std::cout << "_";
        }
      }
      else if(j % 4 == 0 || j == order*4) {
        std::cout << "|";
      }else if(i % 3 == 0 && i != 0){
        std::cout << "_";
      }else if(j % 2 == 0 && (i % 3 != 0 && i % 3 != 1)){
        std::cout << letters[i/4][j/4];
      }else if(i % 3 != 0){
        std::cout << " ";
      }
    }
    std::cout << std::endl;
  }
}

void wordPuzzle::findWords(int i, int j, std::string wrd)
{
  //check input i + j;
  if(i >= order || i < 0 || j >= order
     || j < 0)
     return;
  if(letters[i][j] == "-")
    return;

  //att letter to word
  wrd = wrd + letters[i][j];
  if(!isPrefix(wrd))
    return;
  //if word exists, add to avl tree
  if(search(wrd)) {
    std::stringstream ss;
    ss << std::left << std::setw(15)
       << wrd << "from: (" << i
       << "," << j << ")\n";
    wordsFound.insert(ss.str());
  }
  //grab temp letter and move onto other combinations
  std::string tmpLter = letters[i][j];
  letters[i][j] = "-";
  //call findWords with all possible words around it
  findWords(i+1,j,wrd);
  findWords(i-1,j,wrd);
  findWords(i,j+1,wrd);
  findWords(i,j-1,wrd);
  findWords(i+1,j+1,wrd);
  findWords(i-1,j-1,wrd);
  findWords(i+1,j-1,wrd);
  findWords(i-1,j+1,wrd);
  letters[i][j] = tmpLter;

}
