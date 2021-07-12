#ifndef YONJEFARM_H
#define YONJEFARM_H
#include <ctime>
#include <QWidget>
#include "mainfarm.h"

namespace Ui {
class YonjeFarm;
}

class YonjeFarm : public QWidget
{
    Q_OBJECT

public:
    explicit YonjeFarm(QWidget *parent = nullptr);

    YonjeFarm(int _area=4);

       bool upgradeyonjefarm(int &_nail ,int &_hoe,int &_coin,time_t &_date,int &_playerlevel,int &experience );

       void planting(int plantingareawant);


    ~YonjeFarm();

private slots:
       void on_planting_clicked();
       void plantingareawanted(int _area);
       void on_pushButton_3_clicked();
       void on_upgradebutton_clicked();
       void set_area(int _area);
   ////////////////////////////////////////////////////////////////////
       int getarea(void);

       void set_planingdate(time_t _plantingdate);

       time_t get_plantingdate(void);

       void set_level(int _level);

       int get_level(void);

       //bool isunderplanting(void){}

       bool derokardan(void);

      // void planting(int plantingareawant);

       void upgrade();

////////////////////////////////////////////////////////////////////////
       void on_derokardan_clicked();

private:
    Ui::YonjeFarm *ui;

    time_t time_shokhm_zadan;
<<<<<<< HEAD
    ////////////////////////////
    int area;
    time_t plantingdate;
    int farm_level;
    bool isunderplantingvariable;
    ////////////////////////////
      bool is_plantable;
      int areawanted;


=======
    bool is_plantable;
>>>>>>> c3276557bcbf5916ef883f6b08881e841175b3fe


};

#endif // YONJEFARM_H
