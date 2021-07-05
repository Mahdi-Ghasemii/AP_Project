#ifndef FARMHA_H
#define FARMHA_H
#include <ctime>
////////////////////////////////////////////////////////////////////////////////////////////
class mainfarm
{
protected:
    int area;
    time_t plantingdate;
    int level;
    bool isunderplantingvariable;

public:

    mainfarm();
    void set_area(int _area);

    int getarea(void);

    void set_planingdate(time_t _plantingdate);

    time_t get_plantingdate(void);

    void set_level(int _level);

    int get_level(void);

    //bool isunderplanting(void){}

    bool derokardan(void);

    void planting(int plantingareawant);

};

#endif // FARMHA_H
