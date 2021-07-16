#ifndef RANKING_H
#define RANKING_H

#include <QMainWindow>
#include <algorithm>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QString>
#include <QPixmap>
#include <QPalette>


namespace Ui {
class Ranking;
}

class Ranking : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ranking(QWidget *parent = nullptr);
    ~Ranking();

    void operator=(const Ranking&);

private:
    Ui::Ranking *ui;

    void design();

public slots:
    void Get_Signal_From_Farm();

signals:
    void Send_Signal_to_Farm();
};

#endif // RANKING_H
