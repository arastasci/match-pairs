#ifndef CARD_H
#define CARD_H

#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QPalette>
class Card : public QPushButton{
    Q_OBJECT
    QString name;
public:
    Card();
    Card(const QString& text,
         QWidget* parent);
   void disable();
   void setName(QString& name);
public slots:
    void reveal();
    void hide();

};


#endif // CARD_H
