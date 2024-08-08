#ifndef COMBINATIONGENERATOR_H
#define COMBINATIONGENERATOR_H

#include <set>

class CombinationGenerator
{
public:
    CombinationGenerator() {}

    static std::set<std::set<int>> genCombos(const int& total);

private:
    static void genCombosRecursive(std::set<std::set<int>>& combos, std::set<int>& currentCombo, std::set<int>& numbersUp, const int& total);
};

#endif