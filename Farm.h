#ifndef FARM_H
#define FARM_H

#include <QMainWindow>
#include "Storage.h"
#include "Store.h"
#include "Siloo.h"
#include "Habitat.h"
#include "gandomfarm.h"
#include "yonjefarm.h"
#include "Ranking.h"
#include "ChickenHome.h"
#include "CowHome.h"
#include "SheepHome.h"

namespace Ui {
class Farm;
}

class Farm : public QMainWindow
{
    Q_OBJECT

public:
    explicit Farm(QWidget *parent = nullptr);
    ~Farm();

    Storage& get_storage();
    Store& get_store();
    Siloo& get_siloo();
    Ranking& get_ranking();
    ChickenHome& get_chickenHome();
    CowHome& get_cowHome();
    SheepHome& get_sheepHome();
    void operator=(const Farm&);


private slots:



    void on_Storage_pbn_clicked();
    void on_Siloo_pbn_clicked();
    void on_YonjehFarm_pbn_clicked();
    void on_GandomFarm_pbn_clicked();
    void on_SheepHome_pbn_clicked();
    void on_ChickenHome_pbn_clicked();
    void on_CowHome_pbn_clicked();

    // Slots to comunicate with other classes

    void Show_Farm_Class();


signals:


    // Signals to comunicate with other classes

    void Send_Signal_to_Store();
    void Send_Signal_to_Storage();
    void Send_Signal_to_Siloo();
    void Send_Signal_to_Ranking();

private:
    Ui::Farm *ui;

    Storage storage;
    Store store;
    Siloo siloo;
    static Ranking ranking;
    ChickenHome chickenHome;
    CowHome cowHome;
    SheepHome sheepHome;
    YonjeFarm yonjeFarm;
    GandomFarm gandomFarm;
};

#endif // FARM_H
