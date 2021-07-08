#include "mainfarm.h"


MainFarm::MainFarm(){ }
void MainFarm:: set_area(int _area){area=_area;}

int MainFarm:: getarea(void){return area;}

void MainFarm::set_planingdate(time_t _plantingdate){plantingdate=_plantingdate;}

time_t MainFarm::get_plantingdate(void){return plantingdate;}

void MainFarm::set_level(int _level){level=_level;}

int MainFarm::get_level(void){return level;}

//bool isunderplanting(void){}

bool MainFarm::derokardan(void){}

void MainFarm::planting(int plantingareawant){}
