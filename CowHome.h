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
    void upgrade();
    void feedeing();
    void collect();
    void operator=(const CowHome&);
private:
    Ui::CowHome *ui;
};

#endif // COWHOME_H
