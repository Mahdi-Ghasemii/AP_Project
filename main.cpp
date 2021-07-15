#include <QApplication>
#include "Logo.h"
#include "Data.h"
#include "SignIn.h"


QVector<Player>::iterator Data::it;
QVector<Player> Data::players;
//Ranking Farm::ranking;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Logo logo;
    logo.show();
    _sleep(3000);
    logo.close();
    SignIn signin;
    signin.show();

    return a.exec();
}
