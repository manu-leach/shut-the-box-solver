#include "Vertex.h"

void Vertex::addEdge(Vertex* successor, const double& probability)
{
    edges.push_back(Edge(successor, probability));
}

void Vertex::calcWinChance()
{
    for (Edge edge : edges)
    {
        Vertex* successor = edge.getSuccessor();
        double probability = edge.getProbability();

        if (successor->isFullyExplored())
        {
            winChance += probability * successor->getWinChance();
        }
        else
        {
            successor->calcWinChance();
        }
    }

    fullyExplored = true;
}