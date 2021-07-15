#include "Logo.h"
#include "ui_Logo.h"
#include <QMovie>


Logo::Logo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Logo)
{
    ui->setupUi(this);


    QMovie* movie = new QMovie(":/new/prefix1/Logo.gif");
    ui->label->setMovie(movie);
    movie->start();
}

Logo::~Logo()
{
    delete ui;
}
