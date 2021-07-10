#include "Store.h"
#include "ui_Store.h"

Store::Store(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Store)
{
    ui->setupUi(this);
}


Store::~Store(){
    delete ui;
}


// Slots :

void Store::on_Return_to_Farm_pbn_clicked()
{
    this->close();
}





void Store::on_Buy_Cow_pbn_clicked()
{

}


void Store::on_Sell_Cow_pbn_clicked()
{

}


void Store::on_Buy_Sheep_pbn_clicked()
{

}


void Store::on_Sell_Sheep_pbn_clicked()
{

}


void Store::on_Buy_Chicken_pbn_clicked()
{

}


void Store::on_Sell_Chicken_pbn_clicked()
{

}


void Store::on_Buy_Milk_pbn_clicked()
{

}


void Store::on_Sell_Milk_pbn_clicked()
{

}


void Store::on_Buy_Wool_pbn_clicked()
{

}


void Store::on_Sell_Wool_pbn_clicked()
{

}


void Store::on_Buy_Egg_pbn_clicked()
{

}


void Store::on_Sell_Egg_pbn_clicked()
{

}


void Store::on_Buy_Gandom_pbn_clicked()
{

}


void Store::on_Sell_Gandom_pbn_clicked()
{

}


void Store::on_Buy_Yonjeh_pbn_clicked()
{

}


void Store::on_Sell_Gandom_pbn_2_clicked()
{

}


void Store::on_Buy_Bill_pbn_clicked()
{

}


void Store::on_Sell_Bill_pbn_clicked()
{

}


void Store::on_Buy_Mikh_pbn_clicked()
{

}


void Store::on_Sell_Mikh_pbn_clicked()
{

}

