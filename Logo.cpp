#include "Logo.h"
#include "ui_Logo.h"
#include "SignIn.h"


Logo::Logo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Logo)
{
    ui->setupUi(this);
    _sleep(3000);
    this->close();
    SignIn* si = new SignIn();
    si->show();
}

Logo::~Logo()
{
    delete ui;
}
