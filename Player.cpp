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


    ui->Experience_lbl->setText(QString::number(this->experience));
    ui->Name_lbl->setText(this->name);
//    ui->Num_Coins_lbl->setText(QString::number(this->coin));
    ui->UserName_lbl->setText(this->username);
    ui->Level_lbl->setText(QString::number(this->level));

}

Player::Player(const Player& p){
    operator=(p);
}

Player::~Player()
{
    //delete ui;
}

void Player::operator=(const Player& p){
    name = p.name;
    username = p.username;
    password = p.password;
    email = p.email;
    coin = p.coin;
    level = p.level;
    experience = p.experience;
    experience_required_for_levelUp = p.experience_required_for_levelUp;
    farm = p.farm;
}

void Player::set_name(QString _name)
{
    name = _name;
}

QString Player::get_name()const
{
    return name;
}

void Player::set_username(QString _username)
{
    username = _username;
}

QString Player::get_username()const
{
    return username;
}

void Player::set_password(QString _password)
{
    password = _password;
}

QString Player::get_password()const{
    return password;
}

void Player::set_email(QString _email){
    email = _email;
}
QString Player::get_email()const{
    return email;
}

void Player::set_coin(int _coin){
    coin = _coin;
}

int Player::get_coin()const{
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

int Player::get_experience_required_for_levelUp()const{
    return experience_required_for_levelUp;
}



Farm& Player::get_farm(){
    return farm;
}


