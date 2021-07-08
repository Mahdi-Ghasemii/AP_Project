#ifndef SILOO_H
#define SILOO_H

#include <QWidget>
#include "Product.h"
#include <QMainWindow>
#include "Building.h"

namespace Ui {
class Siloo;
}

class Siloo : public QMainWindow ,public Building
{
    Q_OBJECT

private:
        Product gandom;
        Ui::Siloo *ui;

public:

        explicit Siloo(QWidget *parent = nullptr);
        ~Siloo();

        Product Get_gandom ();
        void Set_Gandom (Product _gandom);

        void Increase_Capacity (int Num_Mikh,int Num_Coin);
        void Check_Siloos_Product ();


};

#endif // SILOO_H
