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

    return a.exec();
}
