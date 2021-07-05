#include "mainfarm.h"



mainfarm::mainfarm(){ }
void mainfarm:: set_area(int _area){area=_area;}

int mainfarm:: getarea(void){return area;}

void mainfarm::set_planingdate(time_t _plantingdate){plantingdate=_plantingdate;}

time_t mainfarm::get_plantingdate(void){return plantingdate;}

void mainfarm::set_level(int _level){level=_level;}

int mainfarm::get_level(void){return level;}

//bool isunderplanting(void){}

bool mainfarm::derokardan(void){}

void mainfarm::planting(int plantingareawant){}
