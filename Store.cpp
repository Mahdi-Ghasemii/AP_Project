#include "Store.h"
#include "ui_Store.h"

Store::Store(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Store)
{
    ui->setupUi(this);
}

void Store::Check_All_Products (int num_gandom,int num_yonjeh,int num_bill,int num_mikh,int num_egg,int num_milk,int num_pashm)
{

}

void Store::Sell_Product (int num_gandom,int num_yonjeh,int num_bill,int num_mikh,int num_egg,int num_milk,int num_pashm)
{

}

void Store::Buy_Product (int num_gandom,int num_yonjeh,int num_bill,int num_mikh,int num_egg,int num_milk,int num_pashm)
{

}

Store::~Store(){
    delete ui;
}
