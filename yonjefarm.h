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

       void on_upgradebutton_clicked();

private:
    Ui::YonjeFarm *ui;

    time_t time_shokhm_zadan;
<<<<<<< HEAD
      bool is_plantable;
      int areawanted;
=======
    bool is_plantable;

>>>>>>> db269b9999aada6e9cfbd77eb2994121f5b8b7f3

};

#endif // YONJEFARM_H
