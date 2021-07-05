
#include <QApplication>
#include "Logo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Logo logo;
    logo.show();

    return a.exec();
}
