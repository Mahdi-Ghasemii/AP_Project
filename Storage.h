#include "Product.h"
#include "Building.h"

using namespace std;

class Storage :  public Building
{
    private:

        Product yonjeh;
        Product bill;
        Product mikh;
        Product egg;
        Product milk;
        Product pashm;
        time_t time_add_milk;

    public:

        Storage ();

        Product Get_bill ();
        void Set_bill (Product _bill);
        Product Get_mikh ();
        void Set_Mikh (Product _mikh);
        Product Get_yonjeh ();
        void Set_Yonjeh (Product _yonjeh);
        Product Get_egg ();
        void Set_Egg (Product _egg);
        Product Get_milk ();
        void Set_Milk (Product _milk);
        Product Get_pashm ();
        void Set_Pashm (Product _pashm);


        void Increase_Capasity ();
        void Check_Storages_Product ();

};
