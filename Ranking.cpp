#include "Ranking.h"
#include "ui_Ranking.h"

Ranking::Ranking(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ranking)
{
    ui->setupUi(this);
}

Ranking::~Ranking()
{
    delete ui;
}
