#include "Vertex.h"

void Vertex::addEdge(Vertex* successor, const int& roll)
{
    edges.push_back(Edge(successor, roll));
}

void Vertex::calcWinChance()
{
    double winChanceTwoDice = calcWinChance(2, 12, Utilities::twoDiceProbabilities);
    double winChanceOneDie;
    if (canRollOneDie())
    {
        winChanceOneDie = calcWinChance(1, 6, Utilities::oneDieProbabilities);
    }
    else
    {
        winChanceOneDie = 0;
    }

    if (winChanceOneDie > winChanceTwoDice)
    {
        winChance = winChanceOneDie;
        rollOneDie = true;
    }
    else
    {
        winChance = winChanceTwoDice;
        rollOneDie = false;
    }

    std::cout << "- - - - - NUMBERS UP: ";
    Utilities::printSet(numbersUp);
    std::cout << "1dChance = " << winChanceOneDie << "\n";
    std::cout << "2dChance = " << winChanceTwoDice << "\n";
    std::cout << "oneDie: " << rollOneDie << "\n";

    fullyExplored = true;
}

void Vertex::printSuccessors() const
{
    int length = edges.size();

    for (int i = 0; i < length; i ++)
    {
        Vertex* successor = edges[i].getSuccessor();
        int roll = edges[i].getRoll();

        std::cout << i << ": ";
        std::cout << "r = " << roll << ", ";
        std::cout << "wc = " << successor->winChance << ". ";
        std::cout << "Up: ";
        Utilities::printSet(successor->getNumbersUp());
    }
}

double Vertex::calcWinChance(const int& minRoll, const int& maxRoll, const std::map<int, double>& probabilityMap)
{
    double chance = 0;

    for (Edge edge : edges)
    {
        int roll = edge.getRoll();
        if (roll > maxRoll || roll < minRoll)
        {
            continue;
        }

        Vertex* successor = edge.getSuccessor();
        double probability = probabilityMap.at(roll);

        if (!successor->isFullyExplored())
        {
            successor->calcWinChance();
        }
        chance += probability * successor->getWinChance();
    }

    return chance;
}

double Vertex::sumTwoDiceProbabilities() const
{
    double sum = 0;

    for (Edge edge : edges)
    {
        int roll = edge.getRoll();
        if (roll == 1)
        {
            continue;
        }
        double probability = Utilities::twoDiceProbabilities.at(roll);
        sum += probability;
    }

    return sum;
}
