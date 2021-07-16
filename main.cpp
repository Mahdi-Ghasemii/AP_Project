#include <QApplication>
#include "Logo.h"
#include "Data.h"
#include "SignIn.h"


QVector<Player>::iterator Data::it;
QVector<Player> Data::players;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Logo logo;
    logo.show();


    return a.exec();
}
