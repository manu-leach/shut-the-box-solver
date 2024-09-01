#include "GameGraph.h"
#include "Utilities.h"

#include <iostream>
#include <set>

int main() 
{
    
    GameGraph gameGraph;
    std::cout << "Created game graph with " << gameGraph.countEdges() << " edges." << std::endl;

    Vertex* currentVertex = gameGraph.getRoot();
    currentVertex->calcWinChance();
    std::cout << "Root grabbed: ";
    Utilities::printSet(currentVertex->getNumbersUp());

    while (currentVertex->countEdges() > 0)
    {
        currentVertex->printSuccessors();

        int choice;
        std::cout << "Which successor do you choose? ";
        std::cin >> choice;
        
        currentVertex = currentVertex->getSuccessor(choice);
    }

    std::set<int> emptySet = {};
    if (currentVertex->getNumbersUp() == emptySet)
    {
        std::cout << "By my reckoning, you have won!";
    }
    else
    {
        std::cout << "I think you have lost :(";
    }

    std::cout << std::endl;

    return 0;
}