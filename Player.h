#ifndef PLAYER_H
#define PLAYER_H


#include <string>
#include "Farm.h"

using namespace std;

class Player
{
    string name;
    string username;
    string password;
    string email;
    int coin;
    int level;
    int experience;
    time_t signUp_time;
    Farm farm;

public:
    Player();

    void set_name(string);
    string get_name();

    void set_username(string);
    string get_username();

    void set_password(string);
    string get_password();

    void set_email(string);
    string get_email();

    void set_coin(int);
    int get_coin();

    void set_level(int);
    int get_level();

    void set_experience(int);
    int get_experience();


    void set_signUp_time(time_t);
    time_t get_signUp_time();

    void set_farm(Farm);
    Farm get_farm();

    static void write_on_file();

};


#endif // PLAYER_H
