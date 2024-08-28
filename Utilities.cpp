#include "Utilities.h"

void Utilities::printSet(std::set<int> set)
{
    for (const int& item : set)
    {
        std::cout << item << ", ";
    }

    std::cout << std::endl;
}