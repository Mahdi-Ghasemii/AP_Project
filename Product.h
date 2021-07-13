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
        void operator=(const Product &temp);

        int Get_Number ();
        void Set_Number (int _Number);



};

#endif // PRODUCT_H
