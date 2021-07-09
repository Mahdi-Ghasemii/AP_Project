#include "CowHome.h"
#include "ui_CowHome.h"

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

void CowHome::upgrade(list<Player>::iterator it){

}

void CowHome::feedeing(list<Player>::iterator it){
    if(it->get_farm().get_storage().get_yonjeh()>=2*stock_animal){
        if(difftime(feed_time,time(NULL))>3*24*3600){
            if (is_collected==true){
                it->get_farm().get_storage().set_yonjeh(it->get_farm().get_storage().get_yonjeh()-2*stock_animal);
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

void CowHome::collect(list<Player>::iterator it){
    if(is_collected==false){
        if(difftime(feed_time,time(NULL))>3*24*3600){
            if(it->get_farm().get_storage().get_capacity()-it->get_farm().get_storage().get_occupid_capacity()>=stock_animal){
                is_collected=true;
                it->get_farm().get_storage().get_milk().set_number(it->get_farm().get_storage().get_milk().get_number+stock_animal);
                it->get_farm().get_storage().set_occupid_capacity(it->get_farm().get_storage().get_milk().get_number+stock_animal);
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
