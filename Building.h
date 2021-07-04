
class Building
{
    protected:

        int capasity;
        int buliding_Level;
        int occupied_capacity;

    public:

        Building ();
        Building (int _capacity,int _building_Level,int _occupied_capacity);

        int GetCapasity ();
        void Set_Capacity (int _capasity);

        int Get_Buliding_Level ();
        void Set_Bulding_Level (int _BL);

        int Get_Occupied_Capacity ();
        void Set_Occupied_Capacity (int _OC);

};
