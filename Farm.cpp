#include "Farm.h"
#include "ui_Farm.h"
#include "Storage.h"
#include "Store.h"
#include "Siloo.h"
#include "Data.h"

Farm::Farm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Farm)
{
    ui->setupUi(this);


    // write connects here :

    connect(&siloo, SIGNAL(Send_Signal_to_Farm()),this,SLOT(Show_Farm_Class()));
    connect(&storage, SIGNAL(Send_Signal_to_Farm()),this,SLOT(Show_Farm_Class()));
    connect(&store, SIGNAL(Send_Signal_to_Farm()),this,SLOT(Show_Farm_Class()));

    connect(this, SIGNAL(Send_Signal_to_Siloo()),&store,SLOT(Get_Signal_From_Farm()));
    connect(this, SIGNAL(Send_Signal_to_Storage()),&store,SLOT(Get_Signal_From_Farm()));
    connect(this, SIGNAL(Send_Signal_to_Store()),&store,SLOT(Get_Signal_From_Farm()));
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

void Farm::operator=(const Farm& p){
    storage=p.storage;
    store=p.store;
    siloo=p.siloo;
    ranking=p.ranking;
    chickenHome=p.chickenHome;
    cowHome=p.cowHome;
    sheepHome=p.sheepHome;
    yonjeFarm=p.yonjeFarm;
    gandomFarm=p.gandomFarm;
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


// Defintion of slot , when farm class has shown


void Farm::Show_Farm_Class()
{

    ui->Num_Coin->setText(QString::number(Data::get_iterator()->get_coin()));
}










