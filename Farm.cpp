#include "Farm.h"
#include "ui_Farm.h"
#include "Storage.h"
#include "Store.h"
#include "Siloo.h"


Farm::Farm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Farm)
{
    ui->setupUi(this);
}

Farm::~Farm(){
    delete ui;
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

ChickenHome& Farm::get_chickenHome(){
    return chickenHome;
}

CowHome& Farm::get_cowHome(){
    return cowHome;
}

SheepHome& Farm::get_sheepHome(){
    return sheepHome;
}



void Farm::on_Storage_pbn_clicked()
{
   storage.show();
}


void Farm::on_Siloo_pbn_clicked()
{
    siloo.show();
}


void Farm::on_YonjehFarm_pbn_clicked()
{
    yonjeFarm.show();
}


void Farm::on_GandomFarm_pbn_clicked()
{
    gandomFarm.show();
}


void Farm::on_SheepHome_pbn_clicked()
{
    sheepHome.show();
}


void Farm::on_ChickenHome_pbn_clicked()
{
    chickenHome.show();
}


void Farm::on_CowHome_pbn_clicked()
{
    cowHome.show();
}

