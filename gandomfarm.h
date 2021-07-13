#ifndef GANDOMFARM_H
#define GANDOMFARM_H

#include <QWidget>
#include "mainfarm.h"
#include <ctime>



namespace Ui {
class GandomFarm;
}

class GandomFarm : public QWidget
{
    Q_OBJECT

private:

     int area;
     time_t plantingdate;
     int farm_level;
     bool isunderplantingvariable;
     Ui::GandomFarm *ui;


public:
       explicit GandomFarm(QWidget *parent = nullptr,int _area=5);
       void operator=(const GandomFarm& temp);
      ~GandomFarm();
       void set_area(int _area);

       int getarea(void);

       void set_planingdate(time_t _plantingdate);

       time_t get_plantingdate(void);

       void set_level(int _level);

       int get_level(void);

       //bool isunderplanting(void){}

      // bool derokardan(void);

       void planting(int plantingareawant);

       void upgrade();
   ////////////////////////////////////////////////////////////////////////
private slots:
       void on_Back_clicked();
       void on_derokardanpbt_clicked();
       void on_upgradepbt_clicked();
       void on_plantingpbt_clicked();
       void Get_Signal_From_Farm();

signals:
       void Send_Signal_to_Farm();
};

#endif // GANDOMFARM_H
