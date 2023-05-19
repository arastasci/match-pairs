#ifndef CARD_H
#define CARD_H

#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QPalette>

class Game;
class Card : public QPushButton{
    Q_OBJECT
public:
    QString name;


    Card();
    Card(const QString& text,
         QWidget* parent);
   void disable();
   void enable();
   void setColor(QColor color);
   void setName(QString& name);
   void remove();
   void justRevealName();
   void hide();

public slots:
    void reveal();
};


#endif // CARD_H
