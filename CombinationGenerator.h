#ifndef COMBINATIONGENERATOR_H
#define COMBINATIONGENERATOR_H

#include <set>

/// @brief Provides static functions generating the combinations of tabs corresponding to totals.
class CombinationGenerator
{
public:
    CombinationGenerator() {}

    /// @brief Generates a set containing every combination of a subset of the numbers 1-9 that sum to a given total. 
    /// @param total The total to be summed to.
    /// @param numbersUp The subset of the numbers 1-9 from which the combinations are to be drawn.
    /// @return Exhaustive list of the combinations of the subset of the numbers 1-9 that sum to the total.
    static std::set<std::set<int>> genCombos(const int& total, std::set<int> numbersUp = {1, 2, 3, 4, 5, 6, 7, 8, 9});

private:
    /// @brief Recursive function for generating the combinations of numbers 1-9 summing to a given total.
    /// @param combos Valid combinations summing to the original total. Used as a return.
    /// @param currentCombo The candidate combination of number 1-9, summing to less than the total, being considered as to whether it can be expanded to a valid combination.
    /// @param numbersUp The numbers 
    /// @param total Current total to be summed to. The original total minus the sum of the current combination.
    static void genCombosRecursive(std::set<std::set<int>>& combos, std::set<int>& currentCombo, std::set<int>& numbersUp, const int& total);
};

#endif