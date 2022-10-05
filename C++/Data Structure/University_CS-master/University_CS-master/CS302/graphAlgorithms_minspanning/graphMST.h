#ifndef GRAPHMST_H_
#define GRAPHMST_H_

#include <string>
#include "disjointSets.h"

class graphMST
{
  public:
    graphMST();
    ~graphMST();
    bool readEdges(const std::string);
    int getVertexCount() const;
    int getEdgeCount() const;
    void printMST() const;
    void printEdges() const;
    std::string getTitle() const;
    void kruskals();
  private:
    std::string title;
    int vertexCount;
    int edgeCount;

    int **edges;
    int **mst;

    static const int minEdges=5;
    static const int minVertices=5;

    void sort(int *[3], int);
};

#endif
