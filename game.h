#ifndef GAME_H
#define GAME_H
#include <utility>
#include <card.h>
#include <grid.h>
#include <QTimer>
#include <QMessageBox>
const int INITIAL_TRY_COUNT = 1;

class Game : public QObject
{
    Q_OBJECT 
    int try_count;
    int timeCount;
    int selectedCardCount;
    int remaining_cards;
    const int WIDTH = 2;
    const int HEIGHT = 3;
public:
    static Game* singleton;
    bool success;
    Card* currentPair[2];
    Grid* grid;
    QTimer* timer;
    QLabel* try_label;
    QPushButton* new_game_button;
    Game();
    void initialize();
    void reenablePair();
    void disablePair();
    void placeCard(Card* c);
    bool isPaired();
    void win();
    void lose();
    void blockAllSignals(bool flag);
    void revealAllCards(bool isAWin);
public slots:
    void timeToEnable();
    void restart();

};

#endif // GAME_H
