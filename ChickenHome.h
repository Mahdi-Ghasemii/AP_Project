#ifndef CHICKENHOME_H
#define CHICKENHOME_H

#include <QMainWindow>
#include "Habitat.h"

namespace Ui {
class ChickenHome;
}

class ChickenHome : public QMainWindow, public Habitat
{
    Q_OBJECT

public:
    explicit ChickenHome(QWidget *parent = nullptr);
    ~ChickenHome();
    void operator=(const ChickenHome&);
    void build();

private slots:
    void on_upgrade_btn_clicked();

    void on_feeding_btn_clicked();

    void on_collect_btn_clicked();

    void on_back_btn_clicked();

    // get signals from Farm class :
    void Get_Signal_From_Farm();

signals:
    void Send_Signal_to_Farm();

private:
    Ui::ChickenHome *ui;
};

#endif // CHICKENHOME_H
