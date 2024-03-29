#include "Farm.h"
#include "ui_Farm.h"
#include "Storage.h"
#include "Store.h"
#include "Siloo.h"
#include "Data.h"
#include "Builting.h"
#include "Profile.h"
#include <QMessageBox>
#include <QKeySequence>

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
    ui->ExitAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_E));
    ui->ProfileAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_P));

    setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);

    this->setFixedSize(1000,666);

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

    connect(&ranking, SIGNAL(Send_Signal_to_Farm()), this, SLOT(Show_Farm_Class()));
    connect(this, SIGNAL(Send_Signal_to_Ranking()), &ranking, SLOT(Get_Signal_From_Farm()));

    connect(&sheepHome, SIGNAL(Send_Signal_to_Farm()),this,SLOT(Show_Farm_Class()));
    connect(&cowHome, SIGNAL(Send_Signal_to_Farm()),this,SLOT(Show_Farm_Class()));
    connect(&chickenHome, SIGNAL(Send_Signal_to_Farm()),this,SLOT(Show_Farm_Class()));

    connect(this, SIGNAL(Send_Signal_to_SheepHome()),&sheepHome,SLOT(Get_Signal_From_Farm()));
    connect(this, SIGNAL(Send_Signal_to_CowHome()),&cowHome,SLOT(Get_Signal_From_Farm()));
    connect(this, SIGNAL(Send_Signal_to_ChickenHome()),&chickenHome,SLOT(Get_Signal_From_Farm()));

    connect(ui->ExitAction , SIGNAL(triggered()) , this ,SLOT(On_ExitAction_triggred()));
    connect(ui->ProfileAction , SIGNAL(triggered()) , this ,SLOT(On_ProfileAction_triggred()));


    // write connects here :
    connect(&myThread,SIGNAL(Send_Signal_to_Farm_for_time_login()),this,SLOT(Set_UI_Attributes1_for_set_time_login()));
    connect(&myThread,SIGNAL(Send_Signal_to_Farm_for_Upgrade_Storage()),this,SLOT(Set_UI_Attributes_for_upgrade_storage()));
    connect(&myThread,SIGNAL(Send_Signal_to_Farm_for_Upgrade_Siloo()),this,SLOT(Set_UI_Attributes1_for_upgrade_siloo()));

    connect(&myThread,SIGNAL(Send_Signal_to_Farm_for_Upgrade_ChickenHome()),this,SLOT(Set_UI_Attributes1_for_upgrade_chickenHome()));
    connect(&myThread,SIGNAL(Send_Signal_to_Farm_for_Upgrade_CowHome()),this,SLOT(Set_UI_Attributes1_for_upgrade_cowHome()));
    connect(&myThread,SIGNAL(Send_Signal_to_Farm_for_Upgrade_SheepHome()),this,SLOT(Set_UI_Attributes1_for_upgrade_sheepHome()));
    connect(&myThread,SIGNAL(Send_Signal_to_Farm_for_Build_ChickenHome()),this,SLOT(Set_UI_Attributes1_for_build_chickenHome()));
    connect(&myThread,SIGNAL(Send_Signal_to_Farm_for_Build_CowHome()),this,SLOT(Set_UI_Attributes1_for_build_cowHome()));
    connect(&myThread,SIGNAL(Send_Signal_to_Farm_for_Build_SheepHome()),this,SLOT(Set_UI_Attributes1_for_build_sheepHome()));

    connect(&myThread,SIGNAL(Send_Signal_to_Farm_for_Build_yonjeFarm()),this,SLOT(Set_UI_Attributes1_for_build_yonjeFarm()));
    connect(&myThread,SIGNAL(Send_Signal_to_Farm_for_Upgrade_yonjeFarm()),this,SLOT(Set_UI_Attributes1_for_upgrade_yonjeFarm()));
    connect(&myThread,SIGNAL(Send_Signal_to_Farm_for_Upgrade_gandomFarm()),this,SLOT(Set_UI_Attributes1_for_upgrade_gandomFarm()));
    connect(&myThread,SIGNAL(Send_Signal_to_Farm_for_plow_yonjeFarm()),this,SLOT(Set_UI_Attributes1_for_plow_yonjeFarm()));

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
    myThread=p.myThread;
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
    if(yonjeFarm.get_is_build()==false&&myThread.Get_Build_YonjehFarm()!=0){
        QMessageBox::warning(this,"تذکر","زمین یونجه در حال ساخته شدن است");
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
        QMessageBox::warning(this,"تذکر","برای دسترسی به این مکان سطح شما باید حداقل 6 باشد");
        return;
    }
    if(sheepHome.get_is_build()==false&&myThread.Get_build_SheepHome()!=0){
        QMessageBox::warning(this,"تذکر","آغل در حال ساخته شدن است");
        return;
    }
    if(sheepHome.get_is_build()==false){
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
        QMessageBox::warning(this,"تذکر","برای دسترسی به این مکان سطح شما باید حداقل 2 باشد");
        return;
    }
    if(chickenHome.get_is_build()==false&&myThread.Get_build_ChickenHome()!=0){
        QMessageBox::warning(this,"تذکر","مرغداری در حال ساخته شدن است");
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
        QMessageBox::warning(this,"تذکر","برای دسترسی به این مکان سطح شما باید حداقل 4 باشد");
        return;
    }
    if(cowHome.get_is_build()==false&&myThread.Get_build_CowHome()!=0){
        QMessageBox::warning(this,"تذکر","'گاوداری در حال ساخته شدن است");
        return;
    }
    if(cowHome.get_is_build()==false){
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

//    time_t now = time(NULL);
//    ui->DaysLeft->setText(QString::number(((now - Data::get_iterator()->get_farm().Get_MyThread().Get_time_login())/(3600*24))));
    int a = Data::get_iterator()->get_experience()*100;
    a /= Data::get_iterator()->get_experience_required_for_levelUp();

    ui->progressBar->setValue(a);
}

