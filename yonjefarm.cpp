#include "yonjefarm.h"
#include "ui_yonjefarm.h"
#include <QPalette>

#include <QMessageBox>
#include "Data.h"

YonjeFarm::YonjeFarm(QWidget *parent,int _area) :
    QWidget(parent),
    ui(new Ui::YonjeFarm)
{
    ui->setupUi(this);
    area=_area;
    ui->yonjearealbl->setText(QString::number(area));
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void YonjeFarm:: set_area(int _area){area=_area;return;}

int YonjeFarm:: getarea(void){return area;}

void YonjeFarm::set_planingdate(time_t _plantingdate){plantingdate=_plantingdate;return ;}

time_t YonjeFarm::get_plantingdate(void){return plantingdate;}

void YonjeFarm::set_level(int _level){farm_level=_level;return ;}

int YonjeFarm::get_level(void){return farm_level;}

//bool isunderplanting(void){}

//bool YonjeFarm::derokardan(void){}

//void YonjeFarm::planting(int plantingareawant){}
// /////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//bool YonjeFarm::upgradeyonjefarm(int &_nail ,int &_hoe,int &_coin,time_t &_date,int &_playerlevel,int &experience ){}

//void YonjeFarm:: planting(int plantingareawant){}






YonjeFarm::~YonjeFarm()
{
    delete ui;
}
/////////////////////////////////////////////////////////////////////
void YonjeFarm::on_planting_clicked()
{

   // //////////چک کند زمین شخم زده شده باشد و یک روز گذشته باشد///////////////////////////////////
    int i=0;
    for (i=0;i<1;i++){
        if(i//for check that is under planting چک کردن برای زیر کشت نبودن//)
                )
        {

                QMessageBox::warning(this,"تاریخ","زمین زیر کشت است. .",QMessageBox::Ok);
                break;
    }
        if (1//زمان چک شود بیش تر از یک روز از شخم زدن گذشته باشد
                )
        {
        QMessageBox::warning(this,"کمبود ضروریات","زمین شخم زده نشده است . .",QMessageBox::Ok);
        break;
       }
        Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Get_Number()-area);
        Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()-area);
        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+(2*area));
         QMessageBox::information(this,"توجه","کشت انجام شد. .",QMessageBox::Ok);
        if(Data::get_iterator()->get_experience()>=Data::get_iterator()->get_experience_required_for_levelUp()){
            Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
            Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
             QMessageBox::information(this,"تبریک","ارتقای سطح کاربر انجام شد. .",QMessageBox::Ok);
        }
     }
}
// /////////////////////////////////////////////////////////////////////


// ////////////////////////////////////////////////////////
void YonjeFarm::on_upgradebutton_clicked()
{
    // چک کردن زمان دورئز الزامی است
    if(Data::get_iterator()->get_level()>=4){
     if(Data::get_iterator()->get_farm().get_storage().Get_bill().Get_Number()>=(2*area)){
        if(Data::get_iterator()->get_coin()>=(5*area)){
                Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()-(5*area));
                Data::get_iterator()->get_farm().get_storage().Get_bill().Set_Number( Data::get_iterator()->get_farm().get_storage().Get_bill().Get_Number()-2*area);

                Data::get_iterator()->get_farm().get_storage().Get_bill().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_bill().Get_Number()-2*area);
                Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()-2*area);
                Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+(3*area));
                area*=2;
                 QMessageBox::information(this,"تبریک","ارتقای مزرعه یونجه انجام شد. .",QMessageBox::Ok);
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
        QMessageBox::warning(this,"کمبود منابع","بیل به اندازه کافی موجود میست. .",QMessageBox::Ok);
    }

   }
    else {
       QMessageBox::warning(this,"پایین بودن سطح","به سطح مرد نیاز نرسیده اید. .",QMessageBox::Ok);
    }
}
// /////////////////////////////////////////////////////////////////

void YonjeFarm::on_derokardan_clicked()
{
    ///

    ///
    /// ////////////////چک کند د روز بعد کاش باشد
   if (//بله)
         1 ){
      if(Data::get_iterator()->get_farm().get_storage().GetCapasity()-Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()>=2*area){
    Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Set_Number(Data::get_iterator()->get_farm().get_siloo().Get_gandom().Get_Number()+2*area);
    Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()+2*area);
    QMessageBox::warning(this,"موفقیت","درو شد. .",QMessageBox::Ok);
    Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+(2*area));
   if(Data::get_iterator()->get_experience()>=Data::get_iterator()->get_experience_required_for_levelUp()){
       Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
       Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
       QMessageBox::information(this,"تبریک","ارتقای سطح کاربر انجام شد. .",QMessageBox::Ok);
     }
   }
   else {
       QMessageBox::warning(this,"ظرفیت ","انبار ظرفیت ندارد. .",QMessageBox::Ok);
   }
   }
      else {
       QMessageBox::warning(this,"تاریخ","زمین آماده برداشت نیست. .",QMessageBox::Ok);

      }
}

// //////////////////////////////////////////////////////////////////////////////////////////////////////////////
void YonjeFarm::on_shokhmzadan_clicked()
{
if(Data::get_iterator()->get_coin()>=(area*5)){
      Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+area);
      if(Data::get_iterator()->get_experience()>=Data::get_iterator()->get_experience_required_for_levelUp()){
          Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
          Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
          QMessageBox::information(this,"تبریک","ارتقای سطح کاربر انجام شد. .",QMessageBox::Ok);
    }
      // ////////////////////////////////////////حالا باید زمان شخم زدن ذخیری شود//////////////////////
}
else {
    QMessageBox::warning(this,"مالی","سکه کافی ندارید. .",QMessageBox::Ok);
}

}

void YonjeFarm::on_Back_clicked()
{
    this->close();
}

