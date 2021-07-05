
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