void Farm::on_pushButton_3_clicked()
{

    if(Data::get_iterator()->get_level() < 2){

         QMessageBox::warning(this," !تذكر","براي دسترسي به فروشگاه ، سطح شما حداقل بايد 2 باشد!.",QMessageBox::Ok);
         return;
    }

    emit Send_Signal_to_Store();
    store.show();
}


void Farm::on_pushButton_clicked()
{
    emit Send_Signal_to_Ranking();
    ranking.show();
}

void Farm::On_ExitAction_triggred()
{
    Data::write_on_file();
    this->close();
    QMessageBox::information(nullptr, "اتمام بازی", "به امید دیدار!");
}

void Farm::On_ProfileAction_triggred()
{
    Profile* p = new Profile;
    p->show();
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


void Farm::Global_Func_to_Set_ui_Attributes()
{
    ui->_Experience->setText(QString::number(Data::get_iterator()->get_experience()));
    if(Data::get_iterator()->get_experience() >= Data::get_iterator()->get_experience_required_for_levelUp()){

        while(Data::get_iterator()->get_experience() >= Data::get_iterator()->get_experience_required_for_levelUp()){
        Data::get_iterator()->set_experience_required_for_levelUp(Data::get_iterator()->get_experience_required_for_levelUp()*2+10);
        Data::get_iterator()->set_level(Data::get_iterator()->get_level()+1);

        }
        ui->_Level->setText(QString::number(Data::get_iterator()->get_level()));
        ui->_Max_Experience->setText(QString::number(Data::get_iterator()->get_experience_required_for_levelUp()));


        if(Data::get_iterator()->get_level()==2)
            QMessageBox::information(this,"تبریک","سطح شما افزایش پیدا کرد, در این سطح به شما اجازه دسترسی به مرغداری, مرغ و تخم‌مرغ داده شده است . . .:)",QMessageBox::Ok);

        else if(Data::get_iterator()->get_level()==3)
            QMessageBox::information(this,"تبریک","سطح شما افزایش پیدا کرد, در این سطح به شما اجازه دسترسی به زمین یونجه و یونجه داده شده است . . .:)",QMessageBox::Ok);

        else if(Data::get_iterator()->get_level()==4)
            QMessageBox::information(this,"تبریک","سطح شما افزایش پیدا کرد, در این سطح به شما اجازه دسترسی به گاوداری, گاو و شیر داده شده است . . .:)",QMessageBox::Ok);

        else if(Data::get_iterator()->get_level()==6)
            QMessageBox::information(this,"تبریک","سطح شما افزایش پیدا کرد, در این سطح به شما اجازه دسترسی به آغل, گوسفند و پشم گوسفند داده شده است . . .:)",QMessageBox::Ok);

        else
            QMessageBox::information(this,"تبریک","سطح شما افزایش پیدا کرد . . .:)",QMessageBox::Ok);
    }
    ui->Num_Coin->setText(QString::number(Data::get_iterator()->get_coin()));

//    time_t now = time(NULL);
//    ui->DaysLeft->setText(QString::number(((now - Data::get_iterator()->get_farm().Get_MyThread().Get_time_login())/(3600*24))));
    int a = Data::get_iterator()->get_experience()*100;
    a /= Data::get_iterator()->get_experience_required_for_levelUp();
    ui->progressBar->setValue(a);

}


// write slots here

void Farm::Set_UI_Attributes1_for_set_time_login()
{
   Global_Func_to_Set_ui_Attributes();
}

void Farm::Set_UI_Attributes_for_upgrade_storage()
{
    Global_Func_to_Set_ui_Attributes();

    QMessageBox::information(this,"","انبار با موفقیت ارتقا پیدا کرد .:)",QMessageBox::Ok);
}

void Farm::Set_UI_Attributes1_for_upgrade_siloo()
{
    Global_Func_to_Set_ui_Attributes();

    QMessageBox::information(this,"","سیلو با موفقیت ارتقا پیدا کرد .:)",QMessageBox::Ok);
}

void Farm::Set_UI_Attributes1_for_build_chickenHome()
{
    Global_Func_to_Set_ui_Attributes();

    QMessageBox::information(this,"تبریک","مرغداری با موفقیت ساخته شد",QMessageBox::Ok);
}

void Farm::Set_UI_Attributes1_for_build_cowHome()
{
    Global_Func_to_Set_ui_Attributes();

    QMessageBox::information(this,"تبریک","گاوداری با موفقیت ساخته شد",QMessageBox::Ok);
}

void Farm::Set_UI_Attributes1_for_build_sheepHome()
{
    Global_Func_to_Set_ui_Attributes();

    QMessageBox::information(this,"تبریک","آغل با موفقیت ساخته شد",QMessageBox::Ok);
}

void Farm::Set_UI_Attributes1_for_upgrade_chickenHome()
{
    Global_Func_to_Set_ui_Attributes();

    QMessageBox::information(this,"تبریک","مرغداری با موفقیت ارتقا پیدا کرد",QMessageBox::Ok);
}

void Farm::Set_UI_Attributes1_for_upgrade_cowHome()
{
    Global_Func_to_Set_ui_Attributes();

    QMessageBox::information(this,"تبریک","گاوداری با موفقیت ارتقا پیدا کرد",QMessageBox::Ok);
}

void Farm::Set_UI_Attributes1_for_upgrade_sheepHome()
{
    Global_Func_to_Set_ui_Attributes();

    QMessageBox::information(this,"تبریک","آغل با موفقیت ارتقا پیدا کرد",QMessageBox::Ok);
}

void Farm::Set_UI_Attributes1_for_upgrade_gandomFarm()
{
    Global_Func_to_Set_ui_Attributes();

    QMessageBox::information(this,"تبریک","مزرعه گندم با موفقیت ارتقا پیدا کرد",QMessageBox::Ok);
}

void Farm::Set_UI_Attributes1_for_upgrade_yonjeFarm()
{
    Global_Func_to_Set_ui_Attributes();

    QMessageBox::information(this,"تبریک","مزرعه یونجه با موفقیت ارتقا پیدا کرد",QMessageBox::Ok);
}

void Farm::Set_UI_Attributes1_for_build_yonjeFarm()
{
    Global_Func_to_Set_ui_Attributes();

    QMessageBox::information(this,"تبریک","مزرعه یونجه با موفقیت ساخته شد",QMessageBox::Ok);
}
void Farm::Set_UI_Attributes1_for_plow_yonjeFarm()
{
    Global_Func_to_Set_ui_Attributes();

    QMessageBox::information(this,"تبریک","مزرعه یونجه با موفقیت شخم زده شد",QMessageBox::Ok);
}

