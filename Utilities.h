#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <set>

namespace Utilities
{
    template <typename T>
    void printSet(const std::set<T> set)
    {
        for (const T& element)
        {
            std::cout << element << ", ";
        }

        std::cout << std::endl;
    }

}

#endif