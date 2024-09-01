#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <map>
#include <set>

namespace Utilities
{
    template <typename T>
    void printSet(const std::set<T>& set)
    {
        for (const T& element : set)
        {
            std::cout << element << ", ";
        }

        std::cout << std::endl;
    }

    extern const std::map<int, double> twoDiceProbabilities;
}

#endif