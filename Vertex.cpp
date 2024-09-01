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

void Vertex::printSuccessors() const
{
    int length = edges.size();

    for (int i = 0; i < length; i ++)
    {
        Vertex* successor = edges[i].getSuccessor();

        std::cout << i << ": ";
        std::cout << "wc = " << successor->winChance << ".";
        std::cout << "Up: ";
        Utilities::printSet(successor->getNumbersUp());
    }
}
