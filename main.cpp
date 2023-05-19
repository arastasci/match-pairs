#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <game.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow* w = new QMainWindow;
    QWidget* centralWidget = new QWidget;
    QVBoxLayout* vb = new QVBoxLayout(centralWidget);
    QHBoxLayout* hb = new QHBoxLayout;
    w->setWindowTitle("Match Pairs");
    Game* game = new Game;
    game->initialize();
    hb->addWidget(game->try_label);
    hb->addWidget(game->new_game_button);
    vb->addLayout(hb);
    vb->addLayout(game->grid);

    w->setCentralWidget(centralWidget);
    w->show();
    return a.exec();
}
