#include "yonjefarm.h"
#include "ui_Yonjefarm.h"

YonjeFarm::YonjeFarm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::YonjeFarm)
{
    ui->setupUi(this);
}

YonjeFarm::YonjeFarm()
{

}
bool YonjeFarm::upgradeyonjefarm(int &_nail ,int &_hoe,int &_coin,time_t &_date,int &_playerlevel,int &experience ){}

void YonjeFarm:: planting(int plantingareawant){}






YonjeFarm::~YonjeFarm()
{
    delete ui;
}
