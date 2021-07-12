#include "Farm.h"
#include "ui_Farm.h"
#include "Storage.h"
#include "Store.h"
#include "Siloo.h"


<<<<<<< HEAD
Farm::Farm() :
=======
Farm::Farm(QWidget *parent) :
    QMainWindow(parent),
>>>>>>> c3276557bcbf5916ef883f6b08881e841175b3fe
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

void Farm::on_pushButton_clicked()
{
    store.show();
}


void Farm::on_pushButton_2_clicked()
{
    storage.show();
}


void Farm::on_pushButton_3_clicked()
{
    siloo.show();
}

