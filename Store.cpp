#include "Store.h"
#include "ui_Store.h"
#include "Data.h"
#include <QString>


Store::Store(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Store)
{
    ui->setupUi(this);
    setFixedSize(934, 578);

}

void Store::operator =(const Store&){


}


Store::~Store(){
   // delete ui;
}


// Slots :


void Store::on_Return_to_Farm_clicked()
{
    emit Send_Signal_to_Farm();

    this->close();
}

void Store::Add_Experience_and_Check_Level(int _e){

    Data::get_iterator()->set_experience(Data::get_iterator()->get_experience() +_e);

    if(Data::get_iterator()->get_experience() >= Data::get_iterator()->get_experience_required_for_levelUp()){
        Data::get_iterator()->set_level(Data::get_iterator()->get_level()+1);
        Data::get_iterator()->set_experience_required_for_levelUp(Data::get_iterator()->get_experience_required_for_levelUp()*2+10);


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


void Store::on_Buy_Gandom_pbn_clicked()
{

    if(Data::get_iterator()->get_coin() < 3){
        QMessageBox::warning(this,"تذکر","تعداد سکه برای خرید کافی نمی باشد .",QMessageBox::Ok);
        return ;
    }
    else if(Data::get_iterator()->get_farm().get_siloo().GetCapasity() <= Data::get_iterator()->get_farm().get_siloo().Get_Occupied_Capacity()){
        QMessageBox::warning(this,"تذکر","ظرفیت سیلو برای خرید گندم کافی نمی باشد .",QMessageBox::Ok);
        return ;
    }

    else {

//        QMessageBox::information(this,"","خرید با موفقیت انجام شد.",QMessageBox::Ok);

        Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()- 3);
        ui->Num_Coin->setText(QString::number(Data::get_iterator()->get_coin()));

        Data::get_iterator()->get_farm().get_siloo().Get_gandom().Set_Number(Data::get_iterator()->get_farm().get_siloo().Get_gandom().Get_Number()+1);
        ui->Num_Gandom->setText(QString::number(Data::get_iterator()->get_farm().get_siloo().Get_gandom().Get_Number()));

        Data::get_iterator()->get_farm().get_siloo().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_siloo().Get_Occupied_Capacity() + 1);


        Add_Experience_and_Check_Level(1);

         return ;

    }
}


void Store::on_Sell_Gandom_pbn_clicked()
{

    if(Data::get_iterator()->get_farm().get_siloo().Get_gandom().Get_Number() < 1){
        QMessageBox::warning(this,"تذکر","تعداد گندم موجود در سیلو کافی نمی باشد .",QMessageBox::Ok);
        return ;
    }
    else {

//        QMessageBox::information(this,"","جنس مورد نظر با موفقیت فروخته شد.",QMessageBox::Ok);

        Data::get_iterator()->set_coin(Data::get_iterator()->get_coin() + 2);
        ui->Num_Coin->setText(QString::number(Data::get_iterator()->get_coin()));

        Data::get_iterator()->get_farm().get_siloo().Get_gandom().Set_Number(Data::get_iterator()->get_farm().get_siloo().Get_gandom().Get_Number()-1);
        ui->Num_Gandom->setText(QString::number(Data::get_iterator()->get_farm().get_siloo().Get_gandom().Get_Number()));

        Data::get_iterator()->get_farm().get_siloo().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_siloo().Get_Occupied_Capacity() - 1);

        Add_Experience_and_Check_Level(6);

         return ;
    }
}




