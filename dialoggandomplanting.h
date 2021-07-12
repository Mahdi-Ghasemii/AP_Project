#ifndef DIALOGGANDOMPLANTING_H
#define DIALOGGANDOMPLANTING_H

#include <QDialog>

namespace Ui {
class DialogGandomPlanting;
}

class DialogGandomPlanting : public QDialog
{
    Q_OBJECT

public:
    explicit DialogGandomPlanting(QWidget *parent = nullptr);
    ~DialogGandomPlanting();

private slots:
    void on_buttonBox_accepted();


signals:
    void plantingareawanting(int);

private:
    Ui::DialogGandomPlanting *ui;
};

#endif // DIALOGGANDOMPLANTING_H
