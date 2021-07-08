#include "Building.h"

Building::Building ()
{
    this->capasity = 0;
    this->building_Level = 0;
    this->occupied_capacity = 0;
}
Building::Building (int _capacity, int _BulidingLevel,int _occupied_capacity)
{
    this->capasity = _capacity;
    this->building_Level = _BulidingLevel;
    this->occupied_capacity = _occupied_capacity;
}

int Building::GetCapasity ()
{
    return this->capasity;
}
void Building::Set_Capacity (int _capasity)
{
    this->capasity = _capasity;
}


int Building::Get_Buliding_Level ()
{
    return this->building_Level;
}
void Building::Set_Bulding_Level (int _BL)
{
    this->building_Level = _BL;
}


int Building::Get_Occupied_Capacity ()
{
    return this->occupied_capacity;
}
void Building::Set_Occupied_Capacity (int _OC)
{
    this->occupied_capacity = _OC;
}






