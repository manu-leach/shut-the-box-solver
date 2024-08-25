#ifndef EDGE_H
#define EDGE_H

#include "GameState.h"

class GameState;

class Edge
{
public:
    Edge(GameState* successor, const double& probability) : successor(successor), probability(probability) {}

private:
    const GameState* successor;
    const double probability;
};

#endif