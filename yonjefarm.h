#ifndef YONJEFARM_H
#define YONJEFARM_H
#include <ctime>
#include <QWidget>
#include "mainfarm.h"
#include "MyThread.h"


namespace Ui {
class YonjeFarm;
}

class YonjeFarm : public QWidget
{
    Q_OBJECT


private:
    Ui::YonjeFarm *ui;

    int area;
    time_t time_shokhm_zadan;
    time_t plantingdate;
    int farm_level;
    bool isunderplantingvariable;
    bool is_plantable;
    bool is_biuld;
    // /////////////////////////////////////////////////////////////
public:
    void build(void);
    bool get_is_build();
    void set_is_build(bool _is_build);
    explicit YonjeFarm(QWidget *parent = nullptr,int _area=4,int _farm_level=1,bool _is_plantable=false,bool is_underplanting=false,bool _is_biuld=false);
    void operator=(const YonjeFarm& temp);
    ~YonjeFarm();

     int getarea(void);

     void set_planingdate(time_t _plantingdate);

     time_t get_plantingdate(void);

     void set_level(int _level);

     int get_level(void);
     bool get_is_plantable(void);
     void set_is_plantable(bool _is_plantable);
     //bool isunderplanting(void){}

     //bool derokardan(void);

     //void planting(int plantingareawant);
     void set_area(int _area);
////////////////////////////////////////////////////////////////////////
private slots:
       void on_planting_clicked();
       void on_upgradebutton_clicked();
       void on_derokardan_clicked();
       void on_shokhmzadan_clicked();
       void on_Back_clicked();
       void Get_Signal_From_Farm();

signals:
       void Send_Signal_to_Farm();

};


#endif // YONJEFARM_H
