#ifndef STATEGENERATOR_H
#define STATEGENERATOR_H

#include <set>
#include <vector>

/// @brief Functions of generating game states.
struct StateGenerator
{
/// @brief Generates all possible sets of "up" numbers, each of which define a game state.
/// @param maxSize The size of set upw to which to generate. Default 9.
/// @return Set of sets of integers.
static std::set<std::set<int>> generateStateCombos(const int& maxSize = 9);
};

#endif