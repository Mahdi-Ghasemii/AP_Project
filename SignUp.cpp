#include "SignUp.h"
#include "ui_SignUp.h"
#include "SignIn.h"


SignUp::SignUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_back_pbn_clicked()
{
    SignIn* si = new SignIn();
    this->close();
    si->show();
}


void SignUp::on_register_pbn_clicked()
{

}

