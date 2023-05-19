#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <game.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow* w = new QMainWindow;
    QWidget* centralWidget = new QWidget;
    QVBoxLayout* vb = new QVBoxLayout(centralWidget);

    w->setWindowTitle("YARAX");
    Game* game = new Game;
    game->initialize();
    vb->addLayout(game->grid);

    w->setCentralWidget(centralWidget);
    w->show();
    return a.exec();
}
