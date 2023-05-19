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
        for(int j = 0; j < 10; j++){
            if(grid->itemAtPosition(i, j) != nullptr)
                continue;
            Card* first_card = new Card;
            Card* second_card = new Card;

            int word_index = rand() % 50;
            first_card->setName(words[word_index]);
            second_card->setName(words[word_index]);

            int rand_row = rand() % 10;
            int rand_col = rand() % 10;
            for(int m = 0; m < 10; m++){
                bool flag = false;
                for(int k = 0; k < 10; k++){
                    if(grid->itemAtPosition((rand_row+m) % 10, (rand_col + k) % 10) == nullptr)
                    {
                        rand_row += m;
                        rand_row += k;
                        flag = true;
                        break;
                    }
                }
                if(flag)
                   break;
            }

            grid->addWidget(first_card, i, j);
            grid->addWidget(second_card, rand_row % 10, rand_col % 10);

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



