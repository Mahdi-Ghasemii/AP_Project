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
    void upgrade();
    void feedeing();
    void collect();

private:
    Ui::ChickenHome *ui;
};

#endif // CHICKENHOME_H
