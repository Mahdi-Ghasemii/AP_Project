#include "gandomfarm.h"
#include "ui_gandomfarm.h"
#include <QPalette>
#include "Data.h"
#include <QString>
#include <QMessageBox>



GandomFarm::GandomFarm(QWidget *parent,int _area,int _farm_level,bool _is_underplanting):
    QWidget(parent),
    ui(new Ui::GandomFarm)
{
    area=_area;
    area=_area;
    farm_level=_farm_level;
    isunderplantingvariable = _is_underplanting;

    ui->setupUi(this);
    QPixmap bkgnd(":/new/prefix1/Icons/gandombackground.jpg");
       bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       QPalette palette;
       palette.setBrush(QPalette::Window, bkgnd);
       this->setPalette(palette);
    ui->arealbl->setText(QString::number(area));
    ui->arealbl->setText(QString::number(area));
}

void GandomFarm::operator=(const GandomFarm&temp){
    this->area = temp.area;
    this->plantingdate = temp.plantingdate;
    this->isunderplantingvariable=temp.isunderplantingvariable;
    this->farm_level=temp.farm_level;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

void GandomFarm:: set_area(int _area){area=_area;}

int GandomFarm:: getarea(void){return area;}

void GandomFarm::set_planingdate(time_t _plantingdate){plantingdate=_plantingdate;return ;}

time_t GandomFarm::get_plantingdate(void){return plantingdate;}

void GandomFarm::set_level(int _level){farm_level=_level;return ;}

int GandomFarm::get_level(void){return farm_level;return 0;}

//bool isunderplanting(void){}

//bool GandomFarm::derokardan(void){ return 0;}

//void GandomFarm::planting(int plantingareawant){ return ;}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//bool GandomFarm::upgradegandomfarm(int &_nail ,int &_hoe,int &_coin,time_t &_date,int &_playerlevel,int &experience ){}
//void GandomFarm:: planting(int plantingareawant){}



GandomFarm::~GandomFarm()
{
    delete ui;
}



// //////////////////////////////////////////////////////////////////////////////////////

void GandomFarm::on_plantingpbt_clicked()
{


    if(Data::get_iterator()->get_farm().Get_MyThread().Get_planting_Gandomfarm() !=0 ){
        QMessageBox::warning(this,"تاریخ","زمین زیر کشت است. .",QMessageBox::Ok);
        return ;
    }


        if(Data::get_iterator()->get_farm().get_siloo().Get_gandom().Get_Number()<area){
            QMessageBox::warning(this,"عدم موجودی","گندم به اندازه نیاز ذر انبار وجود ندارد. .",QMessageBox::Ok);
            return ;
        }
        Data::get_iterator()->get_farm().get_siloo().Get_gandom().Set_Number(Data::get_iterator()->get_farm().get_siloo().Get_gandom().Get_Number()-area);
        Data::get_iterator()->get_farm().get_siloo().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_siloo().Get_Occupied_Capacity()-area);
        QMessageBox::warning(this,"تبریک","زمین با موفقیت به زیر کشت رفت. .",QMessageBox::Ok);
        time_t now = time(NULL);
        Data::get_iterator()->get_farm().Get_MyThread().Set_planting_Gandomfarm(now);
        return;
     }


// /////////////////////////////////////////////////////////////////////////////////////////////
void GandomFarm::on_upgradepbt_clicked()
{
    if(Data::get_iterator()->get_farm().Get_MyThread().Get_upgrade_Gandomfarm() !=0 ){
        QMessageBox::warning(this,"تذکر","شما قبلا درخواست ارتقا داده اید !.",QMessageBox::Ok);
        return;
    }
    if(Data::get_iterator()->get_level()>=2){
     if(Data::get_iterator()->get_farm().get_storage().Get_bill().Get_Number()>=(area)){
        if(Data::get_iterator()->get_coin()>=(5*area)){
                Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()-(5*area));

                Data::get_iterator()->get_farm().get_storage().Get_bill().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_bill().Get_Number()-area);
                Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()-area);
              //  Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+(3*area));
               // area*=2;
                // set time
                time_t now = time(NULL);
                Data::get_iterator()->get_farm().Get_MyThread().Set_upgrade_Gandomfarm(now);
                 //QMessageBox::information(this,"تبریک","ارتقای مزرعه گندم انجام شد. .",QMessageBox::Ok);
                //if(Data::get_iterator()->get_experience()>=Data::get_iterator()->get_experience_required_for_levelUp()){
                  //  Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
                   // Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
                   //  QMessageBox::information(this,"تبریک","ارتقای سطح کاربر انجام شد. .",QMessageBox::Ok);
               // }

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

// /////////////////////////////////////////////////////////////////////////////////////////////////



void GandomFarm::on_derokardanpbt_clicked()
{
    if(Data::get_iterator()->get_farm().Get_MyThread().Get_Collect_from_GandomFarm() !=0 ){
        QMessageBox::warning(this,"تاریخ","زمین آماده برداشت نیست. .",QMessageBox::Ok);
        return;
    }
    if(Data::get_iterator()->get_farm().Get_MyThread().Get_planting_Gandomfarm() ==0 ){
        QMessageBox::warning(this,"تاریخ","هنوز محصولی کاشت نشده. .",QMessageBox::Ok);
        return ;
    }

       //QMessageBox::information(this,"","عملیات درو کردن آغاز شد. ",QMessageBox::Ok);
     // if(Data::get_iterator()->get_farm().get_siloo().GetCapasity()-Data::get_iterator()->get_farm().get_siloo().Get_Occupied_Capacity()>=2*area){
   // Data::get_iterator()->get_farm().get_siloo().Get_gandom().Set_Number(Data::get_iterator()->get_farm().get_siloo().Get_gandom().Get_Number()+2*area);
    //time_t now = time(NULL);
  //  Data::get_iterator()->get_farm().Get_MyThread().Set_upgrade_Gandomfarm(now);
  //  QMessageBox::warning(this,"موفقیت","درو شد. .",QMessageBox::Ok);
  // Data::get_iterator()->get_farm().get_siloo().Set_Occupied_Capacity(  Data::get_iterator()->get_farm().get_siloo().Get_Occupied_Capacity()+2*area);
   //if(Data::get_iterator()->get_experience()>=Data::get_iterator()->get_experience_required_for_levelUp()){
     //  Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
     //  Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
     //  QMessageBox::information(this,"تبریک","ارتقای سطح کاربر انجام شد. .",QMessageBox::Ok);
    // }
   //}
  // else {
   //    QMessageBox::warning(this,"ظرفیت ","سیلو ظرفیت ندارد. .",QMessageBox::Ok);
   //}
}

void GandomFarm::on_Back_clicked()
{
    emit Send_Signal_to_Farm();
    this->close();
}
//Slote

void GandomFarm::Get_Signal_From_Farm()
{

    ui->farmlevellbl->setText(QString::number(this->farm_level));
    ui->arealbl->setText(QString::number(this->area));

}
