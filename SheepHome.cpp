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
    is_build=false;
}

SheepHome::~SheepHome()
{
    delete ui;
}

void SheepHome::operator=(const SheepHome& p){
    capacity=p.capacity;
    stock_animal=p.stock_animal;
    level_habitat=p.level_habitat;
    is_build=p.is_build;
}

void SheepHome::build(){
    if(Data::get_iterator()->get_coin()>=50){
        if(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()>=4){
            if(Data::get_iterator()->get_farm().get_storage().Get_bill().Get_Number()>=2){
                Data::get_iterator()->get_farm().Get_MyThread().Set_build_SheepHome(time(NULL));
                Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()-10);
                Data::get_iterator()->get_farm().get_storage().Get_mikh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()-2);
                Data::get_iterator()->get_farm().get_storage().Get_bill().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_bill().Get_Number()-2);
                QMessageBox::information(this," ","ساختن آغل با موفقیت آغاز شد");
            }
            else
                QMessageBox::warning(this,"تذکر","بیل به اندازه کافی موجود نمی باشد");
        }
        else
            QMessageBox::warning(this,"تذکر","میخ به اندازه کافی موجود نمی باشد");
    }
    else
        QMessageBox::warning(this,"تذکر","سکه به اندازه کافی موجود نمی باشد");
}

void SheepHome::on_upgrade_btn_clicked()
{
    if(Data::get_iterator()->get_farm().Get_MyThread().Get_upgrade_SheepHome()==0){
        if(Data::get_iterator()->get_level()>=7){
            if(Data::get_iterator()->get_coin()>=50){
               if(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()>=3){
                    Data::get_iterator()->get_farm().get_storage().Get_mikh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()-3);
                    Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()-50);
                    Data::get_iterator()->get_farm().Get_MyThread().Set_upgrade_SheepHome(time(NULL));
                    QMessageBox::information(this," ","فرایند ارتقای آغل با موفقیت آغاز شد");
                }
                else
                   QMessageBox::warning(this,"تذکر","میخ به اندازه کافی موجود نمی باشد");

            }
            else
                QMessageBox::warning(this,"تذکر","سکه به اندازه کافی موجود نمی باشد");

        }
        else
            QMessageBox::warning(this,"تذکر","سطح شما برای ارتقا باید حداقل 7 باشد");

    }
    else
        QMessageBox::warning(this,"تذکر","آغل در حال ارتقا یافتن است");
}

void SheepHome::on_feeding_btn_clicked()
{
    if(stock_animal!=0){
        if(Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Get_Number()>=stock_animal){
            if(time(NULL),Data::get_iterator()->get_farm().Get_MyThread().Get_feed_time_sheep()>10*24*3600){
                if (Data::get_iterator()->get_farm().Get_MyThread().Get_feed_time_sheep()==0){
                    Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Get_Number()-stock_animal);
                    Data::get_iterator()->get_farm().Get_MyThread().Set_feed_time_sheep(time(NULL));
                    Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+7*stock_animal);
                    QMessageBox::information(this," ","غذا دادن با موفقیت انجام شد");
                    if(Data::get_iterator()->get_experience()>=Data::get_iterator()->get_experience_required_for_levelUp()){
                        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
                        Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
                        QMessageBox::information(this," ","سطح شما با موفقیت افزایش یافت");
                    }
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
            if(time(NULL),Data::get_iterator()->get_farm().Get_MyThread().Get_feed_time_sheep()>10*24*3600){
                if(Data::get_iterator()->get_farm().Get_MyThread().Get_feed_time_sheep()!=0){
                    Data::get_iterator()->get_farm().Get_MyThread().Set_feed_time_sheep(0);
                    Data::get_iterator()->get_farm().get_storage().Get_pashm().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_pashm().Get_Number()+stock_animal);
                    Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_pashm().Get_Number()+stock_animal);
                    Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()-10*stock_animal);
                    Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+9*stock_animal);
                    QMessageBox::information(this," ","چیدن پشم با موفقیت انجام شد");
                    if(Data::get_iterator()->get_experience()>=Data::get_iterator()->get_experience_required_for_levelUp()){
                        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
                        Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
                        QMessageBox::information(this," ","سطح شما با موفقیت افزایش یافت");
                    }
                }
                else {
                    QMessageBox::warning(this,"تذکر","لطفا ابتدا به گوسفند‌ها غذا دهید");
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
