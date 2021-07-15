#ifndef DATA_H
#define DATA_H

#include <QVector>
#include "Player.h"
#include <fstream>
#include <iostream>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>


using namespace std;


class Data
{
private:
    static QVector<Player>::iterator it;
    static QVector<Player> players;

public:
    static void set_iterator(QVector<Player>::iterator _it){ it=_it; }

    static QVector<Player>::iterator& get_iterator(){ return it; }

    static void set_players(QVector<Player>& _players){ players=_players; }

    static QVector<Player>& get_players() { return players; }


    static void write_on_file() {
        QFile f("Players.json");
        f.open(QIODevice::ReadWrite);
        QJsonDocument d = QJsonDocument::fromJson(f.readAll());
        QJsonObject o = d.object();
        QJsonObject temp = o[get_iterator()->get_username()].toObject();
        temp["Name"] = get_iterator()->get_name();
        temp["Username"] = get_iterator()->get_username();
        temp["Password"] = get_iterator()->get_password();
        temp["Email"] = get_iterator()->get_email();
        temp["Coin"] = get_iterator()->get_coin();
        temp["Level"] = get_iterator()->get_level();
        temp["Experience"] = get_iterator()->get_experience();
        temp["Experience required for levelUp"] = get_iterator()->get_experience_required_for_levelUp();
        //temp["SignUp time]
        temp["Mikh number"] = get_iterator()->get_farm().get_storage().Get_mikh().Get_Number();
        temp["Bill number"] = get_iterator()->get_farm().get_storage().Get_bill().Get_Number();
        temp["Yonjeh number"] = get_iterator()->get_farm().get_storage().Get_yonjeh().Get_Number();
        temp["Egg number"] = get_iterator()->get_farm().get_storage().Get_egg().Get_Number();
        temp["Milk number"] = get_iterator()->get_farm().get_storage().Get_milk().Get_Number();
        temp["Pashm number"] = get_iterator()->get_farm().get_storage().Get_pashm().Get_Number();
        temp["Storage capacity"] = get_iterator()->get_farm().get_storage().GetCapasity();
        temp["Storage level"] = get_iterator()->get_farm().get_storage().Get_Buliding_Level();
        temp["Storage occupied capacity"] = get_iterator()->get_farm().get_storage().Get_Occupied_Capacity();
        temp["Gandom number"] = get_iterator()->get_farm().get_siloo().Get_gandom().Get_Number();
        temp["Siloo capacity"] = get_iterator()->get_farm().get_siloo().GetCapasity();
        temp["Siloo level"] = get_iterator()->get_farm().get_siloo().Get_Buliding_Level();
        temp["Siloo occupied capacity"] = get_iterator()->get_farm().get_siloo().Get_Occupied_Capacity();
        temp["ChickenHome capacity"] = get_iterator()->get_farm().get_chickenHome().get_capacity();
        temp["ChickenHome level"] = get_iterator()->get_farm().get_chickenHome().get_level_habitat();
        temp["ChickenHome stock"] = get_iterator()->get_farm().get_chickenHome().get_stock_animal();
        temp["CowHome capacity"] = get_iterator()->get_farm().get_cowHome().get_capacity();
        temp["CowHome level"] = get_iterator()->get_farm().get_cowHome().get_level_habitat();
        temp["CowHome stock"] = get_iterator()->get_farm().get_cowHome().get_stock_animal();
        temp["SheepHome capacity"] = get_iterator()->get_farm().get_sheepHome().get_capacity();
        temp["SheepHome level"] = get_iterator()->get_farm().get_sheepHome().get_level_habitat();
        temp["SheepHome stock"] = get_iterator()->get_farm().get_sheepHome().get_stock_animal();
        temp["GandomFarm area"] = get_iterator()->get_farm().get_gandomFarm().getarea();
        temp["GandomFarm level"] = get_iterator()->get_farm().get_gandomFarm().get_level();
        temp["YonjehFarm area"] = get_iterator()->get_farm().get_yonjeFarm().getarea();
        temp["YonjehFarm level"] = get_iterator()->get_farm().get_yonjeFarm().get_level();
        o[get_iterator()->get_username()] = temp;
        d.setObject(o);
        f.write(d.toJson());
        f.close();
    }
};

#endif // DATA_H
