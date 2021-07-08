#include "Gandomfarm.h"
#include "ui_Gandomfarm.h"

GandomFarm::GandomFarm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GandomFarm)
{
    ui->setupUi(this);
}

GandomFarm::GandomFarm()
{
    area=5;
}
bool GandomFarm::upgradegandomfarm(int &_nail ,int &_hoe,int &_coin,time_t &_date,int &_playerlevel,int &experience ){}
void GandomFarm:: planting(int plantingareawant){}



GandomFarm::~GandomFarm()
{
    delete ui;
}