void Store::on_Buy_Cow_pbn_clicked()
{
    if(Data::get_iterator()->get_farm().get_cowHome().get_is_build() == 0){
        QMessageBox::warning(this,"تذکر","گاو داری هنوز ساخته نشده است . . .",QMessageBox::Ok);
        return ;
    }
    else if(Data::get_iterator()->get_level() < 4){
        QMessageBox::warning(this,"تذکر","حداقل سطح مورد نیاز برای خرید گاو ، 4 می باشد . .",QMessageBox::Ok);
        return ;
    }

    else if(Data::get_iterator()->get_coin() < 70){
        QMessageBox::warning(this,"تذکر","تعداد سکه برای خرید گاو کافی نمی باشد .",QMessageBox::Ok);
        return ;
    }
    else if(Data::get_iterator()->get_farm().Get_MyThread().Get_feed_time_cow() != 0){
        QMessageBox::warning(this,"تذکر","در هنگام غذا خوردن گاو ها ، امکان خرید گاو وجود ندارد     . . .",QMessageBox::Ok);
        return ;
    }

    else if(Data::get_iterator()->get_farm().get_cowHome().get_capacity() <= Data::get_iterator()->get_farm().get_cowHome().get_stock_animal()){
        QMessageBox::warning(this,"تذکر","ظرفیت گاوداری برای نگه داری گاو کافی نمی باشد .",QMessageBox::Ok);
        return ;
    }

    else {

//        QMessageBox::information(this,"","خرید با موفقیت انجام شد.",QMessageBox::Ok);

        Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()- 70);
        ui->Num_Coin->setText(QString::number(Data::get_iterator()->get_coin()));

        Data::get_iterator()->get_farm().get_cowHome().set_stock_animal(Data::get_iterator()->get_farm().get_cowHome().get_stock_animal()+1);
        ui->Num_Cow->setText(QString::number(Data::get_iterator()->get_farm().get_cowHome().get_stock_animal()));

        Add_Experience_and_Check_Level(10);


         return ;

    }

}


void Store::on_Sell_Cow_pbn_clicked()
{

    if(Data::get_iterator()->get_farm().get_cowHome().get_is_build() == 0){
        QMessageBox::warning(this,"تذکر","گاو داری هنوز ساخته نشده است . . .",QMessageBox::Ok);
        return ;
    }
    else if(Data::get_iterator()->get_level() < 4){
        QMessageBox::warning(this,"تذکر","حداقل سطح مورد نیاز برای فروش گاو ، 4 می باشد . .",QMessageBox::Ok);
        return ;
    }
    else if(Data::get_iterator()->get_farm().get_cowHome().get_stock_animal() < 1){
        QMessageBox::warning(this,"تذکر","تعداد گاو های موجود در گاوداری کافی نمی باشد .",QMessageBox::Ok);
        return ;
    }

    else if(Data::get_iterator()->get_farm().Get_MyThread().Get_feed_time_cow() != 0){
        QMessageBox::warning(this,"تذکر","در هنگام غذا خوردن گاو ها ، امکان خرید گاو وجود ندارد     . . .",QMessageBox::Ok);
        return ;
    }

    else {

//        QMessageBox::information(this,"","جنس مورد نظر با موفقیت فروخته شد.",QMessageBox::Ok);

        Data::get_iterator()->set_coin(Data::get_iterator()->get_coin() + 50);
        ui->Num_Coin->setText(QString::number(Data::get_iterator()->get_coin()));

        Data::get_iterator()->get_farm().get_cowHome().set_stock_animal(Data::get_iterator()->get_farm().get_cowHome().get_stock_animal()-1);
        ui->Num_Cow->setText(QString::number(Data::get_iterator()->get_farm().get_cowHome().get_stock_animal()));

        Add_Experience_and_Check_Level(6);


        return ;
    }
}


void Store::on_Buy_Sheep_pbn_clicked()
{

    if(Data::get_iterator()->get_farm().get_sheepHome().get_is_build() == 0){
        QMessageBox::warning(this,"تذکر","آغل هنوز ساخته نشده است . . .",QMessageBox::Ok);
        return ;
    }
    else if(Data::get_iterator()->get_level() < 6){
        QMessageBox::warning(this,"تذکر","اين مرحله هنوز براي شما قفل است . .",QMessageBox::Ok);
        return ;
    }
    if(Data::get_iterator()->get_coin() < 80){
        QMessageBox::warning(this,"تذکر","تعداد سکه برای خرید گوسفند کافی نمی باشد .",QMessageBox::Ok);
        return ;
    }
    else if(Data::get_iterator()->get_farm().get_sheepHome().get_capacity() <= Data::get_iterator()->get_farm().get_sheepHome().get_stock_animal()){
        QMessageBox::warning(this,"تذکر","ظرفیت آغل برای نگه داری گوسفند کافی نمی باشد .",QMessageBox::Ok);
        return ;
    }
    else if(Data::get_iterator()->get_farm().Get_MyThread().Get_feed_time_sheep() != 0){
        QMessageBox::warning(this,"تذکر","در هنگام غذا خوردن گوسفند ها ، امکان خرید گوسفند وجود ندارد     . . .",QMessageBox::Ok);
        return ;
    }

    else {

//        QMessageBox::information(this,"","خرید با موفقیت انجام شد.",QMessageBox::Ok);

        Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()- 80);
        ui->Num_Coin->setText(QString::number(Data::get_iterator()->get_coin()));

        Data::get_iterator()->get_farm().get_sheepHome().set_stock_animal(Data::get_iterator()->get_farm().get_sheepHome().get_stock_animal()+1);
        ui->Num_Sheep->setText(QString::number(Data::get_iterator()->get_farm().get_sheepHome().get_stock_animal()));

        Add_Experience_and_Check_Level(15);


         return ;

    }

}


