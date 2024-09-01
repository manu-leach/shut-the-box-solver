#ifndef GAMEGRAPH_H
#define GAMEGRAPH_H

#include <algorithm>
#include <map>
#include <vector>

#include "CombinationGenerator.h"
#include "StateGenerator.h"
#include "Vertex.h"

/// @brief Graph of all possible game states and their connections.
class GameGraph
{
public:
    GameGraph();

    /// @brief Checks if the graph has been fully explored and hence the win chance for each vertex calculated.
    /// @return True iff the graph has been fully explored.
    bool checkExplored() const;

    Vertex* getRoot() {return findVertex({1, 2, 3, 4, 5, 6, 7, 8, 9});}

    int countEdges() const;

private:
    std::vector<Vertex> vertices;

    /// @brief Populates a given vertex with all its edges to successor vertices, defined by gamestates reachable by one turn.
    /// @param vertex The vertex to be populated.
    void createEdges(Vertex& vertex);

    /// @brief Finds the vertex with the given subset of the numbers 1-9 raised.
    /// @param numbersUp Set of numbers.
    /// @return Pointer to the vertex.
    Vertex* findVertex(const std::set<int>& numbersUp);

};

#endif