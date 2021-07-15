#include "ChickenHome.h"
#include "ui_ChickenHome.h"
#include "Data.h"

ChickenHome::ChickenHome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChickenHome)
{
    ui->setupUi(this);
    capacity=2;
    stock_animal=0;
    level_habitat=1;
    feed_time=0;
    is_collected=true;
}

ChickenHome::~ChickenHome()
{
    delete ui;
}

void ChickenHome::operator=(const ChickenHome& p){
    capacity=p.capacity;
    stock_animal=p.stock_animal;
    level_habitat=p.level_habitat;
    feed_time=p.feed_time;
    is_collected=p.is_collected;
}

void ChickenHome::on_upgrade_btn_clicked()
{
    if(Data::get_iterator()->get_level()>=3){
        if(Data::get_iterator()->get_coin()>=10){
            if(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()>0){
                Data::get_iterator()->get_farm().get_storage().Get_mikh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()-1);
                Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()-10);
                Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+5);
                capacity*=2;
                level_habitat++;
                ui->capacity_lbl->setText(QString::number(capacity));
                ui->level_lbl->setText(QString::number(level_habitat));
                QMessageBox::information(this,"","ارتقا با موفقیت انجام شد");
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
        QMessageBox::warning(this,"تذکر","سطح شما برای ارتقا باید حداقل 3 باشد");
    }
}

void ChickenHome::on_feeding_btn_clicked()
{
    if(stock_animal!=0){
        if(Data::get_iterator()->get_farm().get_siloo().Get_gandom().Get_Number() >=stock_animal){
            if(difftime(time(NULL),feed_time)>2*24*3600){
                if (is_collected==true){
                    Data::get_iterator()->get_farm().get_siloo().Get_gandom().Set_Number(Data::get_iterator()->get_farm().get_siloo().Get_gandom().Get_Number()-stock_animal);
                    is_collected=false;
                    feed_time=time(NULL);
                    QMessageBox::information(this," ","غذا دادن با موفقیت انجام شد");
                }
                else {
                    QMessageBox::warning(this,"تذکر","شما هنوز تخم مرغ‌ها را جمع آوری نکرده‌اید");
                }
            }
            else {
                QMessageBox::warning(this,"تذکر","شما به تازگی به مرغ‌ها غذا داده‌اید");
            }
        }
        else {
            QMessageBox::warning(this,"تذکر","گندم به مقدار کافی در سیلو موجود نمی باشد");
        }
    }
    else {
        QMessageBox::warning(this,"تذکر","حیوانی در مرغداری موجود نمی باشد");
    }
}

void ChickenHome::on_collect_btn_clicked()
{
    if(Data::get_iterator()->get_farm().get_storage().GetCapasity()-Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()>=stock_animal){
        if(difftime(time(NULL),feed_time)>2*24*3600){
            if(is_collected==false){
                is_collected=true;
                Data::get_iterator()->get_farm().get_storage().Get_egg().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_egg().Get_Number()+stock_animal);
                Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_egg().Get_Number()+stock_animal);
                QMessageBox::information(this," ","برداشت تخم مرغ‌ با موفقیت انجام شد");
            }
            else {
                QMessageBox::warning(this,"تذکر","تخم مرغ‌ها به تازگی برداشت شده‌اند");
            }
        }
        else {
            QMessageBox::warning(this,"تذکر","شما امکان برداشت تخم مرغ‌‌ را ندارید زیرا به تازگی به مرغ‌ها غذا داده‌اید");
        }
    }
    else {
        QMessageBox::warning(this,"تذکر","فضا به مقدار کافی در انبار موجود نمی باشد");
    }
}

void ChickenHome::on_back_btn_clicked()
{
    emit Send_Signal_to_Farm();
    this->close();
}

void ChickenHome::Get_Signal_From_Farm()
{
    ui->capacity_lbl->setText(QString::number(capacity));
    ui->level_lbl->setText(QString::number(level_habitat));
    ui->stockanimal_lbl->setText(QString::number(stock_animal));
}
