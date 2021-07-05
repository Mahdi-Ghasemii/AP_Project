#include "Habitat.h"
#include "ui_Habitat.h"

Habitat::Habitat() :
    ui(new Ui::Habitat)
{
    ui->setupUi(this);
}

void Habitat::upgrade(){

}

void Habitat::feedeing(){

}

void Habitat::collect(){

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
