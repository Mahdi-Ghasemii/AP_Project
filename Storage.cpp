#include "Storage.h"
#include "ui_Storage.h"
#include <QMessageBox>
#include <math.h>
#include "Data.h"
#include <QDebug>
Storage::Storage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Storage)
{
    ui->setupUi(this);




    this->yonjeh.Set_Number(1);

    this->occupied_capacity = 2;
    this->building_Level = 1;

    this->time_add_milk = 0;

    if(capasity == 8){
        qDebug()<<"8 M" ;

    }
    if(capasity == 5){
        qDebug()<<"5 M" ;

    }
    this->mikh.Set_Number(1);
    this->capasity = 5;

}

void Storage::operator=(const Storage& temp){

    this->bill = temp.bill;
    this->mikh = temp.mikh;
    this->milk = temp.milk;
    this->yonjeh = temp.yonjeh;
    this->egg = temp.egg;
    this->pashm = temp.pashm;
    this->time_add_milk = temp.time_add_milk;


    this->capasity = temp.capasity;
    this->building_Level = temp.building_Level;
    this->occupied_capacity = temp.occupied_capacity;

    qDebug()<<"In storage constructor :" << Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number();

}

Storage::Storage(const Storage &temp)
{
    this->operator=(temp);
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
        if(Data::get_iterator()->get_farm().Get_MyThread().Get_upgrade_Storage() !=0 ){
            QMessageBox::warning(this,"","شما قبلا درخواست ارتقا داده اید !.",QMessageBox::Ok);
            return;
        }

        if(Data::get_iterator()->get_level() < this->building_Level){

            QMessageBox::warning(this,"","سطح انبار نمی تواند از سطح بازیکن بیشتر شود.",QMessageBox::Ok);
            return;
        }

        else if(!(this->mikh.Get_Number() >= this->building_Level)){

            QMessageBox::warning(this,"","تعداد ميخ براي ارتقا انبار كافي نمي باشد .",QMessageBox::Ok);
            return;
        }

        else if(!(this->bill.Get_Number() >= this->building_Level -1)){

            QMessageBox::warning(this,"","تعداد بيل براي ارتقا انبار كافي نمي باشد",QMessageBox::Ok);
            return;
        }
        else if(!(Data::get_iterator()->get_coin() >= pow(this->building_Level,3) * 10)){

            QMessageBox::warning(this,"","تعداد سکه براي ارتقا سيلو كافي نمي باشد",QMessageBox::Ok);
            return;
        }

        else {

            QMessageBox::information(this,"","درخواست شما برای ارتقا انبار با موفقیت ثبت شد.",QMessageBox::Ok);

            this->mikh.Set_Number(this->mikh.Get_Number() - this->building_Level);
            this->bill.Set_Number(this->bill.Get_Number() - (this->building_Level -1));
            this->occupied_capacity-=(2 * building_Level -1);

            Data::get_iterator()->set_coin(Data::get_iterator()->get_coin() - pow(this->building_Level,3) * 10);



            ui->Occupied_Capasity->setText(QString::number(this->occupied_capacity));
            ui->Storage_Capasity->setText(QString::number(this->capasity));



            ui->Mikh_Available->setText(QString::number(this->mikh.Get_Number()));
            ui->Bill_Available->setText(QString::number(this->bill.Get_Number()));

            qDebug() << this->mikh.Get_Number();
            time_t now = time(NULL);
            Data::get_iterator()->get_farm().Get_MyThread().Set_upgrade_Storage(now);
            qDebug()<<now<<"\n"<< Data::get_iterator()->get_farm().Get_MyThread().Get_upgrade_Storage();
            return;
        }

}

void Storage::on_Return_to_Farm_pbn_clicked()
{

    emit Send_Signal_to_Farm();
    this->close();
}

void Storage::Get_Signal_From_Farm()
{

    //*******************************************************************
    // Set 3 arguman of storage building

    ui->Occupied_Capasity->setText(QString::number(this->occupied_capacity));
    ui->Storage_Level->setText(QString::number(this->building_Level));
    ui->Storage_Capasity->setText(QString::number(this->capasity));


    //*******************************************************************
    // Set Number of available psroducts in storage

    ui->Milk_Available->setText(QString::number(this->milk.Get_Number()));
    ui->Egg_Availbale->setText(QString::number(this->egg.Get_Number()));
    ui->Wool_Available->setText(QString::number(this->pashm.Get_Number()));
    ui->Yonjeh_Available->setText(QString::number(this->yonjeh.Get_Number()));
    ui->Mikh_Available->setText(QString::number(this->mikh.Get_Number()));
    ui->Bill_Available->setText(QString::number(this->bill.Get_Number()));
}

