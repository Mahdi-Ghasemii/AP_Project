#include "MyThread.h"
#include "Data.h"
#include "Farm.h"
MyThread::MyThread()
{

    time_login = time(NULL);
    last_time_set=time(NULL);
    upgrade_Storage = 0;
    upgrade_Siloo = 0;


    upgrade_ChickenHome = 0;
    build_ChickenHome = 0;
    feed_time_chicken = 0;
    upgrade_CowHome = 0;
    build_CowHome = 0;
    feed_time_cow = 0;
    upgrade_SheepHome = 0;
    build_SheepHome = 0;
    feed_time_sheep = 0;
    upgrade_Gandomfarm = 0;
    Collect_from_GandomFarm = 0;
    upgrade_Yonjehfarm = 0;
    Collect_from_YonjehFarm = 0;
    Build_YonjehFarm = 0;
    Plow_YonjehFarm = 0;
    // // // //
    Planting_from_GandomFarm=0;
    Planting_from_YonjeFarm=0;

  //  connect(this,SIGNAL(Send_Signal_to_Farm1()),&(Data::get_iterator()->get_farm()),SLOT(Set_UI_Attributes()));

}


void MyThread::operator=(const MyThread& temp){

    time_login = temp.time_login;
    last_time_set=temp.last_time_set;
    upgrade_Storage = temp.upgrade_Storage;
    upgrade_Siloo = temp.upgrade_Siloo;

    buy_Milk.resize(temp.buy_Milk.size());

    for(int i = 0;i< Data::get_iterator()->get_farm().get_storage().Get_milk().Get_Number();i++){
        buy_Milk[i] = temp.buy_Milk[i];
    }
    upgrade_ChickenHome = temp.upgrade_ChickenHome;
    build_ChickenHome = temp.build_ChickenHome;
    feed_time_chicken = temp.feed_time_chicken;
    upgrade_CowHome = temp.upgrade_CowHome;
    build_CowHome = temp.build_CowHome;
    feed_time_cow = temp.feed_time_cow;
    upgrade_SheepHome = temp.upgrade_SheepHome;
    build_SheepHome = temp.build_SheepHome;
    feed_time_sheep = temp.feed_time_sheep;
    upgrade_Gandomfarm = temp.upgrade_Gandomfarm;
    Collect_from_GandomFarm = temp.upgrade_Gandomfarm;
    upgrade_Yonjehfarm = temp.upgrade_Gandomfarm;
    Collect_from_YonjehFarm = temp.upgrade_Gandomfarm;
    Build_YonjehFarm = temp.upgrade_Gandomfarm;
    Plow_YonjehFarm = temp.upgrade_Gandomfarm;
    // // // //
    Planting_from_GandomFarm = temp.Planting_from_GandomFarm;
    Planting_from_YonjeFarm = temp.Planting_from_YonjeFarm;



}


