#include "Siloo.h"
#include "ui_Siloo.h"

/*Siloo::Siloo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Siloo)
{
    ui->setupUi(this);
}*/

Siloo::Siloo ()
{
    this->gandom.Set_Type("gandom");
}

Product Siloo::Get_gandom ()
{
    return this->gandom;
}

void Siloo::Set_Gandom (Product _gandom)
{
    gandom = _gandom;
}

void Siloo::Increase_Capacity ()
{

}

void Siloo::Check_Siloos_Product ()
{

}
