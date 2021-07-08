#ifndef STORAGE_H
#define STORAGE_H

#include "Product.h"
#include <QWidget>
#include <QMainWindow>
#include "Building.h"

namespace Ui {
class Storage;
}

class Storage : public QMainWindow , public Building
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


       void Increase_Capasity (int coin,int level);
       void Check_Storages_Product ();
private slots:
       void on_pushButton_clicked();
       void on_pushButton_2_clicked();
       void on_Return_to_Farm_clicked();
       void on_Increase_Capasity_clicked();
};

#endif // STORAGE_H
