#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

class Product
{
    private:

        int number;

    public:

        Product ();

        int Get_Number ();
        void Set_Number (int _Number);


};

#endif // PRODUCT_H
