#include "Logo.h"
#include "ui_Logo.h"
#include "SignIn.h"


Logo::Logo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Logo)
{
    ui->setupUi(this);
}

Logo::~Logo()
{
    delete ui;
}
