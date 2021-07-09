#include "ChickenHome.h"
#include "ui_ChickenHome.h"

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

void ChickenHome::upgrade(list<Player>::iterator it){

}

void ChickenHome::feedeing(list<Player>::iterator it){
    if(it->get_farm().get_siloo().Get_gandom() >=stock_animal){
        if(difftime(feed_time,time(NULL))>2*24*3600){
            if (is_collected==true){
                it->get_farm().get_siloo().set_gandom(it->get_farm().get_siloo().get_gandom()-stock_animal);
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

void ChickenHome::collect(list<Player>::iterator it){
    if(is_collected==false){
        if(difftime(feed_time,time(NULL))>2*24*3600){
            if(it->get_farm().get_storage().get_capacity()-it->get_farm().get_storage().get_occupid_capacity()>=stock_animal){
                is_collected=true;
                it->get_farm().get_storage().get_egg().set_number(it->get_farm().get_storage().get_egg().get_number+stock_animal);
                it->get_farm().get_storage().set_occupid_capacity(it->get_farm().get_storage().get_egg().get_number+stock_animal);
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
