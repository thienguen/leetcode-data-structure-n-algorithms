#ifndef WORDPUZZLE_H_
#define WORDPUZZLE_H_

#include "avlTree.h"
#include <string>

class wordPuzzle: public avlTree<std::string> {
  public:
    wordPuzzle();
    ~wordPuzzle();
    bool readLetters(const std::string);
    bool readDictionary(const std::string);
    void findWords();
    void showTitle() const;
    void showWordCount() const;
    void showWords() const;
    void printLetters() const;
    void findWords(int, int, std::string);
  private:
    std::string title;
    int order;
    std::string **letters;
    avlTree<std::string> wordsFound;
};

#endif
