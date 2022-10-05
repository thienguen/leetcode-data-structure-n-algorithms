#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "graphMST.h"
#include "disjointSets.h"

graphMST::graphMST():
vertexCount(0),
edgeCount(0),
title("")
{
  edges = NULL;
  mst = NULL;
}

graphMST::~graphMST()
{
  if(edges != NULL) {
    for(int i = 0; i < edgeCount; i++) {
      delete [] edges[i];
  	}
		delete [] edges;
  }
  if(mst != NULL) {
    for(int i = 0; i < vertexCount-1; i++) {
      delete [] mst[i];
    }
		delete [] mst;
  }
	edges = mst = NULL;
}

bool graphMST::readEdges(const std::string fileName)
{
  std::ifstream inFile(fileName.c_str());
  if(!inFile.is_open())
    return false;
  //get title, vertex and edge count
  std::getline(inFile, title);
  inFile >> vertexCount >> edgeCount;

  if(vertexCount < minVertices) {
    std::cout << "readEdges: Error, invalid vertex count\n";
    return false;
  }
  if(edgeCount < minEdges) {
    std::cout << "readEdges: Error, invalid edge count\n";
    return false;
  }

  //create min spanning tree array
  mst = new int*[vertexCount-1];
  for(int i = 0; i < vertexCount-1; i++)
    mst[i] = new int[3];

  //create edge array
  edges = new int*[edgeCount];
  for(int i = 0; i < edgeCount; i++)
    edges[i] = new int[3];

  //loop through and place edges into edges array
  int cnt=0;
  inFile >> edges[cnt][0] >> edges[cnt][1] >> edges[cnt][2];
  while(inFile) {
		cnt++;
    inFile >> edges[cnt][0] >> edges[cnt][1] >> edges[cnt][2];
  }
}

int graphMST::getVertexCount() const
{
  return vertexCount;
}

int graphMST::getEdgeCount() const
{
  return edgeCount;
}

void graphMST::printMST() const
{
	if(mst == NULL)
		std::cout << "printMST: Error, mst array not allocated\n";
	else {
		std::cout << "Minimum Spanning Tree:\n";
    std::cout << std::left << "  " << std::setw(10) << "Vertex:" << std::setw(10) 
							<< "Vertex:" << "Weight:\n";
		for(int i = 0; i < vertexCount-1; i++) {
      std::cout << std::right << std::setw(9) << mst[i][0] << std::setw(9) << mst[i][1] 
								<< std::setw(9) << mst[i][2] << std::endl;
		}
	}
}

std::string graphMST::getTitle() const
{
  return title;
}

void graphMST::printEdges() const
{
	if(edges == NULL) 
		std::cout << "printEdges: Error, edges array not allocated\n";
	else {
		std::cout << "Graph Edges:\n";
		std::cout << "Vertices: " << vertexCount << std::endl;
		std::cout << "Edges: " << edgeCount << std::endl;
    std::cout << std::left << "  " << std::setw(10) << "Vertex:" << std::setw(10) 
							<< "Vertex:" << "Weight:\n";
    for(int i = 0; i < edgeCount; i++) {
      std::cout << std::right << std::setw(9) << edges[i][0] << std::setw(9) << edges[i][1] 
								<< std::setw(9) << edges[i][2] << std::endl;
    }
  	std::cout << std::endl;
	}
}

void graphMST::kruskals()
{
  sort(edges, edgeCount);

	disjointSets *mst_union = new disjointSets(vertexCount);

  int j = 0;
  for(int i = 0; i < edgeCount; i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    int s1 = mst_union->setFind(u);
    int s2 = mst_union->setFind(v);
    if(s1 != s2){
			mst[j][0] = u;
      mst[j][1] = v;
      mst[j][2] = edges[i][2];
      mst_union->setUnion(s1, s2);
      j++;
    }
  }
}

void graphMST::sort(int *arr[3],int n)
{
	//selection sort
  int pos_min, tmp1, tmp2, tmp3;

  for(int i = 0; i < n-1; i++) {
    pos_min = i;

    for(int j=i+1; j < n; j++) {
      if(arr[j][2] < arr[pos_min][2])
        pos_min = j;
    }

    if(pos_min != i) {
      tmp1 = arr[i][0];
      tmp2 = arr[i][1];
      tmp3 = arr[i][2];
      arr[i][0] = arr[pos_min][0];
      arr[i][1] = arr[pos_min][1];
      arr[i][2] = arr[pos_min][2];
      arr[pos_min][0] = tmp1;
      arr[pos_min][1] = tmp2;
      arr[pos_min][2] = tmp3;
    }
  }
}
