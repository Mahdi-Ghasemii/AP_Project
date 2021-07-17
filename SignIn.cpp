#include "SignIn.h"
#include "ui_SignIn.h"
#include "SignUp.h"
#include <fstream>
#include <QMessageBox>
#include <QDebug>
using namespace std;


SignIn::SignIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignIn)
{
    ui->setupUi(this);

    QPixmap qpm(":/background/backgrounds/92-Picture-Blur-Nature-500x281.png");
    qpm = qpm.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette qp;
    qp.setBrush(QPalette::Window, qpm);
    this->setPalette(qp);

    QFile f("Players.json");
    f.open(QIODevice::ReadOnly);
    if (f.isOpen() && Data::get_players().isEmpty()) {
        QJsonDocument d = QJsonDocument::fromJson(f.readAll());
        QJsonObject o = d.object();
        QJsonObject temp;
        Player p;
        QStringList sl = o.keys();
        for (int i = 0; i < sl.size(); i++) {
            temp = o[sl[i]].toObject();
            p.set_name(temp["Name"].toString());
            p.set_username(temp["Username"].toString());
            p.set_password(temp["Password"].toString());
            p.set_email(temp["Email"].toString());
            p.set_coin(temp["Coin"].toInt());
            p.set_level(temp["Level"].toInt());
            p.set_experience(temp["Experience"].toInt());
            p.set_experience_required_for_levelUp(temp["Experience required for levelUp"].toInt());
            p.get_farm().Get_MyThread().Set_time_login(temp["SignUp time"].toInt());
            p.get_farm().Get_MyThread().Set_last_time_set(temp["last_time_set"].toInt());
            p.get_farm().Get_MyThread().Set_upgrade_Storage(temp["upgrade_Storage time"].toInt());
            p.get_farm().Get_MyThread().Set_upgrade_Siloo(temp["upgrade_Siloo time"].toInt());
            QJsonArray arr = temp["buy_Milk time"].toArray();
            for (int i = 0; i < arr.size(); i++)
                p.get_farm().Get_MyThread().Push_Back_on_buy_Milk(arr[i].toInt());
            p.get_farm().Get_MyThread().Set_upgrade_ChickenHome(temp["upgrade_ChickenHome time"].toInt());
            p.get_farm().Get_MyThread().Set_build_ChickenHome(temp["build_ChickenHome time"].toInt());
            p.get_farm().Get_MyThread().Set_feed_time_chicken(temp["feed_time_chicken"].toInt());
            p.get_farm().Get_MyThread().Set_upgrade_CowHome(temp["upgrade_CowHome time"].toInt());
            p.get_farm().Get_MyThread().Set_build_CowHome(temp["build_CowHome time"].toInt());
            p.get_farm().Get_MyThread().Set_feed_time_cow(temp["feed_time_cow"].toInt());
            p.get_farm().Get_MyThread().Set_upgrade_SheepHome(temp["upgrade_SheepHome time"].toInt());
            p.get_farm().Get_MyThread().Set_build_SheepHome(temp["build_SheepHome time"].toInt());
            p.get_farm().Get_MyThread().Set_feed_time_sheep(temp["feed_time_sheep"].toInt());
            p.get_farm().Get_MyThread().Set_upgrade_Gandomfarm(temp["upgrade_Gandomfarm time"].toInt());
            p.get_farm().Get_MyThread().Set_Collect_from_GandomFarm(temp["Collect_from_GandomFarm time"].toInt());
            p.get_farm().Get_MyThread().Set_planting_Gandomfarm(temp["Planting_from_GandomFarm time"].toInt());
            p.get_farm().Get_MyThread().Set_planting_YonjeFarm(temp["Planting_from_YonjeFarm time"].toInt());
            p.get_farm().Get_MyThread().Set_upgrade_Yonjehfarm(temp["upgrade_Yonjehfarm time"].toInt());
            p.get_farm().Get_MyThread().Set_Collect_from_YonjehFarm(temp["Collect_from_YonjehFarm time"].toInt());
            p.get_farm().Get_MyThread().Set_Build_YonjehFarm(temp["Build_YonjehFarm time"].toInt());
            p.get_farm().Get_MyThread().Set_Plow_YonjehFarm(temp["Plow_YonjehFarm time"].toInt());
            p.get_farm().get_storage().Get_mikh().Set_Number(temp["Mikh number"].toInt());

            qDebug() << "Mikh Number after reading file" << p.get_farm().get_storage().Get_mikh().Get_Number();

            p.get_farm().get_storage().Get_bill().Set_Number(temp["Bill number"].toInt());
            p.get_farm().get_storage().Get_yonjeh().Set_Number(temp["Yonjeh number"].toInt());
            p.get_farm().get_storage().Get_egg().Set_Number(temp["Egg number"].toInt());
            p.get_farm().get_storage().Get_milk().Set_Number(temp["Milk number"].toInt());
            p.get_farm().get_storage().Get_pashm().Set_Number(temp["Pashm number"].toInt());
            p.get_farm().get_storage().Set_Capacity(temp["Storage capacity"].toInt());
            p.get_farm().get_storage().Set_Bulding_Level(temp["Storage level"].toInt());
            p.get_farm().get_storage().Set_Occupied_Capacity(temp["Storage occupied capacity"].toInt());
            p.get_farm().get_siloo().Get_gandom().Set_Number(temp["Gandom number"].toInt());
            p.get_farm().get_siloo().Set_Capacity(temp["Siloo capacity"].toInt());
            p.get_farm().get_siloo().Set_Bulding_Level(temp["Siloo level"].toInt());
            p.get_farm().get_siloo().Set_Occupied_Capacity(temp["Siloo occupied capacity"].toInt());
            p.get_farm().get_chickenHome().set_capacity(temp["ChickenHome capacity"].toInt());
            p.get_farm().get_chickenHome().set_level_habitat(temp["ChickenHome level"].toInt());
            p.get_farm().get_chickenHome().set_stock_animal(temp["ChickenHome stock"].toInt());
            p.get_farm().get_cowHome().set_capacity(temp["CowHome capacity"].toInt());
            p.get_farm().get_cowHome().set_level_habitat(temp["CowHome level"].toInt());
            p.get_farm().get_cowHome().set_stock_animal(temp["CowHome stock"].toInt());
            p.get_farm().get_sheepHome().set_capacity(temp["SheepHome capacity"].toInt());
            p.get_farm().get_sheepHome().set_level_habitat(temp["SheepHome level"].toInt());
            p.get_farm().get_sheepHome().set_stock_animal(temp["SheepHome stock"].toInt());
            p.get_farm().get_gandomFarm().set_area(temp["GandomFarm area"].toInt());
            p.get_farm().get_gandomFarm().set_level(temp["GandomFarm level"].toInt());
            p.get_farm().get_yonjeFarm().set_area(temp["YonjehFarm area"].toInt());
            p.get_farm().get_yonjeFarm().set_level(temp["YonjehFarm level"].toInt());
            Data::get_players().append(p);


            qDebug() << "Mikh Number after reading file" << p.get_farm().get_storage().Get_mikh().Get_Number();

        }
    }
    f.close();

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
        QMessageBox::warning(this, "تذکر", "نام کاربری و رمز عبور نمی تواند خالی باشد!");
        return;
    }
    for (int i = 0; i < (Data::get_players()).size(); i++)
        if (ui->usernameLE->text() == Data::get_players()[i].get_username()) {
            if (ui->passLE->text() == Data::get_players()[i].get_password()) {
                Data::set_iterator(Data::get_players().begin() + i);
                this->close();

                Data::get_iterator()->get_farm().Get_MyThread().set_first_SizeofMilk(Data::get_iterator()->get_farm().get_storage().Get_milk().Get_Number());
                Data::get_iterator()->get_farm().Get_MyThread().start();

                Data::get_iterator()->get_farm().Show_Farm_Class();
                Data::get_iterator()->get_farm().show();
                return;
            }
            else {
                QMessageBox::warning(this, "تذکر", "رمز عبور اشتباه است!");
                return;
            }
        }
    QMessageBox::warning(this, "تذکر", "نام کاربری یافت نشد!");
}

