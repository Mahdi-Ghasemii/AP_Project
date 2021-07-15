#include "yonjefarm.h"
#include "ui_yonjefarm.h"
#include <QPalette>
#include <QPalette>
#include <QMessageBox>
#include "Data.h"

bool YonjeFarm::isbuilt(void){

// if (should check tarikh
 if(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()>=1){
     if(Data::get_iterator()->get_farm().get_storage().Get_bill().Get_Number()>=1){
     if(Data::get_iterator()->get_coin()>=15){
         if(Data::get_iterator()->get_level()>=3){
             Data::get_iterator()->get_farm().get_storage().Get_mikh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()-1);
             Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()-1);
             Data::get_iterator()->get_farm().get_storage().Get_bill().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_bill().Get_Number()-1);
             Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()-1);
             Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()-15);
             Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+6);

            QMessageBox::information(this,"تبریک","زمین یونجه ساخته شد. .",QMessageBox::Ok);
             if(Data::get_iterator()->get_experience()>=Data::get_iterator()->get_experience_required_for_levelUp()){
                 Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
                 Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
                 QMessageBox::information(this,"تبریک","ارتقای سطح کاربر انجام شد. .",QMessageBox::Ok);
             }
         }
         else {
              QMessageBox::information(this,"کمبود منابع","سطح کاربر کافی نمیباشد. .",QMessageBox::Ok);
              return false;

         }
     }
     else {
          QMessageBox::information(this,"کمبود منابع","سکه کافی نمیباشد. .",QMessageBox::Ok);
          return false;

     }
 }

 else{
        QMessageBox::information(this,"کمبود منابع","تعداد بیل کافی نمیباشد. .",QMessageBox::Ok);
        return false;

     }
 }
 else {
     QMessageBox::information(this,"کمبود منابع","تعداد میخ کافی نمیباشد. .",QMessageBox::Ok);
     return false;

 }


is_biulted=true;
return true;
  }

YonjeFarm::YonjeFarm(QWidget *parent,int _area,int _farm_level,bool _is_plantable,bool _is_underplanting) :
    QWidget(parent),
    ui(new Ui::YonjeFarm)
{
    ui->setupUi(this);
    area=_area;
    farm_level=_farm_level;
    is_plantable=_is_plantable;
    isunderplantingvariable=_is_underplanting;

    QPixmap bkgnd(":/new/prefix1/Icons/yonjebackground.jpg");
       bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       QPalette palette;
       palette.setBrush(QPalette::Window, bkgnd);
       this->setPalette(palette);
       ui->yonjearealbl->setText(QString::number(area));

       if(is_biulted==false){
         /*  bool b=isbuilt();
           if(b==false){
               this->close();
           }*/
       }
}


void YonjeFarm::operator =(const YonjeFarm& temp)
{
    this->area = temp.area;
    this->plantingdate = temp.plantingdate;
    this->time_shokhm_zadan = temp.time_shokhm_zadan;
    this->is_plantable = temp.is_plantable;
    this->isunderplantingvariable=temp.isunderplantingvariable;
    this->farm_level=temp.farm_level;

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
        if (Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Get_Number()>area){
        Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Get_Number()-area);
        Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()-area);
        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+(2*area));
         QMessageBox::information(this,"توجه","کاشت یونجه انجام شد. .",QMessageBox::Ok);
        if(Data::get_iterator()->get_experience()>=Data::get_iterator()->get_experience_required_for_levelUp()){
            Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
            Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
            QMessageBox::information(this,"تبریک","ارتقای سطح کاربر انجام شد. .",QMessageBox::Ok);
        }
     }
        else{
            QMessageBox::warning(this,"عدم موجودی","یونجه به اندازه در انبار موجود نمیباشد. .",QMessageBox::Ok);
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
            //decreas coin
                Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()-(5*area));
                //decreas bill
                Data::get_iterator()->get_farm().get_storage().Get_bill().Set_Number( Data::get_iterator()->get_farm().get_storage().Get_bill().Get_Number()-2*area);
                //increas occupied capacity
                Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()-2*area);
                //increas experienc
                Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+(3*area));
                //increas arae
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
    QMessageBox::warning(this,"تبریک","زمین یونحه با موفقیت دروشد. .",QMessageBox::Ok);
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

    Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()-area*5);
     // decreas coin
      Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+area);
      // increas yonjenum
      // Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Get_Number()+2*area);
       //message for derokardan
       QMessageBox::information(this,"تبریک","باموفقیت مزرعه یونجه شخم زده شد. .",QMessageBox::Ok);
       // chec is it possible to levelupuser
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
    emit Send_Signal_to_Farm();
    this->close();
}

//slote
void YonjeFarm::Get_Signal_From_Farm()
{

    ui->farmlevel->setText(QString::number(this->farm_level));
    ui->yonjearealbl->setText(QString::number(this->area));

}

