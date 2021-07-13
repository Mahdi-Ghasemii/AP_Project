#include "Product.h"

Product::Product ()
{
    this->number = 0;

}


void Product::operator=(const Product &temp){

    this->number = temp.number;

}
int Product::Get_Number ()
{
    return this->number;
}

void Product::Set_Number (int _number)
{
    this->number = _number;
}


