#include "Farm.h"
#include "ui_Farm.h"
#include "Storage.h"
#include "Store.h"
#include "Siloo.h"
#include "Data.h"
#include "Builting.h"
Farm::Farm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Farm)
{
    ui->setupUi(this);


    // write connects here :

    ui->Num_Coin->setText(QString::number(20));
    ui->_Level->setText(QString::number(1));
    ui->_Experience->setText(QString::number(0));
    ui->_Max_Experience->setText(QString::number(10));

    connect(&siloo, SIGNAL(Send_Signal_to_Farm()),this,SLOT(Show_Farm_Class()));
    connect(&storage, SIGNAL(Send_Signal_to_Farm()),this,SLOT(Show_Farm_Class()));
    connect(&store, SIGNAL(Send_Signal_to_Farm()),this,SLOT(Show_Farm_Class()));
    connect(&gandomFarm, SIGNAL(Send_Signal_to_Farm()),this,SLOT(Show_Farm_Class()));
    connect(&yonjeFarm, SIGNAL(Send_Signal_to_Farm()),this,SLOT(Show_Farm_Class()));

    connect(this, SIGNAL(Send_Signal_to_Siloo()),&siloo,SLOT(Get_Signal_From_Farm()));
    connect(this, SIGNAL(Send_Signal_to_Storage()),&storage,SLOT(Get_Signal_From_Farm()));
    connect(this, SIGNAL(Send_Signal_to_Store()),&store,SLOT(Get_Signal_From_Farm()));
    connect(this, SIGNAL(Send_Signal_to_Gandomfarm()),&gandomFarm,SLOT(Get_Signal_From_Farm()));
    connect(this, SIGNAL(Send_Signal_to_Yonjefarm()),&yonjeFarm,SLOT(Get_Signal_From_Farm()));




    connect(&sheepHome, SIGNAL(Send_Signal_to_Farm()),this,SLOT(Show_Farm_Class()));
    connect(&cowHome, SIGNAL(Send_Signal_to_Farm()),this,SLOT(Show_Farm_Class()));
    connect(&chickenHome, SIGNAL(Send_Signal_to_Farm()),this,SLOT(Show_Farm_Class()));

    connect(this, SIGNAL(Send_Signal_to_SheepHome()),&sheepHome,SLOT(Get_Signal_From_Farm()));
    connect(this, SIGNAL(Send_Signal_to_CowHome()),&cowHome,SLOT(Get_Signal_From_Farm()));
    connect(this, SIGNAL(Send_Signal_to_ChickenHome()),&chickenHome,SLOT(Get_Signal_From_Farm()));

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

YonjeFarm &Farm::get_yonjeFarm()
{
    return yonjeFarm;
}

GandomFarm &Farm::get_gandomFarm()
{
    return gandomFarm;
}

MyThread &Farm::Get_MyThread()
{
    return myThread;
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
    if(Data::get_iterator()->get_level()<3){
        QMessageBox::warning(this,"تذکر","سطح شما باید حداقل 3 باشد");
        return;
    }
    if(yonjeFarm.get_is_build()==false){
        Builting* p=new Builting(this);
        p->show();
        connect(p,SIGNAL(Send_Signal_to_Farm(QString)),this,SLOT(get_signal_from_builting_for_YonjeFarm(QString)));
        return;
    }
    emit Send_Signal_to_Yonjefarm();
    yonjeFarm.show();
}


void Farm::on_GandomFarm_pbn_clicked()
{
    emit Send_Signal_to_Gandomfarm();
    gandomFarm.show();
}


void Farm::on_SheepHome_pbn_clicked()
{
    if(Data::get_iterator()->get_level()<6){
        QMessageBox::warning(this,"تذکر","سطح شما باید حداقل 6 باشد");
        return;
    }
    if(chickenHome.get_is_build()==false){
        Builting* p=new Builting(this);
        p->show();
        connect(p,SIGNAL(Send_Signal_to_Farm(QString)),this,SLOT(get_signal_from_builting_for_sheepHome(QString)));
        return;
    }
    emit Send_Signal_to_SheepHome();
    sheepHome.show();
}


void Farm::on_ChickenHome_pbn_clicked()
{
    if(Data::get_iterator()->get_level()<2){
        QMessageBox::warning(this,"تذکر","سطح شما باید حداقل 2 باشد");
        return;
    }
    if(chickenHome.get_is_build()==false){
        Builting* p=new Builting(this);
        p->show();
        connect(p,SIGNAL(Send_Signal_to_Farm(QString)),this,SLOT(get_signal_from_builting_for_chickenHome(QString)));
        return;
    }
    emit Send_Signal_to_ChickenHome();
    chickenHome.show();
}


void Farm::on_CowHome_pbn_clicked()
{
    if(Data::get_iterator()->get_level()<4){
        QMessageBox::warning(this,"تذکر","سطح شما باید حداقل 4 باشد");
        return;
    }
    if(chickenHome.get_is_build()==false){
        Builting* p=new Builting(this);
        p->show();
        connect(p,SIGNAL(Send_Signal_to_Farm(QString)),this,SLOT(get_signal_from_builting_for_cowHome(QString)));
        return;
    }
    emit Send_Signal_to_CowHome();
    cowHome.show();
}


// Defintion of slot , when farm class has shown


void Farm::Show_Farm_Class()
{

    ui->Num_Coin->setText(QString::number(Data::get_iterator()->get_coin()));
    ui->_Experience->setText(QString::number(Data::get_iterator()->get_experience()));
    ui->_Max_Experience->setText(QString::number(Data::get_iterator()->get_experience_required_for_levelUp()));
    ui->_Level->setText(QString::number(Data::get_iterator()->get_level()));

    int a = Data::get_iterator()->get_experience()*100;
    a /= Data::get_iterator()->get_experience_required_for_levelUp();
    ui->progressBar->setValue(a);
}

void Farm::on_pushButton_3_clicked()
{

    emit Send_Signal_to_Store();
    store.show();
}

void Farm::get_signal_from_builting_for_chickenHome(QString str){
    if(str=="yes")
        chickenHome.build();
    else
        return;
}

void Farm::get_signal_from_builting_for_cowHome(QString str){
    if(str=="yes")
        cowHome.build();
    else
        return;
}

void Farm::get_signal_from_builting_for_sheepHome(QString str){
    if(str=="yes")
        sheepHome.build();
    else
        return;
}
//i am hereeeeee?????????
void Farm::get_signal_from_builting_for_YonjeFarm(QString str){
    if(str=="yes")
        yonjeFarm.build();
    else
        return;
}
