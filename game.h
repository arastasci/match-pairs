#ifndef GAME_H
#define GAME_H

#include <utility>
#include <card.h>
#include <QTimer>
#include <QMessageBox>
#include <QGridLayout>

const int INITIAL_TRY_COUNT = 50;

class Game : public QObject
{
    Q_OBJECT 
    int try_count;
    int timeCount;
    int score;
    int selectedCardCount;
    int remaining_cards;
    const int WIDTH = 5;
    const int HEIGHT = 6;
public:
    static Game* singleton;
    bool success;
    Card* currentPair[2];
    QGridLayout* grid;
    QTimer* timer;
    QLabel* try_label;
    QLabel* score_label;
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
    void disconnectAll();
    void revealAllCards(bool isAWin);
public slots:
    void timeToEnable();
    void restart();

};

#endif // GAME_H
