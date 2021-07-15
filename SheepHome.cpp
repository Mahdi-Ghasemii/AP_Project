#include "SheepHome.h"
#include "ui_SheepHome.h"
#include "Data.h"

SheepHome::SheepHome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SheepHome)
{
    ui->setupUi(this);
    capacity=2;
    stock_animal=0;
    level_habitat=1;
    feed_time=0;
    is_collected=true;
}

SheepHome::~SheepHome()
{
    delete ui;
}

void SheepHome::operator=(const SheepHome& p){
    capacity=p.capacity;
    stock_animal=p.stock_animal;
    level_habitat=p.level_habitat;
    feed_time=p.feed_time;
    is_collected=p.is_collected;
}

void SheepHome::on_upgrade_btn_clicked()
{
    if(Data::get_iterator()->get_level()>=7){
        if(Data::get_iterator()->get_coin()>=50){
           if(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()>=3){
                Data::get_iterator()->get_farm().get_storage().Get_mikh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()-3);
                Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()-50);
                Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+15);
                capacity*=2;
                level_habitat++;
                ui->capacity_lbl->setText(QString::number(capacity));
                ui->level_lbl->setText(QString::number(level_habitat));
                QMessageBox::information(this," ","ارتقا با موفقیت انجام شد");
                if(Data::get_iterator()->get_experience()>=Data::get_iterator()->get_experience_required_for_levelUp()){
                    Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
                    Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
                    QMessageBox::information(this," ","سطح شما با موفقیت افزایش یافت");
                }
            }
            else {
               QMessageBox::warning(this,"تذکر","میخ به اندازه کافی موجود نمی باشد");
            }
        }
        else {
            QMessageBox::warning(this,"تذکر","سکه به اندازه کافی موجود نمی باشد");
        }
    }
    else {
        QMessageBox::warning(this,"تذکر","سطح شما برای ارتقا باید حداقل 7 باشد");
    }
}

void SheepHome::on_feeding_btn_clicked()
{
    if(stock_animal!=0){
        if(Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Get_Number()>=stock_animal){
            if(difftime(time(NULL),feed_time)>10*24*3600){
                if (is_collected==true){
                    Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Get_Number()-stock_animal);
                    is_collected=false;
                    feed_time=time(NULL);
                    QMessageBox::information(this," ","غذا دادن با موفقیت انجام شد");
                }
                else {
                    QMessageBox::warning(this,"تذکر","شما هنوز پشم‌ها را نچیده‌اید");
                }
            }
            else {
                QMessageBox::warning(this,"تذکر","شما به تازگی به گوسفند‌ها غذا داده‌اید");
            }
        }
        else {
            QMessageBox::warning(this,"تذکر","یونجه به مقدار کافی در انبار موجود نمی باشد");
        }
    }
    else {
        QMessageBox::warning(this,"تذکر","حیوانی در آغل موجود نمی باشد");
    }
}

void SheepHome::on_collect_btn_clicked()
{
    if(Data::get_iterator()->get_coin()>=10*stock_animal){
        if(Data::get_iterator()->get_farm().get_storage().GetCapasity()-Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()>=stock_animal){
            if(difftime(time(NULL),feed_time)>10*24*3600){
                if(is_collected==false){
                    is_collected=true;
                    Data::get_iterator()->get_farm().get_storage().Get_pashm().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_pashm().Get_Number()+stock_animal);
                    Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_pashm().Get_Number()+stock_animal);
                    Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()-10*stock_animal);
                    QMessageBox::information(this," ","چیدن پشم با موفقیت انجام شد");
                }
                else {
                    QMessageBox::warning(this,"تذکر","پشم‌ها به تازگی چیده شده‌اند");
                }
            }
            else {
                QMessageBox::warning(this,"تذکر","شما امکان چیدن پشم را ندارید زیرا به تازگی به گوسفند‌ها غذا داده‌اید");
            }
        }
        else {
            QMessageBox::warning(this,"تذکر","فضا به مقدار کافی در انبار موجود نمی باشد");
        }
    }
    else {
        QMessageBox::warning(this,"تذکر","سکه به اندازه کافی موجود نمی باشد");
    }
}

void SheepHome::on_back_btn_clicked()
{
    this->close();
}

void SheepHome::Get_Signal_From_Farm()
{
    ui->capacity_lbl->setText(QString::number(capacity));
    ui->level_lbl->setText(QString::number(level_habitat));
    ui->stockanimal_lbl->setText(QString::number(stock_animal));
}
