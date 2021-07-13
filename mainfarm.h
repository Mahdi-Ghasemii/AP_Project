#ifndef MAINFARM_H
#define MAINFARM_H
#include <ctime>

class MainFarm
{
protected:
    int area;
    time_t plantingdate;
    int farm_level;
    bool isunderplantingvariable;

public:

    MainFarm();
    void set_area(int _area);

    int getarea(void);

    void set_planingdate(time_t _plantingdate);

    time_t get_plantingdate(void);

    void set_level(int _level);

    int get_level(void);

    //bool isunderplanting(void){}

   // bool derokardan(void);

    //void planting(int plantingareawant);

};

#endif // MAINFARM_H
