#ifndef VERTEX_H
#define VERTEX_H

#include <set>
#include <vector>

#include "Edge.h"

class Vertex
{
public:
    Vertex() : numbersUp({1, 2, 3, 4, 5, 6, 7, 8, 9}), edges({}), fullyExplored(false), winChance(0) {}
    Vertex(const std::set<int>& numbersUp) : numbersUp(numbersUp), edges({}), fullyExplored(numbersUp.empty()), winChance(0) {}

    inline std::set<int> getNumbersUp() const {return numbersUp;}

    void addEdge(Vertex* successor, const double& probability);

    int countEdges() const {return edges.size();}

    bool isFullyExplored() const {return fullyExplored;}

private:
    const std::set<int> numbersUp;
    std::vector<Edge> edges;
    bool fullyExplored;
    double winChance;
};

#endif