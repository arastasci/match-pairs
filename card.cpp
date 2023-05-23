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
    setColor(Qt::green);
    remove();
}
void Card::justRevealName(){
    setText(name);
}
void Card::reveal(){
    setText(name);
    setColor(Qt::blue);
    blockSignals(true);
    Game::singleton->placeCard(this);
    if(Game::singleton->isPaired()){
        if(QString::compare(Game::singleton->currentPair[0]->name, Game::singleton->currentPair[1]->name) == 0){
            Game::singleton->disablePair();
        }
        else{
            Game::singleton->reenablePair();
        }
    }
}

void Card::hide(){
    setText(unknown_string);
}

void Card::remove(){
    setText("");
}
