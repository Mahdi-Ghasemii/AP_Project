#include "CowHome.h"
#include "ui_CowHome.h"
#include "Data.h"

CowHome::CowHome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CowHome)
{
    ui->setupUi(this);
}

CowHome::~CowHome()
{
    delete ui;
}

void CowHome::operator=(const CowHome& p){
    capacity=p.capacity;
    stock_animal=p.stock_animal;
    level_habitat=p.level_habitat;
    feed_time=p.feed_time;
    is_collected=p.is_collected;
}

void CowHome::on_upgrade_btn_clicked()
{
    if(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()>=2){
        if(Data::get_iterator()->get_coin()>=15){
            if(Data::get_iterator()->get_level()>=5){
                Data::get_iterator()->get_farm().get_storage().Get_mikh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()-2);
                Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()-15);
                Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+6);
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

void CowHome::on_feeding_btn_clicked()
{
    if(Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Get_Number()>=2*stock_animal){
        if(difftime(feed_time,time(NULL))>3*24*3600){
            if (is_collected==true){
                Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Get_Number()-2*stock_animal);
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

void CowHome::on_collect_btn_clicked()
{
    if(is_collected==false){
        if(difftime(feed_time,time(NULL))>3*24*3600){
            if(Data::get_iterator()->get_farm().get_storage().GetCapasity()-Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()>=stock_animal){
                is_collected=true;
                Data::get_iterator()->get_farm().get_storage().Get_milk().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_milk().Get_Number()+stock_animal);
                Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_milk().Get_Number()+stock_animal);
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

void CowHome::on_back_btn_clicked()
{
    this->close();
}

void CowHome::Get_Signal_From_Farm()
{

}
