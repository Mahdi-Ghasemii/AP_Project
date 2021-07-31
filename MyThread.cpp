#include "MyThread.h"
#include "Data.h"

MyThread::MyThread()
{

    time_login = 0;
    upgrade_Storage = 0;
    upgrade_Siloo = 0;


    upgrade_ChickenHome = 0;
    build_ChickenHome = 0;
    collect_Eggs = 0;
    upgrade_CowHome = 0;
    build_CowHome = 0;
    collect_Milks = 0;
    upgrade_SheepHome = 0;
    build_SheepHome = 0;
    correction_Sheeps = 0;
    upgrade_Gandomfarm = 0;
    Collect_from_GandomFarm = 0;
    upgrade_Yonjehfarm = 0;
    Collect_from_YonjehFarm = 0;
    Build_YonjehFarm = 0;
    Plow_YonjehFarm = 0;
}


void MyThread::operator=(const MyThread& temp){

    time_login = temp.time_login;
    upgrade_Storage = temp.upgrade_Storage;
    upgrade_Siloo = temp.upgrade_Siloo;

    buy_Milk.resize(temp.buy_Milk.size());

    for(int i = 0;i< Data::get_iterator()->get_farm().get_storage().Get_milk().Get_Number();i++){
        buy_Milk[i] = temp.buy_Milk[i];
    }
    upgrade_ChickenHome = temp.upgrade_ChickenHome;
    build_ChickenHome = temp.build_ChickenHome;
    collect_Eggs = temp.collect_Eggs;
    upgrade_CowHome = temp.upgrade_CowHome;
    build_CowHome = temp.build_CowHome;
    collect_Milks = temp.collect_Milks;
    upgrade_SheepHome = temp.upgrade_SheepHome;
    build_SheepHome = temp.build_SheepHome;
    correction_Sheeps = temp.correction_Sheeps;
    upgrade_Gandomfarm = temp.upgrade_Gandomfarm;
    Collect_from_GandomFarm = temp.upgrade_Gandomfarm;
    upgrade_Yonjehfarm = temp.upgrade_Gandomfarm;
    Collect_from_YonjehFarm = temp.upgrade_Gandomfarm;
    Build_YonjehFarm = temp.upgrade_Gandomfarm;
    Plow_YonjehFarm = temp.upgrade_Gandomfarm;



}


