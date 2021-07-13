#include "Ranking.h"
#include "ui_Ranking.h"
#include "Data.h"
#include "Player.h"
#include <algorithm>

bool sort_players(const Player&, const Player&);

Ranking::Ranking(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ranking)
{
    ui->setupUi(this);
    std::sort(Data::get_players().begin(), Data::get_players().end(), sort_players);

}

Ranking::~Ranking()
{
    delete ui;
}


bool sort_players(const Player& p1, const Player& p2) {
    if (p1.get_level() > p2.get_level())
        return true;
    if (p1.get_level() == p2.get_level())
        if (p1.get_experience() > p2.get_experience())
            return true;
    return false;
}
