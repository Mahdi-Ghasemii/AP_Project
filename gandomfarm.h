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

public:
    explicit GandomFarm(QWidget *parent = nullptr);


    GandomFarm( int _area=5);




    ~GandomFarm();

private slots:
       void on_pushButton_2_clicked();
       void plantingareawanted(int _area);
       void on_pushButton_5_clicked();
///////////////////////////////////////////////////////////////
       void set_area(int _area);

       int getarea(void);

       void set_planingdate(time_t _plantingdate);

       time_t get_plantingdate(void);

       void set_level(int _level);

       int get_level(void);

       //bool isunderplanting(void){}

       bool derokardan(void);

       void planting(int plantingareawant);

       void upgrade();
   ////////////////////////////////////////////////////////////////////////
       void on_pushButton_4_clicked();

       void on_upgradepbt_clicked();

       void on_plantingpbt_clicked();

       void on_derokardan_clicked();

       void on_derokardanpbt_clicked();

       void on_Back_clicked();

private:


     ///////////////////
     int area;
     time_t plantingdate;
     int farm_level;
     bool isunderplantingvariable;
     //////////////////////////
    Ui::GandomFarm *ui;
};

#endif // GANDOMFARM_H
