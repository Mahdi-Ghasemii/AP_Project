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


       Product& Get_bill ();
       void Set_bill (Product _bill);
       Product& Get_mikh ();
       void Set_Mikh (Product _mikh);
       Product& Get_yonjeh ();
       void Set_Yonjeh (Product _yonjeh);
       Product& Get_egg ();
       void Set_Egg (Product _egg);
       Product& Get_milk ();
       void Set_Milk (Product _milk);
       Product& Get_pashm ();
       void Set_Pashm (Product _pashm);





private slots:
       void on_Upgrade_Storage_clicked();
       void on_Return_to_Farm_pbn_clicked();

       //  get signals from Farm class :

       void Get_Signal_From_Farm();

signals:
       void Send_Signal_to_Farm();
};

#endif // STORAGE_H
