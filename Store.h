#ifndef STORE_H
#define STORE_H

#include <QWidget>
#include "Product.h"
#include <QMainWindow>

namespace Ui {
class Store;
}

class Store : public QMainWindow
{
    Q_OBJECT

private:
    Ui::Store *ui;

public:


        explicit Store(QWidget *parent = nullptr);
        ~Store();



private slots:

    void on_Return_to_Farm_clicked();

    void on_Buy_Gandom_pbn_clicked();
    void on_Sell_Gandom_pbn_clicked();
    void on_Buy_Yonjeh_pbn_clicked();
    void on_Sell_Yonjeh_pbn_clicked();
    void on_Buy_Cow_pbn_clicked();
    void on_Sell_Cow_pbn_clicked();
    void on_Buy_Sheep_pbn_clicked();
    void on_Sell_Sheep_pbn_clicked();
    void on_Buy_Chicken_pbn_clicked();
    void on_Sell_Chicken_pbn_clicked();
    void on_Sell_Milk_pbn_clicked();
    void on_Sell_Wool_pbn_clicked();
    void on_Sell_Egg_pbn_clicked();
    void on_Buy_Bill_pbn_clicked();
    void on_Sell_Bill_pbn_clicked();
    void on_Buy_Mikh_pbn_clicked();
    void on_Sell_Mikh_pbn_clicked();

    void Get_Signal_From_Farm(int _Num_Coin,int _Level , int _Experience ,int Num_Gandom,int Num_Yonjeh ,int Num_Milk ,int Num_Mikh ,int Num_Bill ,int Num_Wool ,int Num_Egg);

signals:
    void Send_Signal_to_Farm(int _Num_Coin , int _Level , int _Experience ,int Num_Gandom,int Num_Yonjeh ,int Num_Milk ,int Num_Mikh ,int Num_Bill ,int Num_Wool ,int Num_Egg);
};

#endif // STORE_H
