#include "GameGraph.h"

GameGraph::GameGraph()
{
    std::set<std::set<int>> states = StateGenerator::generateStateCombos(9);
    std::set<int> dudState = {2, 3, 4, 5, 6, 7, 8, 9};

    for (const std::set<int> state : states)
    {
        if (state == dudState) continue; // TODO: non-hacky fix for this
        Vertex newVertex(state);
        vertices.push_back(newVertex);
    }

    for (Vertex& vertex : vertices)
    {
        createEdges(vertex);
    }

    Vertex* win = findVertex({});
    win->setWinChance(1);
}

bool GameGraph::checkExplored() const 
{
    for (const Vertex& vertex : vertices)
    {
        if (!vertex.isFullyExplored())
        {
            // Utilities::printSet(vertex.getNumbersUp());
            return false;
        }
    }

    return true;
}

int GameGraph::countEdges() const
{
    int edgeCount = 0;

    for (const Vertex& vertex : vertices)
    {
        edgeCount += vertex.countEdges();
    }

    return edgeCount;
}

void GameGraph::createEdges(Vertex& vertex)
{
    std::set<int> numbersUp = vertex.getNumbersUp();

    for (int total = 2; total <= 12; total ++)
    {
        double probability = twoDiceProbabilities.at(total);

        std::set<std::set<int>> possibleRolls = CombinationGenerator::genCombos(total, numbersUp);

        for (const std::set<int>& roll : possibleRolls)
        {
            std::set<int> newNumbersUp = numbersUp;
            for (const int& num : roll)
            {
                newNumbersUp.erase(num);
            }

            Vertex* successor = findVertex(newNumbersUp);
            vertex.addEdge(successor, probability);
        }
    }

}

Vertex* GameGraph::findVertex(const std::set<int>& numbersUp) 
{
    for (Vertex& vertex : vertices)
    {
        if (vertex.getNumbersUp() == numbersUp) 
        {
            return &vertex;
        }
    }

    return nullptr;
}