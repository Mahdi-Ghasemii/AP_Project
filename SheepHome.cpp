#include "SheepHome.h"
#include "ui_SheepHome.h"
#include "Data.h"

SheepHome::SheepHome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SheepHome)
{
    ui->setupUi(this);
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
    if(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()>=3){
        if(Data::get_iterator()->get_coin()>=50){
            if(Data::get_iterator()->get_level()>=7){
                Data::get_iterator()->get_farm().get_storage().Get_mikh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()-3);
                Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()-50);
                Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+15);
                capacity*=2;
                //QMessageBox
                if(Data::get_iterator()->get_experience()>=Data::get_iterator()->get_experience_required_for_levelUp()){
                    Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
                    Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
                    //QMessageBox
                }
            }
            else {
                //QMessageBox
            }
        }
        else {
            //QMessageBox
        }
    }
    else {
        //QMessageBox
    }
}

void SheepHome::on_feeding_btn_clicked()
{
    if(Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Get_Number()>=stock_animal){
        if(difftime(feed_time,time(NULL))>10*24*3600){
            if (is_collected==true){
                Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Get_Number()-stock_animal);
                is_collected=false;
                feed_time=time(NULL);
                //QMessageBox
            }
            else {
                //QMessageBox
            }
        }
        else {
            //QMessageBox
        }
    }
    else {
        //QMessageBox
    }
}

void SheepHome::on_collect_btn_clicked()
{
    if(is_collected==false){
        if(difftime(feed_time,time(NULL))>10*24*3600){
            if(Data::get_iterator()->get_farm().get_storage().GetCapasity()-Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()>=stock_animal){
                if(Data::get_iterator()->get_coin()>=10*stock_animal){
                    is_collected=true;
                    Data::get_iterator()->get_farm().get_storage().Get_pashm().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_pashm().Get_Number()+stock_animal);
                    Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_pashm().Get_Number()+stock_animal);
                    Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()-10*stock_animal);
                }
                else {
                    //QMessageBox
                }
            }
            else {
                //QMessageBox
            }
        }
        else {
            //QMessageBox
        }
    }
    else {
        //QMessageBox
    }
}

void SheepHome::on_back_btn_clicked()
{
    this->close();
}

void SheepHome::Get_Signal_From_Farm()
{

}
