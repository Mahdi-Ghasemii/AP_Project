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

private:
    Ui::Ranking *ui;
};

#endif // RANKING_H
