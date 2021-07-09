#include "SheepHome.h"
#include "ui_SheepHome.h"

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

void SheepHome::upgrade(list<Player>::iterator it){

}

void SheepHome::feedeing(list<Player>::iterator it){
    if(it->get_farm().get_storage().get_yonjeh()>=stock_animal){
        if(difftime(feed_time,time(NULL))>10*24*3600){
            if (is_collected==true){
                it->get_farm().get_storage().set_yonjeh(it->get_farm().get_storage().get_yonjeh()-stock_animal);
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

void SheepHome::collect(list<Player>::iterator it){
    if(is_collected==false){
        if(difftime(feed_time,time(NULL))>10*24*3600){
            if(it->get_farm().get_storage().get_capacity()-it->get_farm().get_storage().get_occupid_capacity()>=stock_animal){
                if(it->get_coin()>=10*stock_animal){
                    is_collected=true;
                    it->get_farm().get_storage().get_pashm().set_number(it->get_farm().get_storage().get_pashm().get_number+stock_animal);
                    it->get_farm().get_storage().set_occupid_capacity(it->get_farm().get_storage().get_pashm().get_number+stock_animal);
                    it->set_coin(it->get_coin()-10*stock_animal);
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
