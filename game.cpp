#include "game.h"

Game::Game(){
    grid = new Grid;
}

void Game::initialize(){
    // fill the grid with cards and connect slots

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            Card* curCard = new Card;

        }
    }
}
void Game::disablePair(){
    currentPair.first->disable();
    currentPair.second->disable();

    currentPair.first = nullptr;
    currentPair.second = nullptr;

}
void Game::win(){

}
void Game::lose(){

}



