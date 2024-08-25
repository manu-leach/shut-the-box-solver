#ifndef ENDNODE_H
#define ENDNODE_H

#include "Node.h"

class EndNode : public Node
{
public: 
    EndNode(const bool& win) : Node(1, true), win(win) {}

private:
    const bool win;
};

#endif