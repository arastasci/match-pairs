#include "card.h"

#include "game.h"

Game* Game::singleton;

const QString unknown_string = "?";
const QString matched_string = "-";

Card::Card(){
    setText(unknown_string);
}

Card::Card(const QString& text,
           QWidget* parent) : QPushButton(unknown_string, parent){
    QPalette pal = palette();
    pal.setColor(QPalette::Button, QColor(Qt::gray));
    setPalette(pal);
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
    blockSignals(false);
    hide();
}

void Card::disable(){ // succeeds, disable the card.
    setColor(Qt::green);
    blockSignals(true);
    remove();
}

void Card::reveal(){
    setText(name);
    QPalette pal = palette();
    pal.setColor(QPalette::Button, QColor(Qt::blue));
    setPalette(pal);
    blockSignals(true);
    Game::singleton->placeCard(this);
    if(Game::singleton->isPaired()){
        if(Game::singleton->currentPair[0]->name == Game::singleton->currentPair[1]->name){
            Game::singleton->disablePair();
        }
        else{
            Game::singleton->reenablePair();
        }
    }
}

void Card::hide(){
    setText(unknown_string);
    blockSignals(false);
}

void Card::remove(){
    setText("");
}
