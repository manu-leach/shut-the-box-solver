#ifndef NODE_H
#define NODE_H

/// @brief Base class for nodes of the game tree.
class Node
{
public:
    /// @brief Default constructor. Initialises a node with weight 1, not fully explored.
    Node() : weight(1), fullyExplored(false) {}

    /// @brief Creates a node with a given weight and fully explored status.
    /// @param weight Weight assigned to the node in a weighted graph.
    /// @param fullyExplored Flags whether all paths emanating from this node have been fully traversed.
    Node(const int& weight, const bool& fullyExplored) : weight(weight), fullyExplored(fullyExplored) {}

    inline int getWeight() {return weight;}

    inline bool isFullyExplored() {return fullyExplored;}

protected:
    int weight;
    bool fullyExplored;
};

#endif