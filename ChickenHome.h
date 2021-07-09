#ifndef CHICKENHOME_H
#define CHICKENHOME_H

#include <QMainWindow>
#include "Habitat.h"

namespace Ui {
class ChickenHome;
}

class ChickenHome : public QMainWindow, public Habitat
{
    Q_OBJECT

public:
    explicit ChickenHome(QWidget *parent = nullptr);
    ~ChickenHome();
    void upgrade(list<Player>::iterator it);
    void feedeing(list<Player>::iterator it);
    void collect(list<Player>::iterator it);

private:
    Ui::ChickenHome *ui;
};

#endif // CHICKENHOME_H
