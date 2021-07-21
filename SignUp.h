#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>

namespace Ui {
class SignUp;
}

class SignUp : public QWidget
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

private slots:
    void on_back_pbn_clicked();

    void on_register_pbn_clicked();

private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
