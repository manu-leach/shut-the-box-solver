#include "CombinationGenerator.h"

std::set<std::set<int>> CombinationGenerator::genCombos(const int& total)
{
    std::set<std::set<int>> combos {};
    std::set<int> currentCombo {};
    std::set<int> numbersUp {1, 2, 3, 4, 5, 6, 7, 8, 9};

    genCombosRecursive(combos, currentCombo, numbersUp, total);

    return combos;
}

void CombinationGenerator::genCombosRecursive(std::set<std::set<int>>& combos, std::set<int>& currentCombo, std::set<int>& numbersUp, const int& total)
{
    for (int i = 1; i <= 9; i ++)
    {
        if (numbersUp.count(i)) 
        {
            numbersUp.erase(i);
            int newTotal = total - i;
            if (newTotal > 0)
            {
                currentCombo.insert(i);
                genCombosRecursive(combos, currentCombo, numbersUp, newTotal);
                currentCombo.erase(i);
            }
            else if (newTotal == 0)
            {
                currentCombo.insert(i);
                combos.insert(currentCombo);
                currentCombo.erase(i);
            }
            numbersUp.insert(i);
        }
    }
}