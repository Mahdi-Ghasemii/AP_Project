#ifndef GANDOMFARM_H
#define GANDOMFARM_H

#include <QWidget>
#include "mainfarm.h"
#include <ctime>



namespace Ui {
class GandomFarm;
}

class GandomFarm : public QWidget , public MainFarm
{
    Q_OBJECT

public:
    explicit GandomFarm(QWidget *parent = nullptr);


    GandomFarm();
       bool upgradegandomfarm(int &_nail ,int &_hoe,int &_coin,time_t &_date,int &_playerlevel,int &experience );
       void planting(int plantingareawant);


    ~GandomFarm();

private slots:
       void on_pushButton_2_clicked();
       void plantingareawanted(int _area);
       void on_pushButton_5_clicked();

private:
     int areawanted;
    Ui::GandomFarm *ui;
};

#endif // GANDOMFARM_H
