#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include <QString>
#include "Farm.h"

namespace Ui {
class Player;
}

class Player : public QMainWindow
{
    Q_OBJECT

public:
    explicit Player(QWidget *parent = nullptr);
    Player(const Player&);
    ~Player();
    void operator=(const Player&);

    void set_name(QString);
    QString get_name()const;

    void set_username(QString);
    QString get_username()const;

    void set_password(QString);
    QString get_password()const;

    void set_email(QString);
    QString get_email()const;

    void set_coin(int);
    int get_coin()const;

    void set_level(int);
    int get_level()const;

    void set_experience(int);
    int get_experience()const;

    void set_experience_required_for_levelUp(int);
    int get_experience_required_for_levelUp()const;

    Farm& get_farm();

private:
    Ui::Player *ui;

    QString name;
    QString username;
    QString password;
    QString email;
    int coin;
    int level;
    int experience;
    int experience_required_for_levelUp;
//    time_t signUp_time;
    Farm farm;
};

#endif // PLAYER_H

