#ifndef RANKING_H
#define RANKING_H

#include <QWidget>

namespace Ui {
class Ranking;
}

class Ranking : public QWidget
{
    Q_OBJECT

public:
    explicit Ranking(QWidget *parent = nullptr);
    ~Ranking();

    void operator=(const Ranking&);

private:
    Ui::Ranking *ui;

public slots:
    void show_ranking();

signals:
    void back_to_farm();
};

#endif // RANKING_H
