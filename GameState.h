#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <set>

class GameState
{
public:
    GameState() : numbersUp({1, 2, 3, 4, 5, 6, 7, 8, 9}) {}
    GameState(const std::set<int>& numbersUp) : numbersUp(numbersUp) {}


private:
    const std::set<int> numbersUp;

};

#endif