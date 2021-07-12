#include "Player.h"
#include "ui_Player.h"

Player::Player(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Player)
{
    ui->setupUi(this);

    this->name = "";
    this->username = "";
    this->password = "";
    this->email = "";

    this->level = 1;
    this->experience = 0;
    this->coin = 20;

    this->signUp_time = time(NULL);

    ui->Experience_lbl->setText(QString::number(this->experience));
    ui->Name_lbl->setText(this->name);
    ui->Num_Coins_lbl->setText(QString::number(this->coin));
    ui->UserName_lbl->setText(this->username);
    ui->Level_lbl->setText(QString::number(this->level));

}

Player::~Player()
{
    delete ui;
}

void Player::set_name(QString _name)
{
    name = _name;
}

QString Player::get_name()
{
    return name;
}

void Player::set_username(QString _username)
{
    username = _username;
}

QString Player::get_username()
{
    return username;
}

void Player::set_password(QString _password)
{
    password = _password;
}

QString Player::get_password(){
    return password;
}

void Player::set_email(QString){

}
QString Player::get_email(){
    return email;
}

void Player::set_coin(int _coin){
    coin = _coin;
}

int Player::get_coin(){
    return coin;
}

void Player::set_level(int _level){
    level = _level;
}

int Player::get_level()const{
    return level;
}

void Player::set_experience(int _experience){
    experience = _experience;
}

int Player::get_experience()const{
    return experience;
}

void Player::set_experience_required_for_levelUp(int _e){
    experience_required_for_levelUp = _e;
}

int Player::get_experience_required_for_levelUp(){
    return experience_required_for_levelUp;
}

void Player::set_signUp_time(time_t _signUp_time){
    signUp_time = _signUp_time;
}

time_t Player::get_signUp_time(){
    return signUp_time;
}

Farm& Player::get_farm(){
    return farm;
}











