#include <QApplication>
#include "Logo.h"
#include "Data.h"
QList<Player>::iterator Data::it;
QList<Player> Data::players;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Logo logo;
    logo.show();

    return a.exec();
}
