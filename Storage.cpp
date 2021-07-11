#include "Storage.h"
#include "ui_Storage.h"
#include <QMessageBox>
#include <math.h>
#include "Data.h"

Storage::Storage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Storage)
{
    ui->setupUi(this);




    this->capasity = 5;
    this->yonjeh.Set_Number(1);
    this->mikh.Set_Number(1);

    this->time_add_milk = time(NULL);

    //*******************************************************************
    // Set 3 arguman of storage building

    ui->Occupied_Capasity->setText(QString::number(this->occupied_capacity));
    ui->Storage_Level->setText(QString::number(this->building_Level));
    ui->Storage_Level->setText(QString::number(this->building_Level));


    //*******************************************************************
    // Set Number of available products in storage

    ui->Milk_Available->setText(QString::number(this->milk.Get_Number()));
    ui->Egg_Availbale->setText(QString::number(this->egg.Get_Number()));
    ui->Wool_Available->setText(QString::number(this->pashm.Get_Number()));
    ui->Yonjeh_Available->setText(QString::number(this->yonjeh.Get_Number()));
    ui->Mikh_Available->setText(QString::number(this->mikh.Get_Number()));
    ui->Bill_Available->setText(QString::number(this->bill.Get_Number()));


}



Product& Storage::Get_bill ()
{
    return this->bill;
}
void Storage::Set_bill (Product _bill)
{
    this->bill = _bill;
}


Product& Storage::Get_mikh ()
{
    return this->mikh;
}
void Storage::Set_Mikh (Product _mikh)
{
    this->mikh = _mikh;
}


Product& Storage::Get_yonjeh ()
{
    return this->yonjeh;
}
void Storage::Set_Yonjeh (Product _yonjeh)
{
    this->yonjeh = _yonjeh;
}


Product& Storage::Get_egg ()
{
    return this->egg;
}
void Storage::Set_Egg (Product _egg)
{
    this->egg = _egg;
}


Product& Storage::Get_milk ()
{
    return this->milk;
}
void Storage::Set_Milk (Product _milk)
{
    this->milk = _milk;
}


Product& Storage::Get_pashm ()
{
    return this->pashm;
}
void Storage::Set_Pashm (Product _pashm)
{
    this->pashm = _pashm;
}

Storage::~Storage(){
    delete ui;
}

// Slots



void Storage::on_Upgrade_Storage_clicked()
{

        if(Data::get_iterator()->get_level() <= this->building_Level){

            QMessageBox::warning(this,"","سطح انبار نمی تواند از سطح بازیکن بیشتر شود.",QMessageBox::Ok);
        }

        else if(!(this->mikh.Get_Number() >= this->building_Level)){

            QMessageBox::warning(this,"","تعداد ميخ براي ارتقا سيلو كافي نمي باشد .",QMessageBox::Ok);
        }

        else if(!(this->bill.Get_Number()-1 >= this->building_Level)){

            QMessageBox::warning(this,"","تعداد بيل براي ارتقا سيلو كافي نمي باشد",QMessageBox::Ok);
        }
        else if(!(Data::get_iterator()->get_coin() >= pow(this->building_Level,3) * 10)){

            QMessageBox::warning(this,"","تعداد سکه براي ارتقا سيلو كافي نمي باشد",QMessageBox::Ok);
        }

        else {
            this->building_Level = round(this->building_Level *3 / 2);

            QMessageBox::information(this,"","انبار با موفقیت ارتقا پیدا کرد",QMessageBox::Ok);
        }

}

void Storage::on_Return_to_Farm_pbn_clicked()
{
    this->close();
}

