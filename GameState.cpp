#include "GameState.h"

void GameState::addEdge(GameState* successor, const double& probability)
{
    edges.push_back(Edge(successor, probability));
}