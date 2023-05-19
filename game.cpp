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
    singleton = this;
    selectedCardCount = 0;
    timeCount = 0;
    timer = new QTimer(this);

}

void Game::initialize(){
    // fill the grid with cards and connect slots
    grid = new Grid;

    for(int i = 0; i < WIDTH; i++){
        for(int j = 0; j < HEIGHT; j++){
            if(grid->itemAtPosition(i, j) != nullptr)
                continue;
            Card* first_card = new Card;
            Card* second_card = new Card;

            int word_index = rand() % 50;
            first_card->setName(words[word_index]);
            second_card->setName(words[word_index]);

            int rand_row = rand() % WIDTH;
            int rand_col = rand() % HEIGHT;
            for(int m = 0; m < WIDTH; m++){
                bool flag = false;
                for(int k = 0; k < HEIGHT; k++){
                    if(grid->itemAtPosition((rand_row+m) % WIDTH, (rand_col + k) % HEIGHT) == nullptr)
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
            QObject::connect(first_card, SIGNAL(clicked()), first_card, SLOT(reveal()));
            QObject::connect(first_card, SIGNAL(clicked()), grid, SLOT(checkCompleteness()));

            QObject::connect(second_card, SIGNAL(clicked()), second_card, SLOT(reveal()));
            QObject::connect(second_card, SIGNAL(clicked()), grid, SLOT(checkCompleteness()));


            grid->addWidget(first_card, i, j);
            grid->addWidget(second_card, rand_row % WIDTH, rand_col % HEIGHT);

        }
    }
}
void Game::disablePair(){
    connect(timer, SIGNAL(timeout()), this, SLOT(timeToEnable()));
    timer->start(1000);
    blockAllSignals(true);
    success = true;

}
bool Game::isPaired(){
    return selectedCardCount == 2;
}
void Game::reenablePair(){
    connect(timer, SIGNAL(timeout()), this, SLOT(timeToEnable()));
    timer->start(1000);
    blockAllSignals(true);
    success = false;

}
void Game::placeCard(Card *c){
    currentPair[selectedCardCount++] = c;
}
void Game::restart(){
    delete grid;
    initialize();
}

void Game::timeToEnable(){
    timeCount++;
    if(timeCount >= 1){
        if(!success){
            currentPair[0]->enable();
            currentPair[1]->enable();
        }
        else{
            currentPair[0]->disable();
            currentPair[1]->disable();
        }

        currentPair[0] = nullptr;
        currentPair[1] = nullptr;

        disconnect(timer, SIGNAL(timeout()), this, SLOT(timeToEnable()));
        blockAllSignals(false);

        timeCount = 0;
        selectedCardCount = 0;
    }
}

void Game::win(){

}
void Game::lose(){

}

void Game::blockAllSignals(bool flag){
    for(int i = 0; i < grid->count(); i++){
        Card* c = qobject_cast<Card*>(grid->itemAt(i)->widget());
        c->blockSignals(flag);
    }
    grid->blockSignals(flag);
}



