#include "GameGraph.h"
#include "Utilities.h"

#include <iostream>

int main() 
{
    
    GameGraph gameGraph;
    std::cout << "Created game graph with " << gameGraph.countEdges() << " edges." << std::endl;

    Vertex* start = gameGraph.getRoot();
    std::cout << "Root grabbed: ";
    Utilities::printSet(start->getNumbersUp());

    start->calcWinChance();

    std::cout << gameGraph.checkExplored() << std::endl;

    return 0;
}