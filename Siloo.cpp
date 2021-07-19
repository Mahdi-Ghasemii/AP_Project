#include "Siloo.h"
#include "ui_Siloo.h"
#include <QString>
#include "Data.h"
#include <QMessageBox>
#include <time.h>
Siloo::Siloo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Siloo)
{
    ui->setupUi(this);
    setFixedSize(410, 295);
    this->gandom.Set_Number(1);
    this->capasity = 10;
    this->occupied_capacity = 1;
    this->building_Level = 1;



}

void Siloo::operator =(const Siloo& temp){

    this->gandom = temp.gandom;

    this->capasity = temp.capasity;
    this->building_Level = temp.building_Level;
    this->occupied_capacity = temp.occupied_capacity;
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

        if(Data::get_iterator()->get_farm().Get_MyThread().Get_upgrade_Siloo() !=0 ){
            QMessageBox::warning(this,"","شما قبلا درخواست ارتقا داده اید !.",QMessageBox::Ok);
            return;
        }

        else if(Data::get_iterator()->get_level() > 1 && Data::get_iterator()->get_level() <= this->building_Level){

             QMessageBox::warning(this,"","حداکثر سطح انبار رعایت نشده است.",QMessageBox::Ok);
             return;
         }

       else  if(!(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number() >= this->building_Level*2)){

            QMessageBox::warning(this,"کمبود منابع","تعداد میخ ها برای ارتقا سیلو کافی نمی باشد .",QMessageBox::Ok);
            return;
        }
        else if(!(Data::get_iterator()->get_coin() >= pow((this->building_Level*2),2))*100){
            QMessageBox::warning(this,"کمبود منابع","تعداد سکه ها برای ارتقا سیلو کافی نمی باشد",QMessageBox::Ok);
            return;
        }
        else if(!(Data::get_iterator()->get_farm().get_storage().Get_bill().Get_Number() >= this->building_Level-2)){
            QMessageBox::warning(this,"کمبود منابع","تعداد بیل ها برای ارتقا سیلو کافی نمی باشد",QMessageBox::Ok);
            return;
        }

        else {

            Data::get_iterator()->get_farm().get_storage().Get_mikh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number() - (this->building_Level*2));

            Data::get_iterator()->get_farm().get_storage().Get_bill().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_bill().Get_Number() - (this->building_Level-2));

            Data::get_iterator()->set_coin(Data::get_iterator()->get_coin() - pow((this->building_Level*2),2)*100);
            QMessageBox::information(this,"","درخواست شما برای ارتقا سیلو با موفقیت ثبت شد.",QMessageBox::Ok);

            ui->Siloo_Capacity->setText(QString::number(this->capasity));
            ui->Gandom_Available->setText(QString::number(this->occupied_capacity));
            ui->Siloo_Level->setText(QString::number(this->building_Level));

            time_t now = time(NULL);
            Data::get_iterator()->get_farm().Get_MyThread().Set_upgrade_Siloo(now);

            return;
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
    emit Send_Signal_to_Farm();
    this->close();
}




