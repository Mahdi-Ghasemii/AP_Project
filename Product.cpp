#include "Product.h"

Product::Product ()
{
    type = "";
    this->price_to_Buy = 0;
    this->price_to_sell = 0;
    this->increase_amount_experience = 0;
    this->required_level = 0;
    this->number = 0;

}

int Product::Get_Price_to_Buy ()
{
    return price_to_Buy;
}
void Product::Set_Price_to_Buy (int _price_to_Buy)
{
    this->price_to_Buy = _price_to_Buy;
}


int Product::Get_Increase_Amount_Experience ()
{
    return increase_amount_experience;
}
void Product::Set_Increase_Amount_Experience (int _increase_Amount_Experience)
{
    this->increase_amount_experience = _increase_Amount_Experience;
}


int Product::Get_Required_Level ()
{
    return required_level;
}
void Product::Set_Required_Level (int _required_Level)
{
    this->required_level = _required_Level;
}


int Product::Get_Price_to_Sell ()
{
    return price_to_sell;
}
void Product::Set_Price_to_Sell (int _price_to_Sell)
{
    this->price_to_sell = _price_to_Sell;
}


string Product::GetType ()
{
    return this->type;
}
void Product::Set_Type (string _type)
{
    this->type = _type;

    if(_type == "gandom"){

        this->price_to_Buy = 3;
        this->price_to_sell = 2;
        this->increase_amount_experience = 1;
        this->required_level = 1;

    }
    else if(_type == "yonjeh"){

        this->price_to_Buy = 6;
        this->price_to_sell = 4;
        this->increase_amount_experience = 2;
        this->required_level = 3;

    }
    else if(_type == "chicken"){

        this->price_to_Buy = 20;
        this->price_to_sell = 15;
        this->increase_amount_experience = 5;
        this->required_level = 2;

    }
    else if(_type == "egg"){

        this->price_to_Buy = 0;
        this->price_to_sell = 8;
        this->increase_amount_experience = 3;
        this->required_level = 2;

    }
    else if(_type == "cow"){

        this->price_to_Buy = 70;
        this->price_to_sell = 50;
        this->increase_amount_experience = 10;
        this->required_level = 4;

    }
    else if(_type == "milk"){

        this->price_to_Buy = 0;
        this->price_to_sell = 12;
        this->increase_amount_experience = 5;
        this->required_level = 4;

    }
    else if(_type == "sheep"){

        this->price_to_Buy = 80;
        this->price_to_sell = 70;
        this->increase_amount_experience = 15;
        this->required_level = 6;
    }
    else if(_type == "mikh"){

        this->price_to_Buy = 30;
        this->price_to_sell = 20;
        this->increase_amount_experience = 4;
        this->required_level = 1;
    }
    else if(_type == "bill"){

        this->price_to_Buy = 50;
        this->price_to_sell = 30;
        this->increase_amount_experience = 8;
        this->required_level = 1;
    }

}


int Product::Get_Number ()
{
    return this->number;
}
void Product::Set_Number (int _number)
{
    this->number = _number;
}














