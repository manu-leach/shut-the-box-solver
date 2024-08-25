#include "GameGraph.h"

GameGraph::GameGraph()
{
    std::set<std::set<int>> states = StateGenerator::generateStateCombos(9);

    for (const std::set<int> state : states)
    {
        GameState newState(state);
        gameStates.push_back(newState);
    }

    for (GameState& gameState : gameStates)
    {
        createEdges(gameState);
    }
}

void GameGraph::createEdges(GameState& gameState)
{
    std::set<int> numbersUp = gameState.getNumbersUp();

    for (int total = 2; total <= 12; total ++)
    {
        double probability = twoDiceProbabilities.at(total);

        std::set<std::set<int>> possibleRolls = CombinationGenerator::genCombos(total, numbersUp);

        for (const std::set<int>& roll : possibleRolls)
        {
            std::set<int> newNumbersUp = numbersUp;
            for (const int& num : roll)
            {
                newNumbersUp.erase(num);
            }

            GameState* successor = findGameState(newNumbersUp);
            gameState.addEdge(successor, probability);
        }
    }

}

GameState* GameGraph::findGameState(const std::set<int>& numbersUp)
{
    for (GameState& gameState : gameStates)
    {
        if (gameState.getNumbersUp() == numbersUp) 
        {
            return &gameState;
        }
    }

    return nullptr;
}