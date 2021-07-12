#include "gandomfarm.h"
#include "ui_gandomfarm.h"

#include "dialoggandomplanting.h"
#include "Data.h"
#include <QString>
#include <QMessageBox>



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

////////////////////////////////////////////////////////////////////////////////////////////////////////

GandomFarm::GandomFarm(int _area)
{
  area=_area;
}
void GandomFarm:: set_area(int _area){area=_area;}

int GandomFarm:: getarea(void){return area;}

void GandomFarm::set_planingdate(time_t _plantingdate){plantingdate=_plantingdate;}

time_t GandomFarm::get_plantingdate(void){return plantingdate;}

void GandomFarm::set_level(int _level){farm_level=_level;}

int GandomFarm::get_level(void){return farm_level;}

//bool isunderplanting(void){}

bool GandomFarm::derokardan(void){}

void GandomFarm::planting(int plantingareawant){}


void GandomFarm::upgrade(){
    if(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()>=0){
        //if(Data::get_iterator()->get_farm().get_storage().Get_bill().Get_Number()>=(area)){
        if(Data::get_iterator()->get_coin()>=(5*area)){
            if(Data::get_iterator()->get_level()>=2){
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//bool GandomFarm::upgradegandomfarm(int &_nail ,int &_hoe,int &_coin,time_t &_date,int &_playerlevel,int &experience ){}
//void GandomFarm:: planting(int plantingareawant){}



GandomFarm::~GandomFarm()
{
    delete ui;
}

void GandomFarm::on_pushButton_2_clicked()
{
    int i=0;
    for (i=0;i<1;i++){
        if(i//for check that is under planting چک کردن برای زیر کشت نبودن//)
                )
        {

                QMessageBox::warning(this,"تاریخ","زمین زیر کشت است. .",QMessageBox::Ok);
                break;
    }

    DialogGandomPlanting *d =new DialogGandomPlanting(this);
    connect(d,SIGNAL(plantingareawanting(int)),this,SLOT(plantingareawanted(int _area)));
    if(areawanted>area){
        QMessageBox msgBox;
        msgBox.setText("invalid data( alfalfa farm area equal maximum)");
        msgBox.exec();
        areawanted=area;
        d->show();
        Data::get_iterator()->get_farm().get_siloo().Get_gandom().Set_Number(Data::get_iterator()->get_farm().get_siloo().Get_gandom().Get_Number()-area);
     }
    }


}
void GandomFarm::plantingareawanted(int _area)
{
    areawanted=_area;
}


void GandomFarm::on_pushButton_5_clicked()
{
    this->close();
}


void GandomFarm::on_pushButton_4_clicked()
{
    ///

    ///
    /// ////////////////چک کند د روز بعد کاش باشد
   if (//بله)
         1 ){
    Data::get_iterator()->get_farm().get_siloo().Get_gandom().Set_Number(Data::get_iterator()->get_farm().get_siloo().Get_gandom().Get_Number()+2*areawanted);
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
