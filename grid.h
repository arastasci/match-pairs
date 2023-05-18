#ifndef GRID_H
#define GRID_H

#include <QWidget>
#include <QGridLayout>

class Grid : public QGridLayout
{
    Q_OBJECT
public:
    Grid();
    ~Grid();
public slots:
    void checkCompleteness();
};

#endif // GRID_H
