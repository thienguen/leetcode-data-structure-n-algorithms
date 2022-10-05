#ifndef GRAPHALGORITHMS_H_
#define GRAPHALGORITHMS_H_

	#include <string>

	class graphAlgorithms {
		public:
			graphAlgorithms(int=0);
			~graphAlgorithms();

			void newGraph(int);
			void addEdge(int, int, int);
			bool readGraph(const std::string);
			int getvertexCount() const;
			void printMatrix() const;
			void topoSort();
			void dijkstra(int);
			std::string getTitle() const;
			void setTitle(const std::string);
			void printDistances() const;
			void destroyGraph();
			void dfs(int, bool[]);
		private:
			int vertexCount;
			std::string title;
			int **graphMatrix;
			int *dist;
			int *topoNodes;
			int topoCount;
	};

#endif