void MyThread::run()
{

    forever{
    time_t now = time(NULL);
    int number = 0;

   // qDebug() <<"Mahdi Ghasemi";
    if(last_time_set != 0 && now - last_time_set >= 3600*24){
        number = (now - last_time_set)/(3600*24);
        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+number);


        emit Send_Signal_to_Farm_for_time_login();

//        Data::get_iterator()->get_farm().Set_UI_Attributes();
        last_time_set += number* 3600*24;
    }
    if(upgrade_Storage != 0 && now - upgrade_Storage >= 5*3600*24){

        //QMessageBox::information(nullptr,"","انبار با موفقیت ارتقا پیدا کرد .:)",QMessageBox::Ok);
        qDebug() << "Aref";

        Data::get_iterator()->get_farm().get_storage().Set_Capacity(round(Data::get_iterator()->get_farm().get_storage().GetCapasity() *3 / 2)+1);
        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience() + Data::get_iterator()->get_farm().get_storage().Get_Buliding_Level() * 3);
        Data::get_iterator()->get_farm().get_storage().Set_Bulding_Level(Data::get_iterator()->get_farm().get_storage().Get_Buliding_Level() + 1);        
        emit Send_Signal_to_Farm_for_Upgrade_Storage();
        upgrade_Storage = 0;


    }

    if(upgrade_Siloo != 0 && now - upgrade_Siloo >= 4*3600*24){

//        QMessageBox::information(&Data::get_iterator()->get_farm(),"","سیلو با موفقیت ارتقا پیدا کرد .:)",QMessageBox::Ok);

        Data::get_iterator()->get_farm().get_storage().Set_Capacity(Data::get_iterator()->get_farm().get_storage().GetCapasity() *2);
        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience() + Data::get_iterator()->get_farm().get_storage().Get_Buliding_Level() * 2);
        Data::get_iterator()->get_farm().get_siloo().Set_Bulding_Level(Data::get_iterator()->get_farm().get_siloo().Get_Buliding_Level() + 1);

        upgrade_Siloo = 0;

        emit Send_Signal_to_Farm_for_Upgrade_Siloo();
    }

    for(int i = 0;i < buy_Milk.size(); i++){

        if (now - buy_Milk[i] >= 10 * 24 *3600 ){
            Data::get_iterator()->get_farm().get_storage().Get_milk().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_milk().Get_Number()-1);
        }
    }


    // Aref
    if(upgrade_CowHome != 0 && now - upgrade_CowHome >= 5*3600*24){
        //QMessageBox::information(&Data::get_iterator()->get_farm(),"تبریک","گاوداری با موفقیت ارتقا پیدا کرد",QMessageBox::Ok);
        Data::get_iterator()->get_farm().get_cowHome().set_capacity(Data::get_iterator()->get_farm().get_cowHome().get_level_habitat() +1);
        Data::get_iterator()->get_farm().get_cowHome().set_level_habitat(Data::get_iterator()->get_farm().get_cowHome().get_capacity() *2);
        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+6);
        upgrade_CowHome = 0;
        emit Send_Signal_to_Farm_for_Upgrade_CowHome();
    }

    if(upgrade_ChickenHome != 0 && now - upgrade_ChickenHome >= 3*3600*24){
        //QMessageBox::information(&Data::get_iterator()->get_farm(),"تبریک","مرغداری با موفقیت ارتقا پیدا کرد",QMessageBox::Ok);
        Data::get_iterator()->get_farm().get_chickenHome().set_capacity(Data::get_iterator()->get_farm().get_chickenHome().get_capacity() *2);
        Data::get_iterator()->get_farm().get_chickenHome().set_level_habitat(Data::get_iterator()->get_farm().get_chickenHome().get_level_habitat() +1);
        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+5);
        upgrade_ChickenHome = 0;
        emit Send_Signal_to_Farm_for_Upgrade_ChickenHome();
    }

    if(upgrade_SheepHome != 0 && now - upgrade_SheepHome >= 9*3600*24){
        //QMessageBox::information(&Data::get_iterator()->get_farm(),"تبریک","آغل با موفقیت ارتقا پیدا کرد",QMessageBox::Ok);
        Data::get_iterator()->get_farm().get_sheepHome().set_capacity(Data::get_iterator()->get_farm().get_sheepHome().get_capacity() *2);
        Data::get_iterator()->get_farm().get_sheepHome().set_level_habitat(Data::get_iterator()->get_farm().get_sheepHome().get_level_habitat() +1);
        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+15);
        upgrade_SheepHome = 0;
        emit Send_Signal_to_Farm_for_Upgrade_SheepHome();
    }

    if(build_CowHome != 0 && now - build_CowHome >= 5*3600*24){
        //QMessageBox::information(&Data::get_iterator()->get_farm(),"تبریک","گاوداری با موفقیت ساخته شد",QMessageBox::Ok);
        Data::get_iterator()->get_farm().get_cowHome().set_is_build(true);
        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+10);
        build_CowHome = 0;
        emit Send_Signal_to_Farm_for_Build_CowHome();
    }




    if(build_ChickenHome != 0 && now - build_ChickenHome >= 3*3600*24){
        //QMessageBox::information(nullptr,"تبریک","مرغداری با موفقیت ساخته شد",QMessageBox::Ok);
        Data::get_iterator()->get_farm().get_chickenHome().set_is_build(true);
        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+5);
        build_ChickenHome = 0;
        emit Send_Signal_to_Farm_for_Build_ChickenHome();
    }

    if(build_SheepHome != 0 && now - build_SheepHome >= 10*3600*24){
        //QMessageBox::information(nullptr,"تبریک","آغل با موفقیت ساخته شد",QMessageBox::Ok);
        Data::get_iterator()->get_farm().get_sheepHome().set_is_build(true);
        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+20);
        build_SheepHome = 0;
        emit Send_Signal_to_Farm_for_Build_SheepHome();
    }
    //Arsalan///////
    //build ///
    if(Build_YonjehFarm != 0 && now - Build_YonjehFarm >= 3*3600*24){
        //QMessageBox::information(nullptr,"تبریک","زمین یونجه با موفقیت ساخته شد",QMessageBox::Ok);
        Data::get_iterator()->get_farm().get_yonjeFarm().set_is_build(true);
        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+6);
        emit Send_Signal_to_Farm_for_Build_yonjeFarm();
        Build_YonjehFarm = 0;
    }



    //upgrade
    if(upgrade_Yonjehfarm != 0 && now - upgrade_Yonjehfarm >= 3*3600*24){
       // QMessageBox::information(&Data::get_iterator()->get_farm().get_yonjeFarm(),"تبریک","مزرعه گندم با موفقیت ارتقا یافت",QMessageBox::Ok);
         Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+3*Data::get_iterator()->get_farm().get_yonjeFarm().getarea());
        Data::get_iterator()->get_farm().get_yonjeFarm().set_area(Data::get_iterator()->get_farm().get_yonjeFarm().getarea() *2);
        Data::get_iterator()->get_farm().get_yonjeFarm().set_level(Data::get_iterator()->get_farm().get_yonjeFarm().get_level() +1);
        upgrade_Yonjehfarm = 0;
        emit Send_Signal_to_Farm_for_Upgrade_yonjeFarm();
    }
    if(upgrade_Gandomfarm!=0 && now - upgrade_Gandomfarm >= 2*3600*24){
       // QMessageBox::information(&Data::get_iterator()->get_farm().get_gandomFarm(),"تبریک","مزرعه گندم با موفقیت ارتقا یافت",QMessageBox::Ok);
        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+3*Data::get_iterator()->get_farm().get_gandomFarm().getarea());
        Data::get_iterator()->get_farm().get_gandomFarm().set_area(Data::get_iterator()->get_farm().get_gandomFarm().getarea() *2);
        Data::get_iterator()->get_farm().get_gandomFarm().set_level(Data::get_iterator()->get_farm().get_gandomFarm().get_level() +1);
        upgrade_Gandomfarm = 0;
        emit Send_Signal_to_Farm_for_Upgrade_gandomFarm();
    }



    //derokardan(collect)//
   // if(Planting_from_GandomFarm!=0 && now - Planting_from_GandomFarm>= 2*3600*24){

     //   if(Data::get_iterator()->get_farm().get_siloo().GetCapasity()-Data::get_iterator()->get_farm().get_siloo().Get_Occupied_Capacity()>=2*Data::get_iterator()->get_farm().get_gandomFarm().getarea()){
     //   Data::get_iterator()->get_farm().get_siloo().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_siloo().Get_Occupied_Capacity()+2*Data::get_iterator()->get_farm().get_gandomFarm().getarea());
     //   Data::get_iterator()->get_farm().get_siloo().Get_gandom().Set_Number(Data::get_iterator()->get_farm().get_siloo().Get_gandom().Get_Number()+2*Data::get_iterator()->get_farm().get_gandomFarm().getarea());
      //  QMessageBox::information(&Data::get_iterator()->get_farm().get_gandomFarm(),"تبریک","مزرعه گندم با موفقیت درو شد",QMessageBox::Ok);

     //   Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+1*Data::get_iterator()->get_farm().get_gandomFarm().getarea());
     //  if(Data::get_iterator()->get_experience() >= Data::get_iterator()->get_experience_required_for_levelUp()){
     //      Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
     //      Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
      //     QMessageBox::information(&Data::get_iterator()->get_farm(),"تبریک","سطح شما با موفقیت افزایش یافت");
      // }
     // Planting_from_GandomFarm = 0;
        //}
      //  else{
           //    QMessageBox::information(&Data::get_iterator()->get_farm().get_yonjeFarm(),"تذکر","سیلو ظرفیت ندارد",QMessageBox::Ok);
   // }
      //  }

   // if( Planting_from_YonjeFarm !=0&& now - Planting_from_YonjeFarm>= 4*3600*24){

      //  if(Data::get_iterator()->get_farm().get_storage().GetCapasity()-Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()>=2*Data::get_iterator()->get_farm().get_yonjeFarm().getarea()){
      //  Data::get_iterator()->get_farm().get_storage().Set_Occupied_Capacity(Data::get_iterator()->get_farm().get_storage().Get_Occupied_Capacity()+2*Data::get_iterator()->get_farm().get_yonjeFarm().getarea());
       // Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Set_Number(Data::get_iterator()->get_farm().get_storage().Get_yonjeh().Get_Number()+2*Data::get_iterator()->get_farm().get_yonjeFarm().getarea());
       // QMessageBox::information(&Data::get_iterator()->get_farm().get_gandomFarm(),"تبریک","مزرعه یونجه با موفقیت درو شد",QMessageBox::Ok);

       // Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+1*Data::get_iterator()->get_farm().get_gandomFarm().getarea());
       //if(Data::get_iterator()->get_experience() >= Data::get_iterator()->get_experience_required_for_levelUp()){
         //  Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()-Data::get_iterator()->get_experience_required_for_levelUp());
         //  Data::get_iterator()->set_experience_required_for_levelUp(2*Data::get_iterator()->get_experience_required_for_levelUp()+10);
         //  QMessageBox::information(&Data::get_iterator()->get_farm(),"تبریک","سطح شما با موفقیت افزایش یافت");
      // }
       //Planting_from_YonjeFarm = 0;
       // }
       // else{
          //     QMessageBox::information(&Data::get_iterator()->get_farm().get_yonjeFarm(),"تذکر","سیلو ظرفیت ندارد",QMessageBox::Ok);
    //}
     //   }
    //shokhmzaminyonje(plow)//

    if(Plow_YonjehFarm!=0 && now - Plow_YonjehFarm>= 1*3600*24){
        //QMessageBox::information(&Data::get_iterator()->get_farm().get_yonjeFarm(),"تبریک","مزرعه یونجه با موفقیت شخم زده شد",QMessageBox::Ok);
        Data::get_iterator()->set_experience(Data::get_iterator()->get_experience()+1*Data::get_iterator()->get_farm().get_yonjeFarm().getarea());
        Data::get_iterator()->get_farm().get_yonjeFarm().set_is_plantable(true);
        Plow_YonjehFarm = 0;
        emit Send_Signal_to_Farm_for_plow_yonjeFarm();
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

void MyThread::Set_last_time_set(time_t t){
    last_time_set = t;
}

time_t MyThread::Get_last_time_set(){
    return last_time_set;
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

QVector<time_t>& MyThread::Get_Buy_Milk()
{
    return buy_Milk;
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

void MyThread::Set_feed_time_chicken(time_t t){
     feed_time_chicken = t;
}

time_t MyThread::Get_feed_time_chicken(){
    return feed_time_chicken;
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

void MyThread::Set_feed_time_cow(time_t t){
     feed_time_cow = t;
}

time_t MyThread::Get_feed_time_cow(){
    return feed_time_cow;
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

void MyThread::Set_feed_time_sheep(time_t t){
    feed_time_sheep = t;
}

time_t MyThread::Get_feed_time_sheep(){
    return feed_time_sheep;
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
// // //
void MyThread::Set_planting_Gandomfarm(time_t t){
    Planting_from_YonjeFarm = t;
}

time_t MyThread::Get_planting_Gandomfarm(){
    return Planting_from_YonjeFarm;
}

void MyThread::Set_planting_YonjeFarm(time_t t){
    Planting_from_YonjeFarm = t;
}

time_t MyThread::Get_planting_YonjeFarm(){
    return Planting_from_YonjeFarm;
}
// // //
void MyThread::Set_Plow_YonjehFarm(time_t t){
    Plow_YonjehFarm = t;
}

time_t MyThread::Get_Plow_YonjehFarm(){
    return Plow_YonjehFarm;
}
