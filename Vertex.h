#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <set>
#include <vector>

#include "Edge.h"
#include "Utilities.h"

class Vertex
{
public:
    Vertex() : numbersUp({1, 2, 3, 4, 5, 6, 7, 8, 9}), edges({}), fullyExplored(false), winChance(0) {}
    Vertex(const std::set<int>& numbersUp) : numbersUp(numbersUp), edges({}), fullyExplored(numbersUp.empty()), winChance(0) {}

    inline std::set<int> getNumbersUp() const {return numbersUp;}

    inline int countEdges() const {return edges.size();}

    inline bool isFullyExplored() const {return fullyExplored;}

    inline double getWinChance() const {return winChance;}

    inline void setWinChance(const double& newWinChance) {winChance = newWinChance;}

    inline Vertex* getSuccessor(const int& index) {return edges[index].getSuccessor();}

    void addEdge(Vertex* successor, const double& probability);

    void calcWinChance();

    void printSuccessors() const;


private:
    const std::set<int> numbersUp;
    std::vector<Edge> edges;
    bool fullyExplored;
    double winChance;
};

#endif