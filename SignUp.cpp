#include "SignUp.h"
#include "ui_SignUp.h"
#include "SignIn.h"
#include "Data.h"
#include <fstream>


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
    Player p;
    p.set_name(ui->nameLE->text());
    p.set_username(ui->usernameLE->text());
    p.set_password(ui->passLE->text());
    p.set_email(ui->emailLE->text());
    p.set_coin(20);
    p.set_level(1);
    p.set_experience(0);
    p.set_experience_required_for_levelUp(2 * p.get_experience() + 10);
    time_t t = time(NULL);
    p.set_signUp_time(t);
    ofstream f("Players.txt", ios::app);
    f.write((char*)&p, sizeof(p));
    f.close();
    SignIn* si = new SignIn();
    this->close();
    si->show();
}

