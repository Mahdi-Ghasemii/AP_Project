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
#include "MyThread.h"

namespace Ui {
class Farm;
}

class Farm : public QMainWindow
{
    Q_OBJECT

public:
    explicit Farm(QWidget *parent = nullptr);
    void operator=(const Farm&);
    ~Farm();

    Storage& get_storage();
    Store& get_store();
    Siloo& get_siloo();
    Ranking& get_ranking();
    ChickenHome& get_chickenHome();
    CowHome& get_cowHome();
    SheepHome& get_sheepHome();
    YonjeFarm& get_yonjeFarm();
    GandomFarm& get_gandomFarm();

    MyThread& Get_MyThread();



private slots:

    void get_signal_from_builting_for_YonjeFarm(QString);

    void get_signal_from_builting_for_chickenHome(QString);
    void get_signal_from_builting_for_cowHome(QString);
    void get_signal_from_builting_for_sheepHome(QString);
    void on_Storage_pbn_clicked();
    void on_Siloo_pbn_clicked();
    void on_YonjehFarm_pbn_clicked();
    void on_GandomFarm_pbn_clicked();
    void on_SheepHome_pbn_clicked();
    void on_ChickenHome_pbn_clicked();
    void on_CowHome_pbn_clicked();

    // Slots to comunicate with other classes



    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void On_ExitAction_triggred();
    void On_ProfileAction_triggred();

public slots:

    void Global_Func_to_Set_ui_Attributes();
    void Set_UI_Attributes1_for_set_time_login();
    void Set_UI_Attributes_for_upgrade_storage();
    void Set_UI_Attributes1_for_upgrade_siloo();

    void Set_UI_Attributes1_for_upgrade_chickenHome();
    void Set_UI_Attributes1_for_upgrade_cowHome();
    void Set_UI_Attributes1_for_upgrade_sheepHome();
    void Set_UI_Attributes1_for_build_chickenHome();
    void Set_UI_Attributes1_for_build_cowHome();
    void Set_UI_Attributes1_for_build_sheepHome();

    void Set_UI_Attributes1_for_build_yonjeFarm();
    void Set_UI_Attributes1_for_upgrade_yonjeFarm();
    void Set_UI_Attributes1_for_upgrade_gandomFarm();
    void Set_UI_Attributes1_for_plow_yonjeFarm();





    void Show_Farm_Class();
signals:


    // Signals to comunicate with other classes

    void Send_Signal_to_Store();
    void Send_Signal_to_Storage();
    void Send_Signal_to_Siloo();
    void Send_Signal_to_Ranking();

    void Send_Signal_to_Gandomfarm();
    void Send_Signal_to_Yonjefarm();

    void Send_Signal_to_SheepHome();
    void Send_Signal_to_CowHome();
    void Send_Signal_to_ChickenHome();


private:
    Ui::Farm *ui;

    Storage storage;
    Store store;
    Siloo siloo;
    Ranking ranking;
    ChickenHome chickenHome;
    CowHome cowHome;
    SheepHome sheepHome;
    YonjeFarm yonjeFarm;
    GandomFarm gandomFarm;
    MyThread myThread;
};

#endif // FARM_H
