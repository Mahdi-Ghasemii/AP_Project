#ifndef STORE_H
#define STORE_H

#include <QWidget>
#include "Product.h"

namespace Ui {
class Store;
}

class Store : public QWidget
{
    Q_OBJECT

public:


       void Check_All_Products (int num_gandom,int num_yonjeh,int num_bill,int num_mikh,int num_egg,int num_milk,int num_pashm);
       void Sell_Product (int num_gandom,int num_yonjeh,int num_bill,int num_mikh,int num_egg,int num_milk,int num_pashm);
       void Buy_Product (int num_gandom,int num_yonjeh,int num_bill,int num_mikh,int num_egg,int num_milk,int num_pashm);

private:
    Ui::Store *ui;
};

#endif // STORE_H
