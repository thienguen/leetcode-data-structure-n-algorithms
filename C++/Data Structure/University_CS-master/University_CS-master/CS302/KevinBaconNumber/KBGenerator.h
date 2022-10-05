#ifndef HASHADJLIST_H_
#define HASHADJLIST_H_

#include "HashList.h"
#include <string>

class KBGenerator {
    public:
       KBGenerator();
        ~KBGenerator();
    
        void addEdge(std::string,std::string);
        void addActorVertex(std::string);
        void addMovieVertex(std::string);
    
        bool readDataFile(const std::string);
        bool initNewGraph();
        
        int getVertexCount();
    private:
        void addEdge(std::string, std::string);
        void addActorVertex(std::string);
        void addMovieVertex(std::string);
        //create two seperate adjacency lists, one for 
        //holding edges between actors and movies, and
        //one containing edges between movies and actors
        HashList d_actors;
        HashList d_movies;

        //amount of vertices
        int d_vertcount;
};

#endif
