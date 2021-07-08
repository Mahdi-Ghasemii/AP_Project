#include "Habitat.h"
#include "ui_Habitat.h"

Habitat::Habitat() :
    ui(new Ui::Habitat)
{
    ui->setupUi(this);
}

void Habitat::upgrade(list<Player>::iterator it){

}

void Habitat::feedeing(list<Player>::iterator it){
    if(type=="chicken"){
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

    else if(type=="cow"){
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

    else if(type=="sheep"){
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
}

void Habitat::collect(list<Player>::iterator it){
    if(type=="chicken"){
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

    else if(type=="cow"){
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

    else if(type=="sheep"){
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
}

void Habitat::set_capacity(int _capacity){
    capacity=_capacity;
}

int Habitat::get_capacity(){
    return capacity;
}

void Habitat::set_stock_animal(int _stock_animal){
    stock_animal=_stock_animal;
}

int Habitat::get_stock_animal(){
    return stock_animal;
}

void Habitat::set_level_habitat(int _level_habitat){
    level_habitat=_level_habitat;
}

int Habitat::get_level_habitat(){
    return level_habitat;
}

void Habitat::set_feed_time(time_t _feed_time){
    feed_time=_feed_time;
}

time_t Habitat::get_feed_time(){
    return feed_time;
}

void Habitat::set_type(string _type){
    type=_type;
}
