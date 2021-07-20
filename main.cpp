#include <QApplication>
#include "Logo.h"
#include "Data.h"
#include "SignIn.h"
//#include <windows.h>
//#include <mmsystem.h>


QVector<Player>::iterator Data::it;
QVector<Player> Data::players;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     //std::PlaySound("");
    Logo logo;
    logo.show();


    return a.exec();
}
