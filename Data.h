#ifndef DATA_H
#define DATA_H

#include <QVector>
#include "Player.h"
#include <fstream>
#include <iostream>

using namespace std;


class Data
{
private:
    static QVector<Player>::iterator it;
    static QVector<Player> players;

public:
    static void set_iterator(QVector<Player>::iterator _it){ it=_it; }

    static QVector<Player>::iterator& get_iterator(){ return it; }

    static void set_players(QVector<Player>& _players){ players=_players; }

    static QVector<Player>& get_players() { return players; }


    static void write_on_file() {
        ofstream f("Players.txt");
        for (int i = 0; i < Data::players.size(); i++)
            f.write((char*)&Data::players[i], sizeof(Data::players[i]));
    }
};

#endif // DATA_H
