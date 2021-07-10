#include "Player.h"

Player::Player()
{
    this->name = "";
    this->username = "";
    this->password = "";
    this->email = "";

    this->level = 1;
    this->experience = 0;
    this->coin = 0;

    this->signUp_time = time(NULL);

}

