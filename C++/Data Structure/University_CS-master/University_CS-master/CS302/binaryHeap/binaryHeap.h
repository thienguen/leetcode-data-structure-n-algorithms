#ifndef BINARYHEAP_H_
#define BINARYHEAP_H_

#include <string>

class binaryHeap
{
  public:
    binaryHeap(int=100);
    ~binaryHeap();
    int entries() const;
    bool readJobs(const std::string);
    void insert(const std::string, const int);
    bool deleteMax(std::string &, int &);
    bool isEmpty() const;
    void printJobHeap() const;
  private:
    struct jobElement {
      int priority;
      std::string name;
    };
    int count;
    int heapSize;
    jobElement *jobHeap;

    void reheapUp(int);
    void reheapDown(int);
    void buildHeap();
    void resize();
};

#endif
