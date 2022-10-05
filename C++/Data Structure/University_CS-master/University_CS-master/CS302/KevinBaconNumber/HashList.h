#ifndef HASHLIST_H_
#define HASHLIST_H_

#include <string>
#include "LinkedList.h"

class HashList {
  public:
    HashList(int tblsize=503);
    ~HashList();

    //const member functions
    int hashCount() const;
    int showHash(std::string) const;
    int getTableSize() const;

    //mutable functions
    int find(const std::string);
    bool insert(const std::string);
    bool remove(const std::string);
    
    void reinitList();
  private:
    int hash(const std::string) const;
    void rehash();

    static const float d_loadfactor = 0.65;
    LinkedList *d_hashtbl;
    int d_tblcount;
    int d_tblsize;
};

#endif
