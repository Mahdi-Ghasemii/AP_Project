#ifndef GANDOM_H
#define GANDOM_H
#include "mainfarm.h"

class gandomfarm :public mainfarm
{

public:

   gandomfarm();

   bool upgradegandomfarm(int &_nail ,int &_hoe,int &_coin,time_t &_date,int &_playerlevel,int &experience );
   void planting(int plantingareawant);

};
#endif // GANDOM_H
