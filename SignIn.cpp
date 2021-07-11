
#include "SignIn.h"
#include "ui_SignIn.h"
#include "SignUp.h"
#include "Player.h"



SignIn::SignIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignIn)
{
    ui->setupUi(this);
}

SignIn::~SignIn()
{
    delete ui;
}

void SignIn::on_sign_up_pbn_clicked()
{
    SignUp* su = new SignUp();
    this->close();
    su->show();
}


void SignIn::on_sign_in_pbn_clicked()
{

}

