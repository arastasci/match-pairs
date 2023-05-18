#include "card.h"
const QString unknown_string = "?";


Card::Card(){

}

Card::Card(const QString& text,
           QWidget* parent) : QPushButton(unknown_string, parent){
    name = text;
}

void Card::setName(QString& name){
    this->name = name;
}

void Card::disable(){ // succeeds, disable the card.
    QPalette pal = palette();
    pal.setColor(QPalette::Button, QColor(Qt::green));
    setPalette(pal);
    blockSignals(true);
}

void Card::reveal(){
    setText(name);
    QPalette pal = palette();
    pal.setColor(QPalette::Button, QColor(Qt::blue));
    setPalette(pal);
    blockSignals(true);
}

void Card::hide(){
    setText(unknown_string);
    blockSignals(false);
}

