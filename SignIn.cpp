#include "SignIn.h"
#include "ui_SignIn.h"
#include "SignUp.h"
#include <QVector>
#include <fstream>
#include <QMessageBox>



SignIn::SignIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignIn)
{
    ui->setupUi(this);

    ifstream f("Players.txt");
    if (f.is_open() && Data::get_players().isEmpty()) {
        QVector<Player> players;
        Player p;
        while(!f.eof()) {
            f.read((char*)&p, sizeof (p));
            players.push_back(p);
        }
        f.close();
        Data::set_players(players);
    }

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
    if (ui->usernameLE->text().isEmpty() || ui->passLE->text().isEmpty()) {
       // QMessageBox::warning(this, "تذکر", "نام کاربری و رمز عبور نمی تواند خالی باشد!");
        return;
    }
    for (int i = 0; i < (Data::get_players()).size(); i++)
        if (ui->usernameLE->text() == Data::get_players()[i].get_username()) {
            if (ui->passLE->text() == Data::get_players()[i].get_password()) {
                Data::set_iterator(Data::get_players().begin() + i);
                Data::get_iterator()->get_farm().show();
                return;
            }
            else {
         //       QMessageBox::warning(this, "تذکر", "رمز عبور اشتباه است!");
                return;
            }
        }
    //QMessageBox::warning(this, "تذکر", "نام کاربری یافت نشد!");
}

