#include "StateGenerator.h"

std::set<std::set<int>> StateGenerator::generateStateCombos(const int& maxSize)
{
    std::vector<std::set<std::set<int>>> statesOfLength(maxSize + 1);

    statesOfLength[0] = {{}};

    for (int length = 1; length <= maxSize; length ++)
    {
        for (const std::set<int>& state : statesOfLength[length - 1])
        {
            for (int i = 1; i <= 9; i ++)
            {
                std::set<int> newState = state;
                newState.insert(i);
                statesOfLength[length].insert(newState);
            }
        }
    }

    std::set<std::set<int>> fullSetOfStates {};
    for (const std::set<std::set<int>>& stateSet : statesOfLength)
    {
        fullSetOfStates.insert(stateSet.begin(), stateSet.end());
    }

    return fullSetOfStates;
}