void Store::on_Sell_Sheep_pbn_clicked()
{

    if(Data::get_iterator()->get_farm().get_sheepHome().get_is_build() == 0){
        QMessageBox::warning(this,"تذکر","آغل هنوز ساخته نشده است . . .",QMessageBox::Ok);
        return ;
    }
    else if(Data::get_iterator()->get_level() < 6){
        QMessageBox::warning(this,"تذکر","اين مرحله هنوز براي شما قفل است . .",QMessageBox::Ok);
        return ;
    }
    else if(Data::get_iterator()->get_farm().get_sheepHome().get_stock_animal() < 1){
        QMessageBox::warning(this,"تذکر","تعداد گوسفند های موجود در آغل کافی نمی باشد .",QMessageBox::Ok);
        return ;
    }
    else if(Data::get_iterator()->get_farm().Get_MyThread().Get_feed_time_sheep() != 0){
        QMessageBox::warning(this,"تذکر","در هنگام غذا خوردن گوسفند ها ، امکان خرید گوسفند وجود ندارد     . . .",QMessageBox::Ok);
        return ;
    }

    else {

//        QMessageBox::information(this,"","جنس مورد نظر با موفقیت فروخته شد.",QMessageBox::Ok);

        Data::get_iterator()->set_coin(Data::get_iterator()->get_coin() + 70);
        ui->Num_Coin->setText(QString::number(Data::get_iterator()->get_coin()));

        Data::get_iterator()->get_farm().get_sheepHome().set_stock_animal(Data::get_iterator()->get_farm().get_sheepHome().get_stock_animal()-1);
        ui->Num_Sheep->setText(QString::number(Data::get_iterator()->get_farm().get_sheepHome().get_stock_animal()));

        Add_Experience_and_Check_Level(6);


        return ;
    }
}


void Store::on_Buy_Chicken_pbn_clicked()
{

    if(Data::get_iterator()->get_farm().get_chickenHome().get_is_build() == 0){
        QMessageBox::warning(this,"تذکر","مرغ داری هنوز ساخته نشده است . . .",QMessageBox::Ok);
        return ;
    }
    else if(Data::get_iterator()->get_level() < 2){
        QMessageBox::warning(this,"تذکر","اين مرحله هنوز براي شما قفل است . .",QMessageBox::Ok);
        return ;
    }

    else if(Data::get_iterator()->get_coin() < 20){
        QMessageBox::warning(this,"تذکر","تعداد سکه برای خرید مرغ کافی نمی باشد .",QMessageBox::Ok);
        return ;
    }
    else if(Data::get_iterator()->get_farm().get_chickenHome().get_capacity() <= Data::get_iterator()->get_farm().get_chickenHome().get_stock_animal()){
        QMessageBox::warning(this,"تذکر","ظرفیت مرغداری برای نگه داری مرغ کافی نمی باشد .",QMessageBox::Ok);
        return ;
    }
    else if(Data::get_iterator()->get_farm().Get_MyThread().Get_feed_time_chicken() != 0){
        QMessageBox::warning(this,"تذکر","در هنگام غذا خوردن مرغ ها ، امکان خرید مرغ وجود ندارد     . . .",QMessageBox::Ok);
        return ;
    }
    else {

//        QMessageBox::information(this,"","خرید با موفقیت انجام شد.",QMessageBox::Ok);

        Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()- 20);
        ui->Num_Coin->setText(QString::number(Data::get_iterator()->get_coin()));

        Data::get_iterator()->get_farm().get_chickenHome().set_stock_animal(Data::get_iterator()->get_farm().get_chickenHome().get_stock_animal()+1);
        ui->Num_Chicken->setText(QString::number(Data::get_iterator()->get_farm().get_chickenHome().get_stock_animal()));

        Add_Experience_and_Check_Level(5);


         return ;

    }
}


