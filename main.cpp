#include "CombinationGenerator.h"
#include "StateGenerator.h"

#include <iostream>

int main() 
{
    
    std::set<std::set<int>> states = StateGenerator::generateStateCombos(9);

    std::cout << states.size() << std::endl;

    return 0;
}