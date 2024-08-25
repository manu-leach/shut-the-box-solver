#include "RollNode.h"

RollNode::RollNode(const int& total, const int& numberOfDice) : Node(1, false), total(total), numberOfDice(numberOfDice)
{
    if (numberOfDice == 2)
    {
        weight = twoDiceWeightMap.at(total);
    }
}