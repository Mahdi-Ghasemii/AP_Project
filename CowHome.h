#ifndef COWHOME_H
#define COWHOME_H

#include <QMainWindow>
#include "Habitat.h"

namespace Ui {
class CowHome;
}

class CowHome : public QMainWindow, public Habitat
{
    Q_OBJECT

public:
    explicit CowHome(QWidget *parent = nullptr);
    ~CowHome();
    void operator=(const CowHome&);

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
    Ui::CowHome *ui;
};

#endif // COWHOME_H
