#ifndef BUILTING_H
#define BUILTING_H

#include <QMainWindow>
#include <QString>
namespace Ui {
class Builting;
}

class Builting : public QMainWindow
{
    Q_OBJECT

public:
    explicit Builting(QWidget *parent = nullptr);
    ~Builting();

private slots:
    void on_yes_btn_clicked();

    void on_no_btn_clicked();

signals:
    void Send_Signal_to_Farm(QString);

private:
    Ui::Builting *ui;

};

#endif // BUILTING_H
