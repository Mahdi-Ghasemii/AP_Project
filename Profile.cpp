#include "Profile.h"
#include "ui_Profile.h"
#include "Data.h"

Profile::Profile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Profile)
{
    ui->setupUi(this);

    setFixedSize(503,400);

    ui->name_lbl->setText(Data::get_iterator()->get_name());
    ui->username_lbl->setText(Data::get_iterator()->get_username());
    ui->Data_lbl->setText(QString::number((time(NULL)-Data::get_iterator()->get_farm().Get_MyThread().Get_time_login())/(3600*24)));
    ui->level_lbl->setText(QString::number(Data::get_iterator()->get_level()));
    ui->experience_lbl->setText(QString::number(Data::get_iterator()->get_experience()));
}

Profile::~Profile()
{
    delete ui;
}
