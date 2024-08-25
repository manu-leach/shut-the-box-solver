#ifndef GAMEGRAPH_H
#define GAMEGRAPH_H

#include <map>
#include <vector>

#include "CombinationGenerator.h"
#include "GameState.h"
#include "StateGenerator.h"

/// @brief Graph of all possible game states and their connections.
class GameGraph
{
public:
    GameGraph();

private:
    std::vector<GameState> gameStates;
    std::map<int, double> twoDiceProbabilities = {{2, 1/36}, {3, 2/36}, {4, 3/36}, {5, 4/36}, {6, 5/36}, {7, 6/36}, {8, 5/36}, {9, 4/36}, {10, 3/36}, {11, 2/36}, {12, 1/36}};

    void createEdges(GameState& gameState);

    GameState* findGameState(const std::set<int>& numbersUp);

};

#endif