#ifndef COWHOME_H
#define COWHOME_H

#include <QMainWindow>
#include "Habitat.h"
<<<<<<< HEAD
#include "Data.h"
=======
>>>>>>> c3276557bcbf5916ef883f6b08881e841175b3fe

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

private:
    Ui::CowHome *ui;
};

#endif // COWHOME_H