void MyThread::run()
{

    forever{
    time_t now = time(NULL);
    int number = 0;

   // qDebug() <<"Mahdi Ghasemi";
    if(time_login != 0 && now - time_login >= 3600*24){
        number = (now - time_login)/(3600*24);
        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+number);
        Data::get_iterator()->set_level(Data::get_iterator()->get_level()+number);

        time_login += number* 3600*24;
    }
    if(upgrade_Storage != 0 && now - upgrade_Storage >= 5*3600*24){

        QMessageBox::information(&Data::get_iterator()->get_farm(),"","انبار با موفقیت ارتقا پیدا کرد .:)",QMessageBox::Ok);
        qDebug() << "Aref";
        Data::get_iterator()->get_farm().get_storage().Set_Capacity(round(Data::get_iterator()->get_farm().get_storage().GetCapasity() *3 / 2)+1);
        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience() + Data::get_iterator()->get_farm().get_storage().Get_Buliding_Level() * 3);

        if(Data::get_iterator()->get_experience() >= Data::get_iterator()->get_experience_required_for_levelUp()){
            Data::get_iterator()->set_level(Data::get_iterator()->get_level()+1);

            Data::get_iterator()->set_experience_required_for_levelUp(Data::get_iterator()->get_experience_required_for_levelUp()*2+10);

        }
        upgrade_Storage = 0;


    }

    if(upgrade_Siloo != 0 && now - upgrade_Siloo >= 4*3600*24){

        QMessageBox::information(&Data::get_iterator()->get_farm().get_siloo(),"","سیلو با موفقیت ارتقا پیدا کرد .:)",QMessageBox::Ok);

        Data::get_iterator()->get_farm().get_storage().Set_Capacity(Data::get_iterator()->get_farm().get_storage().GetCapasity() *2);
        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience() + Data::get_iterator()->get_farm().get_storage().Get_Buliding_Level() * 2);

        if(Data::get_iterator()->get_experience() >= Data::get_iterator()->get_experience_required_for_levelUp()){
            Data::get_iterator()->set_level(Data::get_iterator()->get_level()+1);

            Data::get_iterator()->set_experience_required_for_levelUp(Data::get_iterator()->get_experience_required_for_levelUp()*2+10);

        }
        upgrade_Siloo = 0;


    }

    for(int i = 0;i < buy_Milk.size(); i++){

        if (now - buy_Milk[i] >= 10 * 24 *3600 ){
            Data::get_iterator()->get_farm().get_storage().Get_milk().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_milk().Get_Number()-1);
        }
    }


    // Aref
    if(upgrade_CowHome != 0 && now - upgrade_CowHome >= 5*3600*24){
        QMessageBox::information(&Data::get_iterator()->get_farm(),"تبریک","گاوداری با موفقیت ارتقا پیدا کرد",QMessageBox::Ok);
        Data::get_iterator()->get_farm().get_cowHome().set_capacity(Data::get_iterator()->get_farm().get_cowHome().get_capacity() *2);
        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+6);
        if(Data::get_iterator()->get_experience() >= Data::get_iterator()->get_experience_required_for_levelUp()){
            Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
            Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
            QMessageBox::information(&Data::get_iterator()->get_farm(),"تبریک","سطح شما با موفقیت افزایش یافت");
        }
        upgrade_CowHome = 0;
    }

    if(upgrade_ChickenHome != 0 && now - upgrade_ChickenHome >= 3*3600*24){
        QMessageBox::information(&Data::get_iterator()->get_farm(),"تبریک","مرغداری با موفقیت ارتقا پیدا کرد",QMessageBox::Ok);
        Data::get_iterator()->get_farm().get_chickenHome().set_capacity(Data::get_iterator()->get_farm().get_chickenHome().get_capacity() *2);
        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+5);
        if(Data::get_iterator()->get_experience() >= Data::get_iterator()->get_experience_required_for_levelUp()){
            Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
            Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
            QMessageBox::information(&Data::get_iterator()->get_farm(),"تبریک","سطح شما با موفقیت افزایش یافت");
        }
        upgrade_ChickenHome = 0;
    }

    if(upgrade_SheepHome != 0 && now - upgrade_SheepHome >= 9*3600*24){
        QMessageBox::information(&Data::get_iterator()->get_farm(),"تبریک","آغل با موفقیت ارتقا پیدا کرد",QMessageBox::Ok);
        Data::get_iterator()->get_farm().get_sheepHome().set_capacity(Data::get_iterator()->get_farm().get_sheepHome().get_capacity() *2);
        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+15);
        if(Data::get_iterator()->get_experience() >= Data::get_iterator()->get_experience_required_for_levelUp()){
            Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
            Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
            QMessageBox::information(&Data::get_iterator()->get_farm(),"تبریک","سطح شما با موفقیت افزایش یافت");
        }
        upgrade_SheepHome = 0;
    }

    if(build_CowHome != 0 && now - build_CowHome >= 5*3600*24){
        QMessageBox::information(&Data::get_iterator()->get_farm(),"تبریک","گاوداری با موفقیت ساخته شد",QMessageBox::Ok);
        Data::get_iterator()->get_farm().get_cowHome().set_is_build(true);
        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+10);
        if(Data::get_iterator()->get_experience() >= Data::get_iterator()->get_experience_required_for_levelUp()){
            Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
            Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
            QMessageBox::information(&Data::get_iterator()->get_farm(),"تبریک","سطح شما با موفقیت افزایش یافت");
        }
        build_CowHome = 0;
    }




    if(build_ChickenHome != 0 && now - build_ChickenHome >= 3*3600*24){
        QMessageBox::information(&Data::get_iterator()->get_farm(),"تبریک","مرغداری با موفقیت ساخته شد",QMessageBox::Ok);
        Data::get_iterator()->get_farm().get_chickenHome().set_is_build(true);
        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+5);
        if(Data::get_iterator()->get_experience() >= Data::get_iterator()->get_experience_required_for_levelUp()){
            Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
            Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
            QMessageBox::information(&Data::get_iterator()->get_farm(),"تبریک","سطح شما با موفقیت افزایش یافت");
        }
        build_ChickenHome = 0;
    }

    if(build_SheepHome != 0 && now - build_SheepHome >= 10*3600*24){
        QMessageBox::information(&Data::get_iterator()->get_farm(),"تبریک","آغل با موفقیت ساخته شد",QMessageBox::Ok);
        Data::get_iterator()->get_farm().get_sheepHome().set_is_build(true);
        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+20);
        if(Data::get_iterator()->get_experience() >= Data::get_iterator()->get_experience_required_for_levelUp()){
            Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
            Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
            QMessageBox::information(&Data::get_iterator()->get_farm(),"تبریک","سطح شما با موفقیت افزایش یافت");
        }
        build_SheepHome = 0;
    }

    }
}

