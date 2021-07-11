#include "yonjefarm.h"
#include "ui_yonjefarm.h"
<<<<<<< HEAD
#include <QPalette>
#include "dialoggandomplanting.h"
#include <QMessageBox>
#include "Data.h"
=======

>>>>>>> c3276557bcbf5916ef883f6b08881e841175b3fe
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////
YonjeFarm::YonjeFarm(int _area)
{
    area=_area;
}
void YonjeFarm:: set_area(int _area){area=_area;}

int YonjeFarm:: getarea(void){return area;}

void YonjeFarm::set_planingdate(time_t _plantingdate){plantingdate=_plantingdate;}

time_t YonjeFarm::get_plantingdate(void){return plantingdate;}

void YonjeFarm::set_level(int _level){farm_level=_level;}

int YonjeFarm::get_level(void){return farm_level;}

//bool isunderplanting(void){}

bool YonjeFarm::derokardan(void){}

void YonjeFarm::planting(int plantingareawant){}

void YonjeFarm::upgrade(){
    if(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()>=0){
        //if(Data::get_iterator()->get_farm().get_storage().Get_bill().Get_Number()>=(area*2)){
        if(Data::get_iterator()->get_coin()>=(5*area)){
            if(Data::get_iterator()->get_level()>=4){
                Data::get_iterator()->get_farm().get_storage().Get_mikh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()-0);
                Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()-(5*area));
                Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+(3*area));
                area*=2;
                //QMessageBox
                if(Data::get_iterator()->get_experience()>=Data::get_iterator()->get_experience_required_for_levelUp()){
                    Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
                    Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
                    //QMessageBox
                }
            }
            else {
                //QMessageBox
            }
        }
        else {
            //QMessageBox
        }
    }
    else {
        //QMessageBox
    }

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool YonjeFarm::upgradeyonjefarm(int &_nail ,int &_hoe,int &_coin,time_t &_date,int &_playerlevel,int &experience ){}

//void YonjeFarm:: planting(int plantingareawant){}






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

}


void YonjeFarm::on_derokardan_clicked()
{
    ///

    ///
    /// ////////////////چک کند د روز بعد کاش باشد
   if (//بله)
         1 ){

    Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Get_Number()+2*areawanted);
    QMessageBox::warning(this,"موفقیت","درو شد. .",QMessageBox::Ok);
    if(Data::get_iterator()->get_experience()>=Data::get_iterator()->get_experience_required_for_levelUp()){
       Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
       Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
       //QMessageBox
     }
   }
   else {
       QMessageBox::warning(this,"تاریخ","زمین آماده برداشت نیست. .",QMessageBox::Ok);
   }
}