void Store::on_Sell_Chicken_pbn_clicked()
{

    if(Data::get_iterator()->get_farm().get_chickenHome().get_is_build() == 0){
        QMessageBox::warning(this,"تذکر","مرغ داری هنوز ساخته نشده است . . .",QMessageBox::Ok);
        return ;
    }
    if(Data::get_iterator()->get_level() < 2){
        QMessageBox::warning(this,"تذکر","اين مرحله هنوز براي شما قفل است . .",QMessageBox::Ok);
        return ;
    }

    else if(Data::get_iterator()->get_farm().get_chickenHome().get_stock_animal() < 1){
        QMessageBox::warning(this,"تذکر","تعداد مرغ های موجود در مرغداری کافی نمی باشد .",QMessageBox::Ok);
        return ;
    }
    else if(Data::get_iterator()->get_farm().Get_MyThread().Get_feed_time_chicken() != 0){
        QMessageBox::warning(this,"تذکر","در هنگام غذا خوردن مرغ ها ، امکان خرید مرغ وجود ندارد     . . .",QMessageBox::Ok);
        return ;
    }

    else {

//        QMessageBox::information(this,"","جنس مورد نظر با موفقیت فروخته شد.",QMessageBox::Ok);

        Data::get_iterator()->set_coin(Data::get_iterator()->get_coin() + 15);
        ui->Num_Coin->setText(QString::number(Data::get_iterator()->get_coin()));

        Data::get_iterator()->get_farm().get_chickenHome().set_stock_animal(Data::get_iterator()->get_farm().get_chickenHome().get_stock_animal()-1);
        ui->Num_Chicken->setText(QString::number(Data::get_iterator()->get_farm().get_chickenHome().get_stock_animal()));

        Add_Experience_and_Check_Level(6);

        return ;
    }
}


void Store::on_Buy_Yonjeh_pbn_clicked()
{

    if(Data::get_iterator()->get_level() < 3){
        QMessageBox::warning(this,"تذکر","اين مرحله هنوز براي شما قفل است . .",QMessageBox::Ok);
        return ;
    }

    else if(Data::get_iterator()->get_coin() < 6){
        QMessageBox::warning(this,"تذکر","تعداد سکه برای خرید یونجه کافی نمی باشد .",QMessageBox::Ok);
        return ;
    }
    else if(Data::get_iterator()->get_farm().get_storage().GetCapasity() <= Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()){
        QMessageBox::warning(this,"تذکر","ظرفیت انبار برای خرید یونجه کافی نمی باشد .",QMessageBox::Ok);
        return ;
    }

    else {

//        QMessageBox::information(this,"","خرید با موفقیت انجام شد.",QMessageBox::Ok);

        Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()- 6);
        ui->Num_Coin->setText(QString::number(Data::get_iterator()->get_coin()));

        Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Get_Number()+1);
        ui->Num_Yonjeh->setText(QString::number(Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Get_Number()));

        Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity() + 1);

        Add_Experience_and_Check_Level(2);


         return ;

    }

}


void Store::on_Sell_Yonjeh_pbn_clicked()
{

    if(Data::get_iterator()->get_level() < 3){
        QMessageBox::warning(this,"تذکر","اين مرحله هنوز براي شما قفل است . .",QMessageBox::Ok);
        return ;
    }
    else if(Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Get_Number() < 1){
        QMessageBox::warning(this,"تذکر","تعداد یونجه موجود در انبار کافی نمی باشد .",QMessageBox::Ok);
        return ;
    }
    else {

//        QMessageBox::information(this,"","جنس مورد نظر با موفقیت فروخته شد.",QMessageBox::Ok);

        Data::get_iterator()->set_coin(Data::get_iterator()->get_coin() + 4);
        ui->Num_Coin->setText(QString::number(Data::get_iterator()->get_coin()));

        Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Get_Number()-1);
        ui->Num_Yonjeh->setText(QString::number(Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Get_Number()));

        Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity() - 1);

        Add_Experience_and_Check_Level(6);

         return ;
    }
}




