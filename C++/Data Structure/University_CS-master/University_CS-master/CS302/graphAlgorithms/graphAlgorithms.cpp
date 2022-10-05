#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits.h>
#include <cstdlib>
#include <cstdio>
#include "graphAlgorithms.h"


graphAlgorithms::graphAlgorithms(int vertCount):
title(""),
topoCount(0),
vertexCount(0)
{
	dist = NULL;
	topoNodes = NULL;
	graphMatrix = NULL;
	if(vertCount != 0)
		newGraph(vertCount);
}

graphAlgorithms::~graphAlgorithms()
{
	destroyGraph();
}

void graphAlgorithms::newGraph(int vertCount)
{
	if(vertCount < 5) {
	  std::cout << "newGraph: Error, invalid graph size.\n";
  }else{
		//free any existing memory
		destroyGraph();
		//allocate new adjacency matrix
    graphMatrix = new int*[vertCount];
    for(int i = 0; i < vertCount; i++)
      graphMatrix[i] = new int[vertCount];
    //set all elements in matrix to zero
    for(int r = 0; r < vertCount; r++)
      for(int c = 0; c < vertCount; c++)
        graphMatrix[r][c] = 0;

    dist = new int[vertCount];
    topoNodes = new int[vertCount];	


    vertexCount = vertCount;
	}
}

void graphAlgorithms::addEdge(int from, int to, int weight)
{
	if((from <= vertexCount && to <= vertexCount) &&
     (from > 0 && to > 0)) {
    if(from == to)
      std::cout << "addEdge: Error, from and to cannot be the same.\n";
    else
		  graphMatrix[from-1][to-1] = weight;
	}else
		std::cout << "addEdge: Error, invalid vertex\n";
}

bool graphAlgorithms::readGraph(const std::string fileName)
{
	std::ifstream inFile(fileName.c_str());
	if(!inFile.is_open()){
		std::cout << "readGraph: Error, " << fileName << " cannot be opened...\n";
		return false;
	}
	int from,to,weight, vc;
	//get title and vertex count, ensure vertex count is above 5
	std::getline(inFile, title);
	inFile >> vc;
	if(vc < 5){
		std::cout << "readGraph: Error, invalid vertex";
		return false;
	}
	newGraph(vc);
	//loop and get all edges
	inFile >> from >> to >> weight;
	while(inFile){
			addEdge(from, to, weight);
			inFile >> from >> to >> weight;
	}
}

int graphAlgorithms::getvertexCount() const
{
	return vertexCount;
}
void graphAlgorithms::printMatrix() const
{
  if(graphMatrix == NULL) {
    std::cout << "printMatrix: Error, no graph data.\n"; 
  }else{
    //print first labeling row of adjacency matrix
		std::cout << std::right << "      ";
		for(int j = 0; j < 2; j++) {
      for(int i = 0; i < vertexCount; i++) {
        if(j == 0)
          std::cout << i+1 << "   ";
        else
          std::cout << "----";   
      }
      std::cout << std::endl;
      if(j == 0)
        std::cout << "    ";
    }
    
    //being printing out the guts of the adjacency matrix
		for(int r = 0; r < vertexCount; r++) {
      std::cout << r+1 << "|   ";
      for(int c = 0; c < vertexCount; c++) {
        if(graphMatrix[r][c] == 0)
          if(r == c)
            std::cout << std::setw(2) << graphMatrix[r][c] << "  ";
          else
            std::cout << std::setw(2) << "--" << "  ";
        else
          std::cout << std::setw(2) << graphMatrix[r][c] << "  ";
      }
      std::cout << std::endl;
    }

  }
}

void graphAlgorithms::topoSort()
{
	if(graphMatrix == NULL)
	  std::cout << "topoSort: Error, no graph data.\n";
  else{
    //create boolean array for topo sort
		bool visited[vertexCount];
		for(int i = 0; i < vertexCount; i++)
			visited[i] = false;

    //call dfs on each node if still false
		for(int i = 0; i < vertexCount; i++)
			if(visited[i] == false)
				dfs(i, visited);

    //print out result of topological sort in reverse
    std::cout << "Topological Sort:\n";
	  for(int i = vertexCount-1; i >= 0; i--)
      std::cout << topoNodes[i] << " ";
    std::cout << std::endl << std::endl;
  }
}

void graphAlgorithms::dijkstra(int src)
{
  if(graphMatrix == NULL)
    std::cout << "dijkstra: Error, no graph data.\n";
  else if(src < 0 || src > vertexCount)
    std::cout << "dijkstra: Error, invalid source.\n";
  else{
    bool set[vertexCount];
    //initialize arrays
    for(int i = 0; i < vertexCount; i++){
      dist[i] = INT_MAX;
      set[i] = false;
    }

    //distance from source vertex to itself is zero
    dist[src] = 0;

    for(int cnt = 0; cnt < vertexCount-1; cnt++) {

      int min = INT_MAX;
      int min_index;

      for(int v = 0; v < vertexCount; v++)
        if(set[v] == false && dist[v] <= min) {
          min = dist[v];
          min_index = v;
        }

      int u = min_index;

      set[u] = true;

      for(int v = 0; v < vertexCount; v++) {
        if(!set[v] && graphMatrix[u][v] && dist[u] != INT_MAX
                   && dist[u]+graphMatrix[u][v] < dist[v])
          dist[v] = dist[u] + graphMatrix[u][v];
      }
    }
    
    std::cout << "Shortest Paths:\n";
    std::cout << "From Node: 1 to:\n";
    std::cout << std::right << std::setw(10) << "Vertex" << std::setw(10) << "Distance" << std::endl;
    for(int i = 0; i < vertexCount; i++) { 
      if(dist[i] < INT_MAX)
        std::cout << std::setw(10) << i+1 << std::setw(10) << dist[i] << std::endl;
      else
        std::cout << std::setw(10) << i+1 << std::left << std::setw(7) << "" <<  "not reachable\n" << std::right;
    }
  }

}

std::string graphAlgorithms::getTitle() const
{
	return title;
}

void graphAlgorithms::setTitle(const std::string d_title)
{
	title = d_title;
}

void graphAlgorithms::printDistances() const
{
	for(int i = 0; i < vertexCount; i++) {
		std::cout << dist[i] << " ";
	}
	std::cout << std::endl;
}

void graphAlgorithms::destroyGraph()
{
	//free any existing dynamic memory
	if(dist != NULL)
		delete [] dist;
	if(topoNodes != NULL)
		delete [] topoNodes;

	if(graphMatrix != NULL) {
		for(int i = 0; i < vertexCount; i++)
			delete [] graphMatrix[i];
		delete [] graphMatrix;
	}
}

void graphAlgorithms::dfs(int v, bool visited[])
{
	visited[v] = true;

	for(int i = 0; i < vertexCount; i++) {
		if(graphMatrix[v][i] != 0 || i == v) {
			if(visited[i] == false)
				dfs(i, visited);
		}
	}

	topoNodes[topoCount] = v+1;
	topoCount++;
}
