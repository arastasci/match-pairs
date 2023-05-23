#include "game.h"

#include <iostream>

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
    timer = new QTimer(this);
    try_label = new QLabel();
    score_label = new QLabel();
    new_game_button = new QPushButton("New Game");
    connect(new_game_button, SIGNAL(clicked()), this, SLOT(restart()));
    grid = new QGridLayout;
}

void Game::initialize(){
    // fill the grid with cards and connect slots
    selectedCardCount = 0;
    timeCount = 0;
    score = 0;
    try_count = INITIAL_TRY_COUNT;
    score_label->setText("Score: " + QString::number(score));
    try_label->setText("Tries Remaining: " + QString::number(try_count));

    remaining_cards = WIDTH * HEIGHT;


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
                    if(grid->itemAtPosition((rand_row+m) % WIDTH, (rand_col + k) % HEIGHT) == nullptr
                            && !(i == (rand_row + m) % WIDTH && j == (rand_col + k) % HEIGHT))
                    {
                        rand_row += m;
                        rand_col += k;
                        flag = true;
                        break;
                    }
                }
                if(flag)
                   break;
            }

            QObject::connect(first_card, SIGNAL(clicked()), first_card, SLOT(reveal()));
            QObject::connect(second_card, SIGNAL(clicked()), second_card, SLOT(reveal()));
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
    currentPair[0]->setColor(Qt::green);
    currentPair[1]->setColor(Qt::green);
    disconnect(currentPair[0], SIGNAL(clicked()), currentPair[0], SLOT(reveal()));
    disconnect(currentPair[1], SIGNAL(clicked()), currentPair[1], SLOT(reveal()));
}

bool Game::isPaired(){
    return selectedCardCount == 2;
}

void Game::reenablePair(){
    connect(timer, SIGNAL(timeout()), this, SLOT(timeToEnable()));
    timer->start(1000);
    blockAllSignals(true);
    success = false;
    currentPair[0]->setColor(Qt::red);
    currentPair[1]->setColor(Qt::red);


}

void Game::placeCard(Card *c){
    currentPair[selectedCardCount++] = c;
}

void Game::restart(){
    timer->stop();
    disconnect(timer, SIGNAL(timeout()), this, SLOT(timeToEnable()));
    blockAllSignals(true);

    for(int i = 0 ; i < WIDTH * HEIGHT; i++){
        QLayoutItem* item = grid->itemAt(0);
        QWidget* widget = item->widget();
        grid->removeWidget(widget);
        delete widget;
    }
    initialize();

    blockAllSignals(false);
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
            remaining_cards -=2;
            score++;
            score_label->setText("Score: " + QString::number(score));
            
        }

        try_count--;
        try_label->setText("Tries Remaining: " + QString::number(try_count));

        if(remaining_cards == 0)
               win();
        else if(try_count == 0)
                lose();
        currentPair[0] = nullptr;
        currentPair[1] = nullptr;

        disconnect(timer, SIGNAL(timeout()), this, SLOT(timeToEnable()));
        blockAllSignals(false);

        timeCount = 0;
        selectedCardCount = 0;
        timer->stop();
    }
}
void Game::revealAllCards(bool isAWin){

    for(int i = 0; i < grid->count(); i++){

        Card* c = dynamic_cast<Card*>(grid->itemAt(i)->widget());
        if(!isAWin){
            c->setColor(Qt::red);
        }
        c->justRevealName();
    }
}


void Game::win(){
    disconnectAll();
    QMessageBox winBox;
    revealAllCards(true);
    winBox.setText("You won!\nScore: " + QString::number(score));
    winBox.setStandardButtons(QMessageBox::Ok);
    winBox.exec();
}
void Game::lose(){
    disconnectAll();
    revealAllCards(false);
    QMessageBox loseBox;
    loseBox.setText("You lost...\nScore: " + QString::number(score));
    loseBox.setStandardButtons(QMessageBox::Ok);
    loseBox.exec();
}

void Game::blockAllSignals(bool flag){
    for(int i = 0; i < WIDTH * HEIGHT; i++){
        Card* c = dynamic_cast<Card*>(grid->itemAt(i)->widget());
        c->blockSignals(flag);
    }
}

void Game::disconnectAll(){
    for(int i = 0; i < WIDTH * HEIGHT; i++){
        Card* c = dynamic_cast<Card*>(grid->itemAt(i)->widget());
        disconnect(c, SIGNAL(clicked()), c, SLOT(reveal()));
    }
}




