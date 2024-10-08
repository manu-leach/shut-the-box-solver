#ifndef EDGE_H
#define EDGE_H

#include "Vertex.h"

class Vertex;

/// @brief Directed edge of the game graph. Stores the successor vertex and the probability of rolling the corresponding roll. To be stored by the predecessor vertex.
class Edge
{
public:
    Edge(Vertex* successor, const int& roll) : successor(successor), roll(roll) {}

    Vertex* getSuccessor() const {return successor;}

    int getRoll() const {return roll;}

private:
    Vertex* successor;
    const int roll;
};

#endif