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

bool GandomFarm::derokardan(void){ return 0;}

void GandomFarm::planting(int plantingareawant){ return ;}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//bool GandomFarm::upgradegandomfarm(int &_nail ,int &_hoe,int &_coin,time_t &_date,int &_playerlevel,int &experience ){}
//void GandomFarm:: planting(int plantingareawant){}



GandomFarm::~GandomFarm()
{
    delete ui;
}

void GandomFarm::plantingareawanted(int _area)
{
    areawanted=_area;
}

// //////////////////////////////////////////////////////////////////////////////////////

void GandomFarm::on_plantingpbt_clicked()
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

// /////////////////////////////////////////////////////////////////////////////////////////////
void GandomFarm::on_upgradepbt_clicked()
{
    // چک کردن زمان دورئز الزامی است
    if(Data::get_iterator()->get_level()>=2){
     if(Data::get_iterator()->get_farm().get_storage().Get_bill().Get_Number()>=(area)){
        if(Data::get_iterator()->get_coin()>=(5*area)){
                Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()-(5*area));
                Data::get_iterator()->get_farm().get_storage().Get_bill().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_bill().Get_Number()-area);
                Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+(3*area));
                area*=2;
                 QMessageBox::information(this,"تبریک","ارتقای مزرعه گندم انجام شد. .",QMessageBox::Ok);
                if(Data::get_iterator()->get_experience()>=Data::get_iterator()->get_experience_required_for_levelUp()){
                    Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
                    Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
                     QMessageBox::information(this,"تبریک","ارتقای سطح کاربر انجام شد. .",QMessageBox::Ok);
                }

        }
        else {
             QMessageBox::warning(this,"کمبود منابع","سکه به اندازه کافی موجود میست. .",QMessageBox::Ok);
        }
    }
    else {
        QMessageBox::warning(this,"کمبود منابع","میخ به اندازه کافی موجود میست. .",QMessageBox::Ok);
    }

   }
    else {
       QMessageBox::warning(this,"پایین بودن سطح","به سطح مرد نیاز نرسیده اید. .",QMessageBox::Ok);
    }
}

// /////////////////////////////////////////////////////////////////////////////////////////////////



void GandomFarm::on_derokardanpbt_clicked()
{
    ///

    ///
    /// ////////////////چک کند د روز بعد کاش باشد
   if (//بله)
         1 ){
      if(Data::get_iterator()->get_farm().get_siloo().Get_gandom().Get_Number()>=2*areawanted){
    Data::get_iterator()->get_farm().get_siloo().Get_gandom().Set_Number(Data::get_iterator()->get_farm().get_siloo().Get_gandom().Get_Number()+2*areawanted);
    QMessageBox::warning(this,"موفقیت","درو شد. .",QMessageBox::Ok);
   if(Data::get_iterator()->get_experience()>=Data::get_iterator()->get_experience_required_for_levelUp()){
       Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
       Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
       QMessageBox::information(this,"تبریک","ارتقای سطح کاربر انجام شد. .",QMessageBox::Ok);
     }
   }
   else {
       QMessageBox::warning(this,"ظرفیت ","سیلو ظرفیت ندارد. .",QMessageBox::Ok);
   }
   }
      else {
       QMessageBox::warning(this,"تاریخ","زمین آماده برداشت نیست. .",QMessageBox::Ok);

      }
}


void GandomFarm::on_Back_clicked()
{
      this->close();
}
