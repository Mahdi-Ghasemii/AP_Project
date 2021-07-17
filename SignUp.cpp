#include "SignUp.h"
#include "ui_SignUp.h"
#include "SignIn.h"
#include "Data.h"
#include <fstream>
#include <QMessageBox>
#include <QPixmap>
#include <QPalette>

using namespace std;


SignUp::SignUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);

    setFixedSize(300, 358);

    QPixmap qpm(":/background/backgrounds/istockphoto-1127237731-612x612 (1).png");
    qpm = qpm.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette qp;
    qp.setBrush(QPalette::Window, qpm);
    this->setPalette(qp);
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
    Data::get_players().append(p);
    p.get_farm().Get_MyThread().Set_time_login(time(NULL));

    QFile f("Players.json");
    f.open(QIODevice::ReadOnly);
    QJsonDocument d = QJsonDocument::fromJson(f.readAll());
    f.close();
    QJsonObject o = d.object();
    QJsonObject temp;
    temp["Name"] = p.get_name();
    temp["Username"] = p.get_username();
    temp["Password"] = p.get_password();
    temp["Email"] = p.get_email();
    temp["Coin"] = p.get_coin();
    temp["Level"] = p.get_level();
    temp["Experience"] = p.get_experience();
    temp["Experience required for levelUp"] = p.get_experience_required_for_levelUp();
    temp["SignUp time"] = p.get_farm().Get_MyThread().Get_time_login();
    temp["last_time_set"] = p.get_farm().Get_MyThread().Get_last_time_set();
    temp["upgrade_Storage time"] = 0;
    temp["upgrade_Siloo time"] = 0;
    temp["buy_Milk time"] = 0;
    temp["ChickenHome is build"] = false;
    temp["CowHome is build"] = false;
    temp["SheepHome is build"] = false;
    temp["YonjehFarm is build"] = false;
    temp["YonjehFarm is plantable"] = false;
    temp["upgrade_ChickenHome time"] = 0;
    temp["build_ChickenHome time"] = 0;
    temp["feed_time_chicken"] = 0;
    temp["upgrade_CowHome time"] = 0;
    temp["build_CowHome time"] = 0;
    temp["feed_time_cow"] = 0;
    temp["upgrade_SheepHome time"] = 0;
    temp["build_SheepHome time"] = 0;
    temp["feed_time_sheep"] = 0;
    temp["upgrade_Gandomfarm time"] = 0;
    temp["Collect_from_GandomFarm time"] = 0;
    temp["Planting_from_GandomFarm time"] = 0;
    temp["Planting_from_YonjeFarm time"] = 0;
    temp["upgrade_Yonjehfarm time"] = 0;
    temp["Collect_from_YonjehFarm time"] = 0;
    temp["Build_YonjehFarm time"] = 0;
    temp["Plow_YonjehFarm time"] = 0;
    temp["Mikh number"] = 1;
    temp["Bill number"] = 0;
    temp["Yonjeh number"] = 1;
    temp["Egg number"] = 0;
    temp["Milk number"] = 0;
    temp["Pashm number"] = 0;
    temp["Storage capacity"] = 5;
    temp["Storage level"] = 1;
    temp["Storage occupied capacity"] = 2;
    temp["Gandom number"] = 1;
    temp["Siloo capacity"] = 10;
    temp["Siloo level"] = 1;
    temp["Siloo occupied capacity"] = 1;
    temp["ChickenHome capacity"] = 0;
    temp["ChickenHome level"] = 1;
    temp["ChickenHome stock"] = 0;
    temp["CowHome capacity"] = 0;
    temp["CowHome level"] = 1;
    temp["CowHome stock"] = 0;
    temp["SheepHome capacity"] = 0;
    temp["SheepHome level"] = 1;
    temp["SheepHome stock"] = 0;
    temp["GandomFarm area"] = 5;
    temp["GandomFarm level"] = 1;
    temp["YonjehFarm area"] = 4;
    temp["YonjehFarm level"] = 1;
    o[p.get_username()] = temp;
    d.setObject(o);
    f.open(QIODevice::WriteOnly);
    f.write(d.toJson());
    f.close();
    QMessageBox::information(this, "تکمیل ثبت نام", "ثبت نام شما با موفقیت انجام شد");

}

