#include "ChickenHome.h"
#include "ui_ChickenHome.h"
#include "Data.h"

ChickenHome::ChickenHome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChickenHome)
{
    ui->setupUi(this);
    capacity=2;
    stock_animal=0;
    level_habitat=1;
    is_build=false;
    setFixedSize(403, 339);
}

ChickenHome::~ChickenHome()
{
    delete ui;
}

void ChickenHome::operator=(const ChickenHome& p){
    capacity=p.capacity;
    stock_animal=p.stock_animal;
    level_habitat=p.level_habitat;
    is_build=p.is_build;
}

void ChickenHome::build(){
    if(Data::get_iterator()->get_coin()>=10){
        if(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()>=2){
            Data::get_iterator()->get_farm().Get_MyThread().Set_build_ChickenHome(time(NULL));
            Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()-10);
            Data::get_iterator()->get_farm().get_storage().Get_mikh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()-2);
            Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()-2);
            QMessageBox::information(this," ","ساختن مرغداری با موفقیت آغاز شد");
        }
        else
            QMessageBox::warning(this,"تذکر","میخ به اندازه کافی موجود نمی باشد");
    }
    else
        QMessageBox::warning(this,"تذکر","سکه به اندازه کافی موجود نمی باشد");
}

void ChickenHome::on_upgrade_btn_clicked()
{
    if(Data::get_iterator()->get_farm().Get_MyThread().Get_upgrade_ChickenHome()==0){
        if(Data::get_iterator()->get_level()>=3){
            if(Data::get_iterator()->get_coin()>=10){
                if(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()>=1){
                    Data::get_iterator()->get_farm().get_storage().Get_mikh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()-1);
                    Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()-10);
                    Data::get_iterator()->get_farm().Get_MyThread().Set_upgrade_ChickenHome(time(NULL));
                    Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()-1);
                    QMessageBox::information(this," ","فرایند ارتقای مرغداری با موفقیت آغاز شد");
                }
                else
                    QMessageBox::warning(this,"تذکر","میخ به اندازه کافی موجود نمی باشد");

            }
            else
                QMessageBox::warning(this,"تذکر","سکه به اندازه کافی موجود نمی باشد");

        }
        else
            QMessageBox::warning(this,"تذکر","سطح شما برای ارتقا باید حداقل 3 باشد");
    }
    else
        QMessageBox::warning(this,"تذکر","مرغداری در حال ارتقا یافتن است");

}

void ChickenHome::on_feeding_btn_clicked()
{
    if(stock_animal!=0){
        if(Data::get_iterator()->get_farm().get_siloo().Get_gandom().Get_Number() >=stock_animal){
            if(time(NULL)-Data::get_iterator()->get_farm().Get_MyThread().Get_feed_time_chicken()>=2*24*3600){
                if (Data::get_iterator()->get_farm().Get_MyThread().Get_feed_time_chicken()==0){
                    Data::get_iterator()->get_farm().get_siloo().Get_gandom().Set_Number(Data::get_iterator()->get_farm().get_siloo().Get_gandom().Get_Number()-stock_animal);
                    Data::get_iterator()->get_farm().Get_MyThread().Set_feed_time_chicken(time(NULL));
                    Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+stock_animal);
                    QMessageBox::information(this," ","غذا دادن با موفقیت انجام شد");
                    if(Data::get_iterator()->get_experience()>=Data::get_iterator()->get_experience_required_for_levelUp()){
                        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
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
                }
                else
                    QMessageBox::warning(this,"تذکر","شما هنوز تخم مرغ‌ها را جمع آوری نکرده‌اید");

            }
            else
                QMessageBox::warning(this,"تذکر","شما به تازگی به مرغ‌ها غذا داده‌اید");

        }
        else
            QMessageBox::warning(this,"تذکر","گندم به مقدار کافی در سیلو موجود نمی باشد");

    }
    else
        QMessageBox::warning(this,"تذکر","حیوانی در مرغداری موجود نمی باشد");

}

void ChickenHome::on_collect_btn_clicked()
{
    if(Data::get_iterator()->get_farm().get_storage().GetCapasity()-Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()>=stock_animal){
        if(time(NULL)-Data::get_iterator()->get_farm().Get_MyThread().Get_feed_time_chicken()>2*24*3600){
            if(Data::get_iterator()->get_farm().Get_MyThread().Get_feed_time_chicken()!=0){
                Data::get_iterator()->get_farm().Get_MyThread().Set_feed_time_chicken(0);
                Data::get_iterator()->get_farm().get_storage().Get_egg().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_egg().Get_Number()+stock_animal);
                Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_egg().Get_Number()+stock_animal);
                Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+2*stock_animal);
                QMessageBox::information(this," ","برداشت تخم مرغ‌ با موفقیت انجام شد");
                if(Data::get_iterator()->get_experience()>=Data::get_iterator()->get_experience_required_for_levelUp()){
                    Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
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
            }
            else
                QMessageBox::warning(this,"تذکر","لطفا ابتدا به مرغ‌ها غذا دهید");

        }
        else
            QMessageBox::warning(this,"تذکر","شما امکان برداشت تخم مرغ‌‌ را ندارید زیرا به تازگی به مرغ‌ها غذا داده‌اید");

    }
    else
        QMessageBox::warning(this,"تذکر","فضا به مقدار کافی در انبار موجود نمی باشد");

}

void ChickenHome::on_back_btn_clicked()
{
    emit Send_Signal_to_Farm();
    this->close();
}

void ChickenHome::Get_Signal_From_Farm()
{
    ui->capacity_lbl->setText(QString::number(capacity));
    ui->level_lbl->setText(QString::number(level_habitat));
    ui->stockanimal_lbl->setText(QString::number(stock_animal));
}