void Store::on_Sell_Milk_pbn_clicked()
{

    if(Data::get_iterator()->get_farm().get_storage().Get_milk().Get_Number() < 1){
        QMessageBox::warning(this,"تذکر","تعداد شیر های موجود در انبار کافی نمی باشد .",QMessageBox::Ok);
        return ;
    }
    else {

//        QMessageBox::information(this,"","جنس مورد نظر با موفقیت فروخته شد.",QMessageBox::Ok);

        Data::get_iterator()->set_coin(Data::get_iterator()->get_coin() + 12);
        ui->Num_Coin->setText(QString::number(Data::get_iterator()->get_coin()));

        Data::get_iterator()->get_farm().get_storage().Get_milk().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_milk().Get_Number()-1);
        ui->Num_Milk->setText(QString::number(Data::get_iterator()->get_farm().get_storage().Get_milk().Get_Number()));

        Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity() - 1);

        Add_Experience_and_Check_Level(6);

         return ;
    }

}


void Store::on_Sell_Wool_pbn_clicked()
{

    if(Data::get_iterator()->get_level() < 6){
        QMessageBox::warning(this,"تذکر","اين مرحله هنوز براي شما قفل است . .",QMessageBox::Ok);
        return ;
    }
    else if(Data::get_iterator()->get_farm().get_storage().Get_pashm().Get_Number() < 1){
        QMessageBox::warning(this,"تذکر","تعداد پشم گوسفند های موجود در انبار کافی نمی باشد .",QMessageBox::Ok);
        return ;
    }
    else {

//        QMessageBox::information(this,"","جنس مورد نظر با موفقیت فروخته شد.",QMessageBox::Ok);

        Data::get_iterator()->set_coin(Data::get_iterator()->get_coin() + 23);
        ui->Num_Coin->setText(QString::number(Data::get_iterator()->get_coin()));

        Data::get_iterator()->get_farm().get_storage().Get_pashm().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_pashm().Get_Number()-1);
        ui->Num_Wool->setText(QString::number(Data::get_iterator()->get_farm().get_storage().Get_pashm().Get_Number()));

        Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity() - 1);

        Add_Experience_and_Check_Level(6);

         return ;
    }
}



void Store::on_Sell_Egg_pbn_clicked()
{

    if(Data::get_iterator()->get_level() < 2){
        QMessageBox::warning(this,"تذکر","اين مرحله هنوز براي شما قفل است . .",QMessageBox::Ok);
        return ;
    }
    else if(Data::get_iterator()->get_farm().get_storage().Get_egg().Get_Number() < 1){
        QMessageBox::warning(this,"تذکر","تعداد تخم مرغ های موجود در انبار کافی نمی باشد .",QMessageBox::Ok);
        return ;
    }
    else {

//        QMessageBox::information(this,"","جنس مورد نظر با موفقیت فروخته شد.",QMessageBox::Ok);

        Data::get_iterator()->set_coin(Data::get_iterator()->get_coin() + 8);
        ui->Num_Coin->setText(QString::number(Data::get_iterator()->get_coin()));

        Data::get_iterator()->get_farm().get_storage().Get_egg().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_egg().Get_Number()-1);
        ui->Num_Egg->setText(QString::number(Data::get_iterator()->get_farm().get_storage().Get_egg().Get_Number()));

        Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity() - 1);

        Add_Experience_and_Check_Level(6);

         return ;
    }
}


void Store::on_Buy_Bill_pbn_clicked()
{

    if(Data::get_iterator()->get_coin() < 50){
        QMessageBox::warning(this,"تذکر","تعداد سکه برای خرید بیل کافی نمی باشد .",QMessageBox::Ok);
        return ;
    }
    else if(Data::get_iterator()->get_farm().get_storage().GetCapasity() <= Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()){
        QMessageBox::warning(this,"تذکر","ظرفیت انبار برای خرید بیل کافی نمی باشد .",QMessageBox::Ok);
        return ;
    }

    else {

//        QMessageBox::information(this,"","خرید با موفقیت انجام شد.",QMessageBox::Ok);

        Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()- 50);
        ui->Num_Coin->setText(QString::number(Data::get_iterator()->get_coin()));

        Data::get_iterator()->get_farm().get_storage().Get_bill().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_bill().Get_Number()+1);
        ui->Num_Bill->setText(QString::number(Data::get_iterator()->get_farm().get_storage().Get_bill().Get_Number()));

        Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity() + 1);

        Add_Experience_and_Check_Level(8);


         return ;

    }
}


