#ifndef SHEEPHOME_H
#define SHEEPHOME_H

#include <QMainWindow>
#include "Habitat.h"
<<<<<<< HEAD
#include "Data.h"
=======
>>>>>>> c3276557bcbf5916ef883f6b08881e841175b3fe

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

private:
    Ui::SheepHome *ui;
};

#endif // SHEEPHOME_H
