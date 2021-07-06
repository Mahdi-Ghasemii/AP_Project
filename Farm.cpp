#include "Farm.h"
#include "ui_Farm.h"

Farm::Farm() :
    ui(new Ui::Farm)
{
    ui->setupUi(this);
}

Storage& Farm::get_storage(){
    return storage;
}

Store& Farm::get_store(){
    return store;
}

Siloo& Farm::get_siloo(){
    return siloo;
}

Ranking& Farm::get_ranking(){
    return ranking;
}

Habitat& Farm::get_chickenHome(){
    return chickenHome;
}

Habitat& Farm::get_cowHome(){
    return cowHome;
}

Habitat& Farm::get_sheepHome(){
    return sheepHome;
}
