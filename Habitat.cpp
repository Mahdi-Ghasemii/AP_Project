#include "Habitat.h"

Habitat::Habitat()
{

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

bool Habitat::get_is_build(){
    return is_build;
}

void Habitat::set_is_build(bool _is_build){
    is_build=_is_build;
}
