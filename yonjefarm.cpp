#include "yonjefarm.h"
#include "ui_yonjefarm.h"
#include <QPalette>
#include "dialoggandomplanting.h"
#include <QMessageBox>

YonjeFarm::YonjeFarm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::YonjeFarm)
{
    ui->setupUi(this);

    QPixmap bkgnd("C:/Users/Arman/Desktop/ap/AP_Project/Icons/yonjebackground");
       bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       QPalette palette;
       palette.setBrush(QPalette::Window, bkgnd);
       this->setPalette(palette);
       ui->yonjearealbl->setText(QString::number(area));
}

YonjeFarm::YonjeFarm(int _area)
{
    area=_area;
}
bool YonjeFarm::upgradeyonjefarm(int &_nail ,int &_hoe,int &_coin,time_t &_date,int &_playerlevel,int &experience ){}

void YonjeFarm:: planting(int plantingareawant){}






YonjeFarm::~YonjeFarm()
{
    delete ui;
}

void YonjeFarm::on_planting_clicked()
{
    DialogGandomPlanting *d=new DialogGandomPlanting(this) ;
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

void YonjeFarm::plantingareawanted(int _area)
{
    areawanted=_area;

}


void YonjeFarm::on_pushButton_3_clicked()
{
    this->close();
}

