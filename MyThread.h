#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <time.h>
#include <QVector>


class MyThread : public QThread
{
public:
    MyThread();
    void operator=(const MyThread& temp);
    void run();

    void set_first_SizeofMilk(int size);

    // my functions :
    void Set_time_login(time_t t);
    time_t Get_time_login();
    void Set_last_time_set(time_t t);
    time_t Get_last_time_set();
    void Set_upgrade_Storage(time_t t);
    time_t Get_upgrade_Storage();
    void Set_upgrade_Siloo(time_t t);
    time_t Get_upgrade_Siloo();
    void Push_Back_on_buy_Milk(time_t t);


    // Aref functions :
    void Set_upgrade_ChickenHome(time_t t);
    time_t Get_upgrade_ChickenHome();
    void Set_build_ChickenHome(time_t t);
    time_t Get_build_ChickenHome();
    void Set_feed_time_chicken(time_t t);
    time_t Get_feed_time_chicken();
    void Set_upgrade_CowHome(time_t t);
    time_t Get_upgrade_CowHome();
    void Set_build_CowHome(time_t t);
    time_t Get_build_CowHome();
    void Set_feed_time_cow(time_t t);
    time_t Get_feed_time_cow();
    void Set_upgrade_SheepHome(time_t t);
    time_t Get_upgrade_SheepHome();
    void Set_build_SheepHome(time_t t);
    time_t Get_build_SheepHome();
    void Set_feed_time_sheep(time_t t);
    time_t Get_feed_time_sheep();


    // Arsalan functions:
    void Set_planting_Gandomfarm(time_t t);
    time_t Get_planting_Gandomfarm();

    void Set_upgrade_Gandomfarm(time_t t);
    time_t Get_upgrade_Gandomfarm();
    // ////////////////////////////////////
    void Set_planting_YonjeFarm(time_t t);
    time_t Get_planting_YonjeFarm();

    void Set_Collect_from_GandomFarm(time_t t);
    time_t Get_Collect_from_GandomFarm();

    void Set_upgrade_Yonjehfarm(time_t t);
    time_t Get_upgrade_Yonjehfarm();

    void Set_Collect_from_YonjehFarm(time_t t);
    time_t Get_Collect_from_YonjehFarm();

    void Set_Build_YonjehFarm(time_t t);
    time_t Get_Build_YonjehFarm();

    void Set_Plow_YonjehFarm(time_t t);
    time_t Get_Plow_YonjehFarm();




private:

    time_t time_login;
    time_t last_time_set;
    //  Storage & siloo
    time_t upgrade_Storage;
    time_t upgrade_Siloo;
    QVector<time_t> buy_Milk;

    // ChickenHome classes :
    time_t upgrade_ChickenHome;
    time_t build_ChickenHome;
    time_t feed_time_chicken;
    // CowHome classes :
    time_t upgrade_CowHome;
    time_t build_CowHome;
    time_t feed_time_cow;
    // SheepHome classes :
    time_t upgrade_SheepHome;
    time_t build_SheepHome;
    time_t feed_time_sheep;

    // YonjehFarm & GandomFarm :

    // GandomFarm :
    time_t upgrade_Gandomfarm;
    time_t Collect_from_GandomFarm;
    time_t Planting_from_GandomFarm;

    // YonjehFarm :
    time_t Planting_from_YonjeFarm;
    time_t upgrade_Yonjehfarm;
    time_t Collect_from_YonjehFarm;
    time_t Build_YonjehFarm;
    time_t Plow_YonjehFarm;

};

#endif // MYTHREAD_H
