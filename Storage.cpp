#include "Storage.h"
#include "ui_Storage.h"
#include <QMessageBox>
#include <math.h>

Storage::Storage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Storage)
{
    ui->setupUi(this);


    this->bill.Set_Type("bill");
    this->mikh.Set_Type("mikh");
    this->yonjeh.Set_Type("yonjeh");
    this->egg.Set_Type("egg");
    this->milk.Set_Type("milk");
    this->pashm.Set_Type("pashm");
    this->bill.Set_Type("bill");

    this->capasity = 5;
    this->yonjeh.Set_Number(1);
    this->mikh.Set_Number(1);

    this->time_add_milk = time(NULL);
}



Product Storage::Get_bill ()
{
    return this->bill;
}
void Storage::Set_bill (Product _bill)
{
    this->bill = _bill;
}


Product Storage::Get_mikh ()
{
    return this->mikh;
}
void Storage::Set_Mikh (Product _mikh)
{
    this->mikh = _mikh;
}


Product Storage::Get_yonjeh ()
{
    return this->yonjeh;
}
void Storage::Set_Yonjeh (Product _yonjeh)
{
    this->yonjeh = _yonjeh;
}


Product Storage::Get_egg ()
{
    return this->egg;
}
void Storage::Set_Egg (Product _egg)
{
    this->egg = _egg;
}


Product Storage::Get_milk ()
{
    return this->milk;
}
void Storage::Set_Milk (Product _milk)
{
    this->milk = _milk;
}


Product Storage::Get_pashm ()
{
    return this->pashm;
}
void Storage::Set_Pashm (Product _pashm)
{
    this->pashm = _pashm;
}



void Storage::Increase_Capasity (int coin,int level)
{

    if(level<=this->building_Level){
        //warning :QMessageBox()
        return;
    }

    else if(!(this->mikh.Get_Number() >= this->building_Level && this->bill.Get_Number()-1 >= this->building_Level
            && coin >= pow(this->building_Level,3) * 10)){

        // Warning : QmessageBox()
    }

    else {
        this->building_Level = round(this->building_Level *3 / 2);

        //Information : Qmessagebox()
    }

}

void Storage::Check_Storages_Product ()
{

}

Storage::~Storage(){
    delete ui;
}
