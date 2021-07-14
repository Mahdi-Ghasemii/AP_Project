#include <QApplication>
#include "Logo.h"
#include "Data.h"
QVector<Player>::iterator Data::it;
QVector<Player> Data::players;
//Ranking Farm::ranking;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Logo logo;
    logo.show();

    Player p;

    p.set_name("Mahdi");
    p.set_username("Mahdi");
    p.set_password("Mahdi");


    Data::set_iterator(&p);

    p.get_farm().show();



    return a.exec();
}
