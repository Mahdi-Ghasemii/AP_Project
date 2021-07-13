#include "ChickenHome.h"
#include "ui_ChickenHome.h"
#include "Data.h"

ChickenHome::ChickenHome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChickenHome)
{
    ui->setupUi(this);
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
    if(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()>0){
        if(Data::get_iterator()->get_coin()>=10){
            if(Data::get_iterator()->get_level()>=3){
                Data::get_iterator()->get_farm().get_storage().Get_mikh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()-1);
                Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()-10);
                Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+5);
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

void ChickenHome::on_feeding_btn_clicked()
{
    if(Data::get_iterator()->get_farm().get_siloo().Get_gandom().Get_Number() >=stock_animal){
        if(difftime(feed_time,time(NULL))>2*24*3600){
            if (is_collected==true){
                Data::get_iterator()->get_farm().get_siloo().Get_gandom().Set_Number(Data::get_iterator()->get_farm().get_siloo().Get_gandom().Get_Number()-stock_animal);
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

void ChickenHome::on_collect_btn_clicked()
{
    if(is_collected==false){
        if(difftime(feed_time,time(NULL))>2*24*3600){
            if(Data::get_iterator()->get_farm().get_storage().GetCapasity()-Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()>=stock_animal){
                is_collected=true;
                Data::get_iterator()->get_farm().get_storage().Get_egg().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_egg().Get_Number()+stock_animal);
                Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_egg().Get_Number()+stock_animal);
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

void ChickenHome::on_back_btn_clicked()
{
    this->close();
}

void ChickenHome::Get_Signal_From_Farm()
{

}
