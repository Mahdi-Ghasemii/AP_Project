#include "SignIn.h"
#include "ui_SignIn.h"
#include "SignUp.h"
#include <fstream>
#include <QMessageBox>

using namespace std;


SignIn::SignIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignIn)
{
    ui->setupUi(this);

    QPixmap qpm("C:/Users/TAD BIR RAYANEH/Desktop/test files for ap project/92-Picture-Blur-Nature-500x281.png");
    qpm = qpm.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette qp;
    qp.setBrush(QPalette::Window, qpm);
    this->setPalette(qp);

    QFile f("Players.json");
    f.open(QIODevice::ReadOnly);
    if (f.isOpen()) {
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
            //p.set_signUp_time(temp["SignUp time"].toString());
            p.get_farm().get_storage().Get_mikh().Set_Number(temp["Mikh number"].toInt());
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

