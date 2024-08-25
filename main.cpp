#include "CombinationGenerator.h"

#include <iostream>

int main() 
{
    CombinationGenerator slay;
    
    for (int i = 1; i <= 12; i ++)
    {
        std::cout << " - - - - - TOTAL: " << i << " - - - - - " << std::endl;
        std::set<std::set<int>> combos = slay.genCombos(i);

        for (const std::set<int> combo : combos)
        {
            for (const int num : combo)
            {
                std::cout << num << ", ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}