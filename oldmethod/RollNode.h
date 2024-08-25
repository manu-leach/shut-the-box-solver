#ifndef ROLLNODE_H
#define ROLLNODE_H

#include <map>

#include "Node.h"

/// @brief Node of the game tree representing a roll of the dice.
class RollNode : public Node
{
public:
    RollNode(const int& total, const int& numberOfDice);

private:
    const int total;
    const int numberOfDice;

    const std::map<int, int> twoDiceWeightMap{{2, 1}, {3, 2}, {4, 3}, {5, 4}, {6, 5}, {7, 6}, {8, 5}, {9, 4}, {10, 3}, {11, 2}, {12, 1}};

};

#endif