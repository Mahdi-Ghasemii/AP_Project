#ifndef SILOO_H
#define SILOO_H

#include <QWidget>
#include "Product.h"

namespace Ui {
class Siloo;
}

class Siloo : public QWidget
{
    Q_OBJECT

private:
        Product gandom;
        Ui::Siloo *ui;

public:

        Siloo ();
        Product Get_gandom ();
        void Set_Gandom (Product _gandom);

        void Increase_Capacity ();
        void Check_Siloos_Product ();


};

#endif // SILOO_H
