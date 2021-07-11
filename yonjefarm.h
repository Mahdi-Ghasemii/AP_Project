#ifndef YONJEFARM_H
#define YONJEFARM_H
#include <ctime>
#include <QWidget>
#include "mainfarm.h"

namespace Ui {
class YonjeFarm;
}

class YonjeFarm : public QWidget , public MainFarm
{
    Q_OBJECT

public:
    explicit YonjeFarm(QWidget *parent = nullptr);

    YonjeFarm(int _area=5);

       bool upgradeyonjefarm(int &_nail ,int &_hoe,int &_coin,time_t &_date,int &_playerlevel,int &experience );

       void planting(int plantingareawant);


    ~YonjeFarm();

private slots:
       void on_planting_clicked();
       void plantingareawanted(int _area);
       void on_pushButton_3_clicked();

private:
    Ui::YonjeFarm *ui;

    time_t time_shokhm_zadan;
      bool is_plantable;
      int areawanted;

};

#endif // YONJEFARM_H
