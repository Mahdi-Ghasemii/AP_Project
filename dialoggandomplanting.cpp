#include "dialoggandomplanting.h"
#include "ui_dialoggandomplanting.h"

DialogGandomPlanting::DialogGandomPlanting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogGandomPlanting)
{
    ui->setupUi(this);
}

DialogGandomPlanting::~DialogGandomPlanting()
{
    delete ui;
}

void DialogGandomPlanting::on_buttonBox_accepted()
{
    emit plantingareawanting ((ui->lineEdit->text()).toInt());
}

