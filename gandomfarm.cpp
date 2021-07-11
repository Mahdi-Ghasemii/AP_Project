#include "gandomfarm.h"
#include "ui_gandomfarm.h"
#include "dialoggandomplanting.h"

GandomFarm::GandomFarm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GandomFarm)
{
    ui->setupUi(this);

    QPixmap bkgnd("C:/Users/Arman/Desktop/ap/AP_Project/Icons/gandombackground");
       bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       QPalette palette;
       palette.setBrush(QPalette::Window, bkgnd);
       this->setPalette(palette);
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

void GandomFarm::on_pushButton_2_clicked()
{
    DialogGandomPlanting *d =new DialogGandomPlanting(this);
    connect(d,SIGNAL(plantingareawanting(int)),this,SLOT(plantingareawanted(int _area)));
    if(areawanted>area){
        QMessageBox msgBox;
        msgBox.setText("invalid data( alfalfa farm area equal maximum)");
        msgBox.exec();
        areawanted=area;
    }
    d->show();
    //now i should get gandomnum and decreas number of them.
}

void GandomFarm::plantingareawanted(int _area)
{
    areawanted=_area;
}


void GandomFarm::on_pushButton_5_clicked()
{
    this->close();
}

