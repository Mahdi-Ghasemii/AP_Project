#ifndef DATA_H
#define DATA_H

#include <QList>
#include "Player.h"

class Data
{
private:
    static QList<Player>::iterator it;
    static QList<Player> players;

public:
    static void set_iterator(QList<Player>::iterator _it){ it=_it; }

    static QList<Player>::iterator& get_iterator(){ return it; }

    static void set_players(QList<Player> _players){ players=_players; }

    static QList<Player>& set_players(){ return players; }

    static void write_on_file();
};

#endif // DATA_H
