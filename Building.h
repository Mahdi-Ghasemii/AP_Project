#ifndef BUILDING_H
#define BUILDING_H

class Building
{
    protected:

        int capasity;
        int building_Level;
        int occupied_capacity;

    public:

        Building ();
        void operator=(const Building & temp);

        int GetCapasity ();
        void Set_Capacity (int _capasity);

        int Get_Buliding_Level ();
        void Set_Bulding_Level (int _BL);

        int Get_Occupied_Capacity ();
        void Set_Occupied_Capacity (int _OC);


};

#endif // BUILDING_H
