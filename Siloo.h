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

        Product& Get_gandom ();
        void Set_Gandom (Product _gandom);



private slots:
        void on_Return_to_Farm_clicked();
        void on_Upgrade_Siloo_clicked();

        //  get signals from Farm class :

        void Get_Signal_From_Farm(int _Num_Gandom);

signals:
        void Send_Signal_to_Farm(int _Num_Coin , int _Level , int _Experience);
};

#endif // SILOO_H
