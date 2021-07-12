#include "SignIn.h"
#include "ui_SignIn.h"
#include "SignUp.h"
#include "Player.h"
#include "Data.h"
#include <QVector>
#include <fstream>



SignIn::SignIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignIn)
{
    ui->setupUi(this);

    ifstream f("Players.txt");
    if (f.is_open()) {
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

}

