#include <QApplication>
#include <QMainWindow>
#include <game.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow* w = new QMainWindow;
    w->setWindowTitle("YARAX");\
    Game* game = new Game;
    game->initialize();
    w->setCentralWidget(game->grid->widget());

    w->show();
    return a.exec();
}
