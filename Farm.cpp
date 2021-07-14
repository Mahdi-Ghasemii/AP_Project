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
    connect(&gandomFarm, SIGNAL(Send_Signal_to_Farm()),this,SLOT(Show_Farm_Class()));
    connect(&yonjeFarm, SIGNAL(Send_Signal_to_Farm()),this,SLOT(Show_Farm_Class()));

    connect(this, SIGNAL(Send_Signal_to_Siloo()),&siloo,SLOT(Get_Signal_From_Farm()));
    connect(this, SIGNAL(Send_Signal_to_Storage()),&storage,SLOT(Get_Signal_From_Farm()));
    connect(this, SIGNAL(Send_Signal_to_Store()),&store,SLOT(Get_Signal_From_Farm()));
    connect(this, SIGNAL(Send_Signal_to_Gandomfarm),&gandomFarm,SLOT(Get_Signal_From_Farm()));
    connect(this, SIGNAL(Send_Signal_to_Yonjefarm),&yonjeFarm,SLOT(Get_Signal_From_Farm()));




    connect(&sheepHome, SIGNAL(Send_Signal_to_Farm()),this,SLOT(Show_Farm_Class()));
    connect(&cowHome, SIGNAL(Send_Signal_to_Farm()),this,SLOT(Show_Farm_Class()));
    connect(&chickenHome, SIGNAL(Send_Signal_to_Farm()),this,SLOT(Show_Farm_Class()));

    connect(this, SIGNAL(Send_Signal_to_SheepHome()),&store,SLOT(Get_Signal_From_Farm()));
    connect(this, SIGNAL(Send_Signal_to_CowHome()),&store,SLOT(Get_Signal_From_Farm()));
    connect(this, SIGNAL(Send_Signal_to_ChickenHome()),&store,SLOT(Get_Signal_From_Farm()));

}


Farm::~Farm(){
    //delete ui;
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

    emit Send_Signal_to_Storage();
   storage.show();
}


void Farm::on_Siloo_pbn_clicked()
{
    emit Send_Signal_to_Siloo();
    siloo.show();
}


void Farm::on_YonjehFarm_pbn_clicked()
{

    emit Send_Signal_to_Yonjefarm();
    yonjeFarm.show();
}


void Farm::on_GandomFarm_pbn_clicked()
{

    emit Send_Signal_to_Gandomfarm();;
    gandomFarm.show();
}


void Farm::on_SheepHome_pbn_clicked()
{

    emit Send_Signal_to_SheepHome();
    sheepHome.show();
}


void Farm::on_ChickenHome_pbn_clicked()
{

    emit Send_Signal_to_ChickenHome();
    chickenHome.show();
}


void Farm::on_CowHome_pbn_clicked()
{

    emit Send_Signal_to_CowHome();
    cowHome.show();
}


// Defintion of slot , when farm class has shown


void Farm::Show_Farm_Class()
{

    ui->Num_Coin->setText(QString::number(Data::get_iterator()->get_coin()));
}





void Farm::on_pushButton_3_clicked()
{

   emit Send_Signal_to_Store();

    store.show();
}

