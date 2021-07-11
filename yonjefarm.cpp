#include "yonjefarm.h"
#include "ui_yonjefarm.h"
#include <QPalette>
#include "dialoggandomplanting.h"
#include <QMessageBox>
#include <Data.h>
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


void YonjeFarm::on_upgradebutton_clicked()
{
    if(!(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number() >= this->building_Level*2)){

                QMessageBox::warning(this,"کمبود منابع","تعداد میخ ها برای ارتقا سیلو کافی نمی باشد .",QMessageBox::Ok);
            }
            else if(!( Data::get_iterator()->get_coin() >= pow((this->building_Level*2),2))*100){
                QMessageBox::warning(this,"کمبود منابع","تعداد سکه ها برای ارتقا سیلو کافی نمی باشد",QMessageBox::Ok);
            }

            else {
                this->building_Level *= 2;
                QMessageBox::information(this,"","سیلو با موفقیت ارتقا پیدا کرد .",QMessageBox::Ok);

                Data::get_iterator()->set_experience(Data::get_iterator()->get_experience() + (this->building_Level * 2));
            }

}

