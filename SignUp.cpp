#include "SignUp.h"
#include "ui_SignUp.h"
#include "SignIn.h"
#include "Data.h"
#include <fstream>
#include <iostream>
#include <QMessageBox>

using namespace std;


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
    if (ui->nameLE->text().isEmpty() || ui->usernameLE->text().isEmpty() || ui->passLE->text().isEmpty() || ui->repassLE->text().isEmpty()
            || ui->emailLE->text().isEmpty()) {
        QMessageBox::warning(this, "تذکر", "همه فیلدها باید پر شوند!");
        return;
    }
    for (int i = 0; i < Data::get_players().size(); i++) {
        if (ui->usernameLE->text() == Data::get_players()[i].get_username()) {
            QMessageBox::warning(this, "تذکر", "این نام کاربری قبلا استفاده شده است!");
            return;
        }
    }
    if (ui->passLE->text() != ui->repassLE->text()) {
        QMessageBox::warning(this, "تذکر", "رمز عبور و تکرار آن یکسان نیست!");
        return;
    }
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
    Data::get_players().append(p);
    ofstream f("Players.txt", ios::app);
    f.write((char*)&p, sizeof(p));
    f.close();
    QMessageBox::information(this, "تکمیل ثبت نام", "ثبت نام شما با موفقیت انجام شد");
}

