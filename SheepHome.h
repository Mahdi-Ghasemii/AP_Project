#ifndef SHEEPHOME_H
#define SHEEPHOME_H

#include <QMainWindow>
#include "Habitat.h"

namespace Ui {
class SheepHome;
}

class SheepHome : public QMainWindow, public Habitat
{
    Q_OBJECT

public:
    explicit SheepHome(QWidget *parent = nullptr);
    ~SheepHome();
    void operator=(const SheepHome&);
    void build();

private slots:
    void on_upgrade_btn_clicked();

    void on_feeding_btn_clicked();

    void on_collect_btn_clicked();

    void on_back_btn_clicked();

    //  get signals from Farm class :
    void Get_Signal_From_Farm();

signals:
    void Send_Signal_to_Farm();

private:
    Ui::SheepHome *ui;
};

#endif // SHEEPHOME_H
