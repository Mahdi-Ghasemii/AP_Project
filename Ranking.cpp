#include "Ranking.h"
#include "ui_Ranking.h"
#include "Data.h"
#include "Player.h"
#include <QString>
#include <QDebug>



bool sort_players(const Player&, const Player&);

Ranking::Ranking(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ranking)
{
    ui->setupUi(this);
    setFixedSize(480, 580);
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


void Ranking::Get_Signal_From_Farm() {
    QString uname = Data::get_iterator()->get_username();
    std::sort(Data::get_players().begin(), Data::get_players().end(), sort_players);
    for (int i = 0; i < Data::get_players().size(); i++) {
        if (uname == Data::get_players()[i].get_username()) {
            Data::set_iterator(Data::get_players().begin() + i);
            break;
        }
    }
    setWindowTitle("رتبه بندی");

    design();

}

void Ranking::operator=(const Ranking &) {

}

void Ranking::design()
{

    //QFont

    QTableWidget* table = new QTableWidget(this);
    table->setRowCount(Data::get_players().size());
    table->setColumnCount(4);

    table->setAlternatingRowColors(true);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setShowGrid(false);

    table->horizontalHeader()->setVisible(false);
    table->horizontalHeader()->setStretchLastSection(true);
    table->horizontalHeader()->setDefaultSectionSize(120);

    table->verticalHeader()->setVisible(false);

    //----------set items--------------
    QTableWidgetItem* item;
    for (int i = 0, j = 1; i < Data::get_players().size(); i++) {
        for (int k = 0; k < 4; k++) {
            item = new QTableWidgetItem;
            if (k == 0)
                item->setText("رتبه " + QString::number(j));
            if (k == 1) {
                if (Data::get_players()[i].get_username() == Data::get_iterator()->get_username()) {
                    item->setText("(شما)" + Data::get_players()[i].get_username());
                }
                else {
                    item->setText(Data::get_players()[i].get_username());
                }
            }
            if (k == 2)
                item->setText("سطح : " + QString::number(Data::get_players()[i].get_level()));
            if (k == 3)
                item->setText("تجربه : " + QString::number(Data::get_players()[i].get_experience()));
            item->setTextAlignment(Qt::AlignRight);
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            table->setItem(i, 3 - k, item);
        }
        if (i != Data::get_players().size() - 1)
            if ((Data::get_players()[i].get_level() != Data::get_players()[i + 1].get_level()) ||
                    (Data::get_players()[i].get_experience() != Data::get_players()[i + 1].get_experience()))
                j++;
    }



    this->setCentralWidget(table);
}
