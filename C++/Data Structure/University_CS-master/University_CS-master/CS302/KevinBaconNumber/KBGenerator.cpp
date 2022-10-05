#include <iostream>
#include <fstream>
#include <string>
#include "KBGenerator.h"

KBGenerator::KBGenerator():
d_vertcount(0)
{
    d_actors = NULL;
    d_movies = NULL;
}

KBGenerator::~KBGenerator()
{

}

void KBGenerator::addEdge(std::string from, std::string to)
{
    if((from <= d_vertcount && to <= d_vertcount) && 
        (from > 0 && to > 0)) {
        if(from == to)
            std::cout << "Error, from and to cannot be the same\n"
        else {
            int f1 = d_actors.find(from);
            int f2 = d_movies.find(from);
            if(f1 == -1 && f2 == -1) {
                std::cout << "Error vertex not found...\n";
            }else if(f1 > -1) {
                
            } 
        }
    }    
}

void KBGenerator::addActorVertex(std::string key)
{
    d_actors.insert(key);
}

void KBGenerator::addMovieVertex(std::string key)
{
    d_movies.insert(key);
}

bool KBGenerator::readDataFile(const std::string fileName)
{
    std::ifstream inFile(fileName.c_str());
    if(!inFile.is_open())
        return false;
}

int KBGenerator::getVertexCount()
{
    return d_vertcount;
}