void Store::on_Sell_Bill_pbn_clicked()
{

    if(Data::get_iterator()->get_farm().get_storage().Get_bill().Get_Number() < 1){
        QMessageBox::warning(this,"تذکر","تعداد بیل های موجود در انبار کافی نمی باشد .",QMessageBox::Ok);
        return ;
    }
    else {

//        QMessageBox::information(this,"","جنس مورد نظر با موفقیت فروخته شد.",QMessageBox::Ok);

        Data::get_iterator()->set_coin(Data::get_iterator()->get_coin() + 30);
        ui->Num_Coin->setText(QString::number(Data::get_iterator()->get_coin()));

        Data::get_iterator()->get_farm().get_storage().Get_bill().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_bill().Get_Number()-1);
        ui->Num_Bill->setText(QString::number(Data::get_iterator()->get_farm().get_storage().Get_bill().Get_Number()));

        Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity() - 1);

        Add_Experience_and_Check_Level(6);

         return ;
    }
}


void Store::on_Buy_Mikh_pbn_clicked()
{

    if(Data::get_iterator()->get_coin() < 30){
        QMessageBox::warning(this,"تذکر","تعداد سکه برای خرید ميخ کافی نمی باشد .",QMessageBox::Ok);
        return ;
    }
    else if(Data::get_iterator()->get_farm().get_storage().GetCapasity() <= Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()){
        QMessageBox::warning(this,"تذکر","ظرفیت انبار برای خرید ميخ کافی نمی باشد .",QMessageBox::Ok);
        return ;
    }

    else {

//        QMessageBox::information(this,"","خرید با موفقیت انجام شد.",QMessageBox::Ok);

        Data::get_iterator()->set_coin(Data::get_iterator()->get_coin()- 30);
        ui->Num_Coin->setText(QString::number(Data::get_iterator()->get_coin()));

        Data::get_iterator()->get_farm().get_storage().Get_mikh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()+1);
        ui->Num_Mikh->setText(QString::number(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()));

        Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity() + 1);

        Add_Experience_and_Check_Level(4);


         return ;
      }

}


void Store::on_Sell_Mikh_pbn_clicked()
{

    if(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number() < 1){
        QMessageBox::warning(this,"تذکر","تعداد ميخ های موجود در انبار کافی نمی باشد .",QMessageBox::Ok);
        return ;
    }
    else {

//        QMessageBox::information(this,"","جنس مورد نظر با موفقیت فروخته شد.",QMessageBox::Ok);

        Data::get_iterator()->set_coin(Data::get_iterator()->get_coin() + 20);
        ui->Num_Coin->setText(QString::number(Data::get_iterator()->get_coin()));

        Data::get_iterator()->get_farm().get_storage().Get_mikh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()-1);
        ui->Num_Mikh->setText(QString::number(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()));

        Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity() - 1);

        Add_Experience_and_Check_Level(6);

         return ;
    }
}

void Store::Get_Signal_From_Farm()
{


    ui->Num_Coin->setText(QString::number(Data::get_iterator()->get_coin()));

    // set storages product
    ui->Num_Bill->setText(QString::number(Data::get_iterator()->get_farm().get_storage().Get_bill().Get_Number()));
    ui->Num_Egg->setText(QString::number(Data::get_iterator()->get_farm().get_storage().Get_egg().Get_Number()));
    ui->Num_Mikh->setText(QString::number(Data::get_iterator()->get_farm().get_storage().Get_mikh().Get_Number()));
    ui->Num_Milk->setText(QString::number(Data::get_iterator()->get_farm().get_storage().Get_milk().Get_Number()));
    ui->Num_Wool->setText(QString::number(Data::get_iterator()->get_farm().get_storage().Get_pashm().Get_Number()));
    ui->Num_Yonjeh->setText(QString::number(Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Get_Number()));

    // set siloos product
    ui->Num_Gandom->setText(QString::number(Data::get_iterator()->get_farm().get_siloo().Get_gandom().Get_Number()));

    // set Habitats animal
    ui->Num_Sheep->setText(QString::number(Data::get_iterator()->get_farm().get_sheepHome().get_stock_animal()));
    ui->Num_Cow->setText(QString::number(Data::get_iterator()->get_farm().get_cowHome().get_stock_animal()));
    ui->Num_Chicken->setText(QString::number(Data::get_iterator()->get_farm().get_chickenHome().get_stock_animal()));
}
