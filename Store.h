#ifndef STORE_H
#define STORE_H

#include <QWidget>
#include "Product.h"
#include <QMainWindow>

namespace Ui {
class Store;
}

class Store : public QMainWindow
{
    Q_OBJECT

private:
    Ui::Store *ui;

public:


        explicit Store(QWidget *parent = nullptr);
        ~Store();

       void Check_All_Products (int num_gandom,int num_yonjeh,int num_bill,int num_mikh,int num_egg,int num_milk,int num_pashm);
       void Sell_Product (int num_gandom,int num_yonjeh,int num_bill,int num_mikh,int num_egg,int num_milk,int num_pashm);
       void Buy_Product (int num_gandom,int num_yonjeh,int num_bill,int num_mikh,int num_egg,int num_milk,int num_pashm);


};

#endif // STORE_H
