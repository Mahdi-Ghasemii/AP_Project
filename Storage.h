#ifndef STORAGE_H
#define STORAGE_H

#include "Product.h"
#include <QWidget>
#include <QMainWindow>

namespace Ui {
class Storage;
}

class Storage : public QMainWindow
{
    Q_OBJECT

private:

       Product yonjeh;
       Product bill;
       Product mikh;
       Product egg;
       Product milk;
       Product pashm;
       time_t time_add_milk;

       Ui::Storage *ui;

   public:

       explicit Storage(QWidget *parent = nullptr);
       ~Storage();


       Product Get_bill ();
       void Set_bill (Product _bill);
       Product Get_mikh ();
       void Set_Mikh (Product _mikh);
       Product Get_yonjeh ();
       void Set_Yonjeh (Product _yonjeh);
       Product Get_egg ();
       void Set_Egg (Product _egg);
       Product Get_milk ();
       void Set_Milk (Product _milk);
       Product Get_pashm ();
       void Set_Pashm (Product _pashm);


       void Increase_Capasity ();
       void Check_Storages_Product ();
};

#endif // STORAGE_H
