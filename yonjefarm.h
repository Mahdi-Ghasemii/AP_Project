#ifndef YONJE_H
#define YONJE_H
#include "mainfarm.h"

class yonjefarm:public mainfarm
{
private:
   time_t time_shokhm_zadan;
   bool is_plantable;

public:

   yonjefarm();

   bool upgradeyonjefarm(int &_nail ,int &_hoe,int &_coin,time_t &_date,int &_playerlevel,int &experience );

   void planting(int plantingareawant);

};
#endif // YONJE_H
