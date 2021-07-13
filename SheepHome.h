#ifndef SHEEPHOME_H
#define SHEEPHOME_H

#include <QMainWindow>
#include "Habitat.h"

namespace Ui {
class SheepHome;
}

class SheepHome : public QMainWindow, public Habitat
{
    Q_OBJECT

public:
    explicit SheepHome(QWidget *parent = nullptr);
    ~SheepHome();
    void upgrade();
    void feedeing();
    void collect();
    void operator=(const SheepHome&);
private:
    Ui::SheepHome *ui;
};

#endif // SHEEPHOME_H
