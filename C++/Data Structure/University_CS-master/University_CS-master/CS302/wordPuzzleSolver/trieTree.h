#ifndef TRIETREE_H_
#define TRIETREE_H_

#include <string>

struct trieNodeType {
  char keyValue;
  bool endWordMark;
  trieNodeType *children[26];
};

class trieTree {
  public:
    trieTree();
    ~trieTree();
    int countNodes() const;
    int height() const;
    void insert(std::string);
    bool search(std::string) const;
    bool isPrefix(std::string) const;
    void printTree() const;
    void destroyTree();
  private:
    int countNodes(trieNodeType *) const;
    int height(trieNodeType *) const;
    void destroyTree(trieNodeType *&);
    void printTree(trieNodeType *) const;
    trieNodeType *root;
};

#endif
