#include <string>

using namespace std;

class Product
{
    private:

        string type;
        int price_to_Buy;
        int price_to_sell;
        int increase_amount_experience;
        int required_level;
        int number;

    public:

        Product ();

        string GetType ();
        void Set_Type (string _type);

        int Get_Price_to_Buy ();
        void Set_Price_to_Buy (int _Price_to_Buy);

        int Get_Price_to_Sell ();
        void Set_Price_to_Sell (int _Price_to_Sell);

        int Get_Increase_Amount_Experience ();
        void Set_Increase_Amount_Experience (int _Increase_Amount_Experience);

        int Get_Required_Level ();
        void Set_Required_Level (int _Required_Level);

        int Get_Number ();
        void Set_Number (int _Number);


};
