#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <set>
#include <vector>

#include "Edge.h"

class GameState
{
public:
    GameState() : numbersUp({1, 2, 3, 4, 5, 6, 7, 8, 9}), fullyExplored(false) {}
    GameState(const std::set<int>& numbersUp) : numbersUp(numbersUp), edges({}), fullyExplored(numbersUp.empty()) {}

    inline std::set<int> getNumbersUp() const {return numbersUp;}

    void addEdge(GameState* successor, const double& probability);

    int countEdges() const {return edges.size();}

private:
    const std::set<int> numbersUp;
    std::vector<Edge> edges;
    bool fullyExplored;
};

#endif