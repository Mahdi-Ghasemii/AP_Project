#include <QApplication>
#include "Logo.h"
#include "Data.h"
#include "SignIn.h"

#define DEBUG
#ifdef DEBUG
#include <QVector>
#endif

//#include <windows.h>
QVector<Player>::iterator Data::it;
QVector<Player> Data::players;
//Ranking Farm::ranking;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#ifdef DEBUG
    QVector<Player> v;
    Player p;
    v.append(p);
#endif
    Logo logo;
    logo.show();
    _sleep(3000);
    logo.close();
    SignIn signin;
    signin.show();

    return a.exec();
}
