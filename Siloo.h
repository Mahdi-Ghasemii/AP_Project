#include "Product.h"
#include "Building.h"

using namespace std;

class Siloo :  public Building
{
    private:
        Product gandom;

    public:

        Siloo ();
        Product Get_gandom ();
        void Set_Gandom (Product _gandom);

        void Increase_Capacity ();
        void Check_Siloos_Product ();

};
