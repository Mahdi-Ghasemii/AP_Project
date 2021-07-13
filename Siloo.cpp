#include "Siloo.h"
#include "ui_Siloo.h"
#include <QString>
#include "Data.h"
#include <QMessageBox>

Siloo::Siloo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Siloo)
{
    ui->setupUi(this);

    this->gandom.Set_Number(1);
    this->capasity = 10;
    this->occupied_capacity = 1;
    this->building_Level = 1;


}


Product& Siloo::Get_gandom ()
{
    return this->gandom;
}

void Siloo::Set_Gandom (Product _gandom)
{
    gandom = _gandom;
}

Siloo::~Siloo(){
    delete ui;
}

// Slots

void Siloo::on_Upgrade_Siloo_clicked()
{


        if(!(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number() >= this->building_Level*2)){

            QMessageBox::warning(this,"کمبود منابع","تعداد میخ ها برای ارتقا سیلو کافی نمی باشد .",QMessageBox::Ok);
        }
        else if(!( Data::get_iterator()->get_coin() >= pow((this->building_Level*2),2))*100){
            QMessageBox::warning(this,"کمبود منابع","تعداد سکه ها برای ارتقا سیلو کافی نمی باشد",QMessageBox::Ok);
        }
        else if(!( Data::get_iterator()->get_farm().get_storage().Get_bill().Get_Number() >= this->building_Level-2)){
            QMessageBox::warning(this,"کمبود منابع","تعداد بیل ها برای ارتقا سیلو کافی نمی باشد",QMessageBox::Ok);
        }

        else {
            this->building_Level *= 2;
            QMessageBox::information(this,"","سیلو با موفقیت ارتقا پیدا کرد .",QMessageBox::Ok);

            Data::get_iterator()->set_experience(Data::get_iterator()->get_experience() + (this->building_Level * 2));
        }


}

void Siloo::Get_Signal_From_Farm()
{

    ui->Siloo_Capacity->setText(QString::number(this->capasity));
    ui->Gandom_Available->setText(QString::number(this->occupied_capacity));
    ui->Siloo_Level->setText(QString::number(this->building_Level));
}

void Siloo::on_Return_to_Farm_clicked()
{
    this->close();
}




