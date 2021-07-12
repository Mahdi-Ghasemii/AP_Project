<<<<<<< HEAD
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
};

#endif // STORE_H
=======
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
};

#endif // STORE_H
>>>>>>> c3276557bcbf5916ef883f6b08881e841175b3fe
