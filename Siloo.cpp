#include "Siloo.h"
#include "ui_Siloo.h"

Siloo::Siloo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Siloo)
{
    ui->setupUi(this);

    this->gandom.Set_Type("gandom");

    ui->Siloo_Capacity = this->capasity;
    ui->Gandom_Available = this->occupied_capacity;
    ui->Siloo_Level = this->building_Level;
}


Product Siloo::Get_gandom ()
{
    return this->gandom;
}

void Siloo::Set_Gandom (Product _gandom)
{
    gandom = _gandom;
}




void Siloo::on_Upgrade_Siloo_clicked()
{

    /*
        if(!(Num_Mikh >= this->building_Level && Num_Coin >= pow((this->building_Level*2),2))*100){

            // Warning : QmessageBox()
        }

        else {
            this->building_Level *= 2;

            //Information : Qmessagebox()
        }
    */

}

void Siloo::on_Return_to_Farm_clicked()
{
    this->close();
}




Siloo::~Siloo(){
    delete ui;
}
