#ifndef CARD_H
#define CARD_H

#include <QLabel>
#include <QPushButton>

class Card : public QPushButton{
    Q_OBJECT
public:
    Card();
public slots:
    void reveal();
    void hide();
    void remove();
};


#endif // CARD_H
