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
    setFixedSize(402, 312);
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


/////////////////////////////////////////////////////////////////////////////////////////////////////////




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
            QMessageBox::warning(this,"عدم موجودی","گندم به اندازه نیاز در سیلو وجود ندارد. .",QMessageBox::Ok);
            return ;
        }
        Data::get_iterator()->get_farm().get_siloo().Get_gandom().Set_Number(Data::get_iterator()->get_farm().get_siloo().Get_gandom().Get_Number()-area);
        Data::get_iterator()->get_farm().get_siloo().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_siloo().Get_Occupied_Capacity()-area);
        QMessageBox::warning(this,"تبریک","زمین با موفقیت به زیر کشت رفت. .",QMessageBox::Ok);
        time_t now = time(NULL);
        Data::get_iterator()->get_farm().Get_MyThread().Set_planting_Gandomfarm(now);

        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+area);
        if(Data::get_iterator()->get_experience()>=Data::get_iterator()->get_experience_required_for_levelUp()){
          Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
          Data::get_iterator()->set_level(Data::get_iterator()->get_level()+1);
          Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
           if(Data::get_iterator()->get_level()==2)
               QMessageBox::information(this,"تبریک","سطح شما افزایش پیدا کرد, در این سطح به شما اجازه دسترسی به مرغداری, مرغ و تخم‌مرغ داده شده است . . .:)",QMessageBox::Ok);

           else if(Data::get_iterator()->get_level()==3)
               QMessageBox::information(this,"تبریک","سطح شما افزایش پیدا کرد, در این سطح به شما اجازه دسترسی به زمین یونجه و یونجه داده شده است . . .:)",QMessageBox::Ok);

           else if(Data::get_iterator()->get_level()==4)
               QMessageBox::information(this,"تبریک","سطح شما افزایش پیدا کرد, در این سطح به شما اجازه دسترسی به گاوداری, گاو و شیر داده شده است . . .:)",QMessageBox::Ok);

           else if(Data::get_iterator()->get_level()==6)
               QMessageBox::information(this,"تبریک","سطح شما افزایش پیدا کرد, در این سطح به شما اجازه دسترسی به آغل, گوسفند و پشم گوسفند داده شده است . . .:)",QMessageBox::Ok);

           else
               QMessageBox::information(this,"تبریک","سطح شما افزایش پیدا کرد . . .:)",QMessageBox::Ok);
       }
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
                time_t now = time(NULL);
                Data::get_iterator()->get_farm().Get_MyThread().Set_upgrade_Gandomfarm(now);
                qDebug()<<now<<"\n"<< Data::get_iterator()->get_farm().Get_MyThread().Get_upgrade_Gandomfarm();


        }
        else {
             QMessageBox::warning(this,"کمبود منابع","سکه به اندازه کافی موجود نیست. .",QMessageBox::Ok);
        }
    }
    else {
        QMessageBox::warning(this,"کمبود منابع","بیل به اندازه کافی موجود نیست. .",QMessageBox::Ok);
    }

   }
    else {
       QMessageBox::warning(this,"پایین بودن سطح","به سطح مورد نیاز نرسیده اید. .",QMessageBox::Ok);
    }
}

// /////////////////////////////////////////////////////////////////////////////////////////////////



void GandomFarm::on_derokardanpbt_clicked()
{
    time_t now = time(NULL);

    if(Data::get_iterator()->get_farm().Get_MyThread().Get_planting_Gandomfarm() ==0 ){
        QMessageBox::warning(this,"","هنوز محصولی کاشت نشده. .",QMessageBox::Ok);
        return ;
    }
    if(Data::get_iterator()->get_farm().Get_MyThread().Get_planting_Gandomfarm()!=0 && now - Data::get_iterator()->get_farm().Get_MyThread().Get_planting_Gandomfarm()>= 2*3600*24){
          if(Data::get_iterator()->get_farm().get_siloo().GetCapasity()-Data::get_iterator()->get_farm().get_siloo().Get_Occupied_Capacity()>=2*area){
          Data::get_iterator()->get_farm().get_siloo().Get_gandom().Set_Number(Data::get_iterator()->get_farm().get_siloo().Get_gandom().Get_Number()+2*area);
          QMessageBox::information(this," با موفقیت","درو شد .",QMessageBox::Ok);
          Data::get_iterator()->get_farm().get_siloo().Set_Occupied_Capacity(  Data::get_iterator()->get_farm().get_siloo().Get_Occupied_Capacity()+2*area);

          Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+1*area);
          if(Data::get_iterator()->get_experience()>=Data::get_iterator()->get_experience_required_for_levelUp()){
            Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
            Data::get_iterator()->set_level(Data::get_iterator()->get_level()+1);
            Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
             if(Data::get_iterator()->get_level()==2)
                 QMessageBox::information(this,"تبریک","سطح شما افزایش پیدا کرد, در این سطح به شما اجازه دسترسی به مرغداری, مرغ و تخم‌مرغ داده شده است . . .:)",QMessageBox::Ok);

             else if(Data::get_iterator()->get_level()==3)
                 QMessageBox::information(this,"تبریک","سطح شما افزایش پیدا کرد, در این سطح به شما اجازه دسترسی به زمین یونجه و یونجه داده شده است . . .:)",QMessageBox::Ok);

             else if(Data::get_iterator()->get_level()==4)
                 QMessageBox::information(this,"تبریک","سطح شما افزایش پیدا کرد, در این سطح به شما اجازه دسترسی به گاوداری, گاو و شیر داده شده است . . .:)",QMessageBox::Ok);

             else if(Data::get_iterator()->get_level()==6)
                 QMessageBox::information(this,"تبریک","سطح شما افزایش پیدا کرد, در این سطح به شما اجازه دسترسی به آغل, گوسفند و پشم گوسفند داده شده است . . .:)",QMessageBox::Ok);

             else
                 QMessageBox::information(this,"تبریک","سطح شما افزایش پیدا کرد . . .:)",QMessageBox::Ok);
         }
          Data::get_iterator()->get_farm().Get_MyThread().Set_planting_Gandomfarm(0);
          return;
}
          else{
             QMessageBox::warning(this,"ظرفیت","سیلو ظرفیت کافی را ندارد. .",QMessageBox::Ok);
          }
    }
    else {
        QMessageBox::warning(this,"تاریخ","زمین هنوز آماده برداشت نیست. .",QMessageBox::Ok);
    }

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
