#include "CowHome.h"
#include "ui_CowHome.h"
#include "Data.h"
#include <QDebug>
CowHome::CowHome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CowHome)
{
    ui->setupUi(this);
    capacity=2;
    stock_animal=0;
    level_habitat=1;
    is_build=false;
    setFixedSize(403, 339);
}

CowHome::~CowHome()
{
    delete ui;
}

void CowHome::operator=(const CowHome& p){
    capacity=p.capacity;
    stock_animal=p.stock_animal;
    level_habitat=p.level_habitat;
    is_build=p.is_build;
}

void CowHome::build(){
    if(Data::get_iterator()->get_coin()>=20){
        if(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()>=3){
            Data::get_iterator()->get_farm().Get_MyThread().Set_build_CowHome(time(NULL));
            Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()-20);
            Data::get_iterator()->get_farm().get_storage().Get_mikh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()-3);
            Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()-3);
            QMessageBox::information(this," ","ساختن گاوداری با موفقیت آغاز شد");
        }
        else
            QMessageBox::warning(this,"تذکر","میخ به اندازه کافی موجود نمی باشد");
    }
    else
        QMessageBox::warning(this,"تذکر","سکه به اندازه کافی موجود نمی باشد");
}

void CowHome::on_upgrade_btn_clicked()
{
    if(Data::get_iterator()->get_farm().Get_MyThread().Get_upgrade_CowHome()==0){
        if(Data::get_iterator()->get_level()>=5){
            if(Data::get_iterator()->get_coin()>=15){
                if(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()>=2){
                    Data::get_iterator()->get_farm().get_storage().Get_mikh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()-2);
                    Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()-15);
                    Data::get_iterator()->get_farm().Get_MyThread().Set_upgrade_CowHome(time(NULL));
                    Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()-2);
                    QMessageBox::information(this," ","فرایند ارتقای گاوداری با موفقیت آغاز شد");
                }
                else
                    QMessageBox::warning(this,"تذکر","میخ به اندازه کافی موجود نمی باشد");

            }
            else
                QMessageBox::warning(this,"تذکر","سکه به اندازه کافی موجود نمی باشد");

        }
        else
            QMessageBox::warning(this,"تذکر","سطح شما برای ارتقا باید حداقل 5 باشد");

    }
    else
        QMessageBox::warning(this,"تذکر","گاوداری در حال ارتقا یافتن است");
}

void CowHome::on_feeding_btn_clicked()
{
    if(stock_animal!=0){
        if(Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Get_Number()>=2*stock_animal){
            if(time(NULL),Data::get_iterator()->get_farm().Get_MyThread().Get_feed_time_cow()>3*24*3600){
                if (Data::get_iterator()->get_farm().Get_MyThread().Get_feed_time_cow()==0){
                    Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Get_Number()-2*stock_animal);
                    Data::get_iterator()->get_farm().Get_MyThread().Set_feed_time_cow(time(NULL));
                    Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+3*stock_animal);
                    QMessageBox::information(this," ","غذا دادن با موفقیت انجام شد");
                    if(Data::get_iterator()->get_experience()>=Data::get_iterator()->get_experience_required_for_levelUp()){
                        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
                        Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
                        QMessageBox::information(this," ","سطح شما با موفقیت افزایش یافت");
                    }
                }
                else {
                    QMessageBox::warning(this,"تذکر","شما هنوز شیرها را ندوشیده‌اید");
                }
            }
            else {
                QMessageBox::warning(this,"تذکر","شما به تازگی به گاو‌ها غذا داده‌اید");
            }
        }
        else {
            QMessageBox::warning(this,"تذکر","یونجه به مقدار کافی در انبار موجود نمی باشد");
        }
    }
    else {
        QMessageBox::warning(this,"تذکر","حیوانی در گاوداری موجود نمی باشد");
    }

}

void CowHome::on_collect_btn_clicked()
{
    if(Data::get_iterator()->get_farm().get_storage().GetCapasity()-Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()>=stock_animal){
        if(time(NULL)-Data::get_iterator()->get_farm().Get_MyThread().Get_feed_time_cow()>3*24*3600){
            if(Data::get_iterator()->get_farm().Get_MyThread().Get_feed_time_cow()!=0){
                Data::get_iterator()->get_farm().Get_MyThread().Set_feed_time_cow(0);
                Data::get_iterator()->get_farm().get_storage().Get_milk().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_milk().Get_Number()+stock_animal);
                Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_milk().Get_Number()+stock_animal);
                Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+5*stock_animal);
                for(int i=0;i<stock_animal;i++){
                    Data::get_iterator()->get_farm().Get_MyThread().Push_Back_on_buy_Milk(time(NULL));
                }
                QMessageBox::information(this," ","برداشت شیر با موفقیت انجام شد");
                if(Data::get_iterator()->get_experience()>=Data::get_iterator()->get_experience_required_for_levelUp()){
                    Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
                    Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
                    QMessageBox::information(this," ","سطح شما با موفقیت افزایش یافت");
                }
            }
            else {
                QMessageBox::warning(this,"تذکر","لطفا ابتدا به گاوها غذا دهید");
            }
        }
        else {
            QMessageBox::warning(this,"تذکر","شما امکان برداشت شیر را ندارید زیرا به تازگی به گاوها غذا داده‌اید");
        }
    }
    else {
        QMessageBox::warning(this,"تذکر","فضا به مقدار کافی در انبار موجود نمی باشد");
    }
}

void CowHome::on_back_btn_clicked()
{
    this->close();
}

void CowHome::Get_Signal_From_Farm()
{
    ui->capacity_lbl->setText(QString::number(capacity));
    ui->level_lbl->setText(QString::number(level_habitat));
    ui->stockanimal_lbl->setText(QString::number(stock_animal));
}
