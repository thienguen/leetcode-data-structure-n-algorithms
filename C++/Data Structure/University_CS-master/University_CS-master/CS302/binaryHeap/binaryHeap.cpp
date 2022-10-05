#include <iostream>
#include <fstream>
#include <cmath>
#include "binaryHeap.h"

binaryHeap::binaryHeap(int size)
{
  count = 0;
  if(size < 100 || size > 1000)
    size = 100;

  heapSize = size;
  jobHeap = new jobElement[heapSize];
  for(int i = 0; i < heapSize; i++) {
    jobHeap[i].name = "";
    jobHeap[i].priority = 0;
  }
}

binaryHeap::~binaryHeap()
{
  if(jobHeap != NULL)
    delete [] jobHeap;
}

int binaryHeap::entries() const
{
  return count;
}

bool binaryHeap::readJobs(const std::string fileName)
{
  std::ifstream inFile(fileName.c_str());
  jobElement tmp;
  std::string title;
  std::getline(inFile, title);
  inFile >> tmp.name >> tmp.priority;
  while(inFile) {
    jobHeap[++count] = tmp;
    if(count == heapSize - 1)
      resize();
    inFile >> tmp.name >> tmp.priority;
  }
  buildHeap();
}

void binaryHeap::insert(const std::string nm, const int pri)
{
  //if our heap is too large, resize heap
  if(count == heapSize - 1)
    resize();

  jobElement newElement;
  newElement.name = nm;
  newElement.priority = pri;

  jobHeap[0] = newElement;
  reheapUp(++count);
}

bool binaryHeap::deleteMax(std::string & name, int & priority)
{
  if( isEmpty() )
    return false;

  name = jobHeap[1].name;
  priority = jobHeap[1].priority;
  jobHeap[1] = jobHeap[count--];
  reheapDown(1);
}

bool binaryHeap::isEmpty() const
{
  return count == 0;
}

void binaryHeap::printJobHeap() const
{
  int n =1;
  int cnt = 0;
  for(int i = 1; i < heapSize; i++) {
    if(jobHeap[i].name.length() > 0) {
      std::cout << jobHeap[i].name << "  " << jobHeap[i].priority << std::endl;
      ++cnt;
      if(cnt >= std::pow(2, n-1)){
        std::cout << std::endl;
        n++;
	      cnt=0;
      }
    }
  }
}

void binaryHeap::reheapUp(int hole)
{
  if(hole != 0){
    int parent = (hole)/2;
    if( jobHeap[0].priority > jobHeap[parent].priority){
      jobHeap[hole] = jobHeap[hole/2];
      reheapUp(parent);
    } else
      jobHeap[hole] = jobHeap[0];
  }
}

void binaryHeap::reheapDown(int hole)
{
  int leftChild = hole * 2;
  int rightChild = hole * 2 + 1;
  if(leftChild <= count){
    int largest = leftChild;
    if(rightChild <= count && jobHeap[largest].priority < jobHeap[rightChild].priority)
      largest = rightChild;
    if(jobHeap[hole].priority < jobHeap[largest].priority){
      jobElement tmp = jobHeap[hole];
      jobHeap[hole] = jobHeap[largest];
      jobHeap[largest] = tmp;
      reheapDown(largest);
    }
  }
}

void binaryHeap::buildHeap()
{
  for(int i = count/2; i > 0; i--)
    reheapDown( i );
}

void binaryHeap::resize()
{
  //create temporary array
  jobElement oldEntries[heapSize];
  int j = 0;
  for(int i = 0; i < heapSize; i++) {
    if(jobHeap[i].name.length() > 0){
      oldEntries[j] = jobHeap[i];
      j++;
    }
  }

  //free memory
  delete [] jobHeap;

  //double size of heap
  heapSize = heapSize * 2;
  //create new table, set all elements inside to NULL
  jobHeap = new jobElement[heapSize];
  for(int i = 0; i < heapSize; i++)
    jobHeap[i].name = "";

  for(int i = 0; i < sizeof(oldEntries) / sizeof(oldEntries[0]); i++){
    jobHeap[i] = oldEntries[i];
  }
}
