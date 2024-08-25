#ifndef CHOICENODE_H
#define CHOICENODE_H

#include <set>

#include "Node.h"

/// @brief Game tree node representing the choice of numbers the player has chosen to "shut".
class ChoiceNode : public Node
{
public:
    /// @brief Default constructor for a choice node. Initialises with a weight of 1, not fully explored.
    ChoiceNode(const std::set<int>& choiceOfCombo) : Node(1, false), choiceOfCombo(choiceOfCombo) {}

    inline std::set<int> getChoiceOfCombo() {return choiceOfCombo;}
    
private:
    const std::set<int> choiceOfCombo;
};

#endif