void MyThread::set_first_SizeofMilk(int size){
    buy_Milk.resize(size);

    for(int i=0;i<size;i++){
        buy_Milk[i] = 0;
    }
}




// set & get functions


void MyThread::Set_time_login(time_t t){
    time_login = t;
}

time_t MyThread::Get_time_login(){
    return time_login;
}

void MyThread::Set_upgrade_Storage(time_t t){
     upgrade_Storage = t;
}

time_t MyThread::Get_upgrade_Storage(){
    return upgrade_Storage;
}

void MyThread::Set_upgrade_Siloo(time_t t){
     upgrade_Siloo = t;
}

time_t MyThread::Get_upgrade_Siloo(){
    return upgrade_Siloo;
}

void MyThread::Push_Back_on_buy_Milk(time_t t){
     buy_Milk.push_back(t);
}


// Aref functions :
void MyThread::Set_upgrade_ChickenHome(time_t t){
     upgrade_ChickenHome = t;
}

time_t MyThread::Get_upgrade_ChickenHome(){
    return upgrade_ChickenHome;
}

void MyThread::Set_build_ChickenHome(time_t t){
     build_ChickenHome = t;
}

time_t MyThread::Get_build_ChickenHome(){
    return build_ChickenHome;
}

void MyThread::Set_collect_Eggs(time_t t){
     collect_Eggs = t;
}

time_t MyThread::Get_collect_Eggs(){
    return collect_Eggs;
}

void MyThread::Set_upgrade_CowHome(time_t t){
    upgrade_CowHome = t;
}

time_t MyThread::Get_upgrade_CowHome(){
    return upgrade_CowHome;
}

void MyThread::Set_build_CowHome(time_t t){
     build_CowHome = t;
}

time_t MyThread::Get_build_CowHome(){
    return build_CowHome;
}

void MyThread::Set_collect_Milks(time_t t){
     collect_Milks = t;
}

time_t MyThread::Get_collect_Milks(){
    return collect_Milks;
}

void MyThread::Set_upgrade_SheepHome(time_t t){
     upgrade_SheepHome = t;
}

time_t MyThread::Get_upgrade_SheepHome(){
    return upgrade_SheepHome;
}

void MyThread::Set_build_SheepHome(time_t t){
     build_SheepHome = t;
}

time_t MyThread::Get_build_SheepHome(){
    return build_SheepHome;
}

void MyThread::Set_correction_Sheeps(time_t t){
    correction_Sheeps = t;
}

time_t MyThread::Get_correction_Sheeps(){
    return correction_Sheeps;
}


// Arsalan functions:
void MyThread::Set_upgrade_Gandomfarm(time_t t){
     upgrade_Gandomfarm = t;
}

time_t MyThread::Get_upgrade_Gandomfarm(){
    return upgrade_Gandomfarm;
}

void MyThread::Set_Collect_from_GandomFarm(time_t t){
     Collect_from_GandomFarm = t;
}

time_t MyThread::Get_Collect_from_GandomFarm(){
    return Collect_from_GandomFarm;
}

void MyThread::Set_upgrade_Yonjehfarm(time_t t){
     upgrade_Yonjehfarm = t;
}

time_t MyThread::Get_upgrade_Yonjehfarm(){
    return upgrade_Yonjehfarm;
}

void MyThread::Set_Collect_from_YonjehFarm(time_t t){
    Collect_from_YonjehFarm = t;
}

time_t MyThread::Get_Collect_from_YonjehFarm(){
    return Collect_from_YonjehFarm;
}

void MyThread::Set_Build_YonjehFarm(time_t t){
    Build_YonjehFarm = t;
}

time_t MyThread::Get_Build_YonjehFarm(){
    return Build_YonjehFarm;
}

void MyThread::Set_Plow_YonjehFarm(time_t t){
    Plow_YonjehFarm = t;
}

time_t MyThread::Get_Plow_YonjehFarm(){
    return Plow_YonjehFarm;
}
