#include "Vertex.h"

void Vertex::addEdge(Vertex* successor, const int& roll)
{
    edges.push_back(Edge(successor, roll));
}

void Vertex::calcWinChance()
{
    for (Edge edge : edges)
    {
        Vertex* successor = edge.getSuccessor();
        
        int roll = edge.getRoll();
        double probability = Utilities::twoDiceProbabilities.at(roll);

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
