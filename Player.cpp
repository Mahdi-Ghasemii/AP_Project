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

Player::Player(const Player& p){
    operator=(p);
}

Player::~Player()
{
    //delete ui;
}

void Player::operator=(const Player& p){
    name = p.get_name();
    username = p.get_username();
    password = p.get_password();
    email = p.get_email();
    coin = p.get_coin();
    level = p.get_level();
    experience = p.get_experience();
    experience_required_for_levelUp = p.get_experience_required_for_levelUp();
    signUp_time = p.get_signUp_time();
    //farm = p.get_farm();
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

void Player::set_signUp_time(time_t _signUp_time){
    signUp_time = _signUp_time;
}

time_t Player::get_signUp_time()const{
    return signUp_time;
}

Farm& Player::get_farm(){
    return farm;
}
