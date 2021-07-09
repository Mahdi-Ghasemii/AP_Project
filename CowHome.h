#ifndef COWHOME_H
#define COWHOME_H

#include <QMainWindow>
#include "Habitat.h"
namespace Ui {
class CowHome;
}

class CowHome : public QMainWindow, public Habitat
{
    Q_OBJECT

public:
    explicit CowHome(QWidget *parent = nullptr);
    ~CowHome();
    void upgrade(list<Player>::iterator it);
    void feedeing(list<Player>::iterator it);
    void collect(list<Player>::iterator it);

private:
    Ui::CowHome *ui;
};

#endif // COWHOME_H
