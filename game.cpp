#include "game.h"

QString words[] = {
    "apple",
    "banana",
    "car",
    "dog",
    "eleven",
    "flower",
    "grape",
    "house",
    "ice",
    "juice",
    "kite",
    "lemon",
    "mouse",
    "nest",
    "orange",
    "pear",
    "queen",
    "rabbit",
    "sun",
    "tree",
    "umbra",
    "violet",
    "water",
    "xylo",
    "yellow",
    "zebra",
    "air",
    "ball",
    "cat",
    "door",
    "egg",
    "fire",
    "guitar",
    "hat",
    "ink",
    "jacket",
    "key",
    "lamp",
    "moon",
    "note",
    "ocean",
    "piano",
    "quilt",
    "rose",
    "snake",
    "table",
    "umbra",
    "violin",
    "window",
    "xylo",
    "yarn",
    "zebra"
};



Game::Game(){

}

void Game::initialize(){
    // fill the grid with cards and connect slots
    grid = new Grid;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 5; j++){
            if(grid->itemAtPosition(i, j) != nullptr)
                continue;
            Card* first_card = new Card;
            Card* second_card = new Card;

            int word_index = rand() % 50;
            first_card->setName(words[word_index]);
            second_card->setName(words[word_index]);

            int rand_row;
            int rand_col;
            do{
                rand_row = rand() % 10;
                rand_col = rand() % 10;
            }
            while( grid->itemAtPosition(rand_row, rand_col) != nullptr || rand_row == i || rand_col == j);

            grid->addWidget(first_card, i, j);
            grid->addWidget(second_card, rand_row, rand_col);

        }
    }
}
void Game::disablePair(){
    currentPair.first->disable();
    currentPair.second->disable();

    currentPair.first = nullptr;
    currentPair.second = nullptr;

}

void Game::restart(){
    delete grid;
    initialize();
}

void Game::win(){

}
void Game::lose(){

}



