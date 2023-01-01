#ifndef BINARYHEAP_H_
#define BINARYHEAP_H_

#include <string>

class binaryHeap
{
public:
	/* Default */
	~binaryHeap();
	binaryHeap(int = 100);
	
	/* Accessors */
	int entries() const;
	bool readJobs(const std::string);
	void insert(const std::string, const int);
	bool isEmpty() const;
	bool deleteMax(std::string &, int &);
	void printJobHeap() const;

private:
	
	/* Node of the heap */
	struct jobElement
	{
		int priority;
		std::string name;
	};

	/* Attributes */
	int count;
	int heapSize;
	jobElement *jobHeap;

	/* Ah yes, def not PQ, but the damn heap */
	void resize();
	void buildHeap();
	void reheapUp(int);
	void reheapDown(int);
};

#endif
