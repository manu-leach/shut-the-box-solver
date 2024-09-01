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
    Vertex() : numbersUp({1, 2, 3, 4, 5, 6, 7, 8, 9}), edges({}), fullyExplored(false), winChance(0), rollOneDie(false) {}
    Vertex(const std::set<int>& numbersUp) : numbersUp(numbersUp), edges({}), fullyExplored(numbersUp.empty()), winChance(0), rollOneDie(false) {}

    std::set<int> getNumbersUp() const {return numbersUp;}

    int countEdges() const {return edges.size();}

    bool isFullyExplored() const {return fullyExplored;}

    double getWinChance() const {return winChance;}

    void setWinChance(const double& newWinChance) {winChance = newWinChance;}

    Vertex* getSuccessor(const int& index) {return edges[index].getSuccessor();}

    /// @brief Checks if we have the choice of rolling just one die, that is if the 7, 8 and 9 are not up.
    /// @return True iff we can roll just one die.
    bool canRollOneDie() const {return !(numbersUp.count(7) + numbersUp.count(8) + numbersUp.count(9));}

    void addEdge(Vertex* successor, const int& roll);

    void calcWinChance();

    void printSuccessors() const;

private:
    const std::set<int> numbersUp;
    std::vector<Edge> edges;
    bool fullyExplored;
    double winChance;
    bool rollOneDie;
};

#endif