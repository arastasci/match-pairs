#ifndef GAME_H
#define GAME_H
#include <utility>
#include <card.h>
#include <grid.h>

const int INITIAL_TRY_COUNT = 50;

class Game
{
    int try_count = INITIAL_TRY_COUNT;
    std::pair<Card*, Card*> currentPair;
    Grid* grid;
public:
    Game();
    void initialize();
    void disablePair();
    void win();
    void lose();
};

#endif // GAME_H
