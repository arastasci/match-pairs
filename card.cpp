#include "card.h"

#include "game.h"

Game* Game::singleton;

const QString unknown_string = "?";

Card::Card(){
    setText(unknown_string);
    setColor(Qt::white);
}

Card::Card(const QString& text,
           QWidget* parent) : QPushButton(unknown_string, parent){
    setColor(Qt::white);
    name = text;
}

void Card::setName(QString& name){
    this->name = name;
}

// boilerplate code for setting the color.
void Card::setColor(QColor color){
    QPalette pal = palette(); 
    pal.setColor(QPalette::Button, QColor(color));
    setPalette(pal);
}


void Card::enable(){
    setColor(Qt::white);
    hide();
}

void Card::disable(){ // succeeds, disable the card.
    setText("");
}
void Card::justRevealName(){
    setText(name);
}

void Card::reveal(){
    setText(name);
    setColor(Qt::blue);
    blockSignals(true);
    Game::singleton->placeCard(this);
    if(Game::singleton->isPaired()){ // if isPaired
        if(QString::compare(Game::singleton->currentPair[0]->name, Game::singleton->currentPair[1]->name) == 0){ // if there is a match, then disable the cards
            Game::singleton->disablePair();
        }
        else{
            Game::singleton->reenablePair(); // else reenable them for further play
        }
    }
}

void Card::hide(){
    setText(unknown_string);
}


