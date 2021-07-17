#include "Builting.h"
#include "ui_Builting.h"

Builting::Builting(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Builting)
{
    ui->setupUi(this);
}

Builting::~Builting()
{
    delete ui;
}

void Builting::on_yes_btn_clicked()
{
    emit Send_Signal_to_Farm("yes");
     this->close();
}

void Builting::on_no_btn_clicked()
{
    emit Send_Signal_to_Farm("no");
    this->close();

}
