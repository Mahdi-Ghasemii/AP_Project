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
    explicit YonjeFarm(QWidget *parent = nullptr,int _area=4);

    ~YonjeFarm();
// ////////////////////////////////////////////////////////////////
private slots:
       void on_planting_clicked();
       void on_upgradebutton_clicked();
       void on_derokardan_clicked();
       void on_shokhmzadan_clicked();
       void on_Back_clicked();
   ////////////////////////////////////////////////////////////////////
public:
       int getarea(void);

       void set_planingdate(time_t _plantingdate);

       time_t get_plantingdate(void);

       void set_level(int _level);

       int get_level(void);

       //bool isunderplanting(void){}

       //bool derokardan(void);

       //void planting(int plantingareawant);
       void set_area(int _area);
////////////////////////////////////////////////////////////////////////


private:
    Ui::YonjeFarm *ui;

    time_t time_shokhm_zadan;

    ////////////////////////////
    int area;
    time_t plantingdate;
    int farm_level;
    bool isunderplantingvariable;
    ////////////////////////////
     bool is_plantable;






};


#endif // YONJEFARM_H
