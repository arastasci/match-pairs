#ifndef GAME_H
#define GAME_H
#include <utility>
#include <card.h>
#include <grid.h>
#include <QTimer>

const int INITIAL_TRY_COUNT = 50;

class Game : public QObject
{
    Q_OBJECT 
    int try_count = INITIAL_TRY_COUNT;
    int timeCount;
    int selectedCardCount;
    const int WIDTH = 6;
    const int HEIGHT = 5;
public:
    static Game* singleton;
    bool success;
    Card* currentPair[2];
    Grid* grid;
    QTimer* timer;
    Game();
    void restart();
    void initialize();
    void reenablePair();
    void disablePair();
    void placeCard(Card* c);
    bool isPaired();
    void win();
    void lose();
    void blockAllSignals(bool flag);
public slots:
    void timeToEnable();
};

#endif // GAME_H
