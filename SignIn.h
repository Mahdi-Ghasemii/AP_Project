#ifndef SIGNIN_H
#define SIGNIN_H

#include <QWidget>
#include "Data.h"


namespace Ui {
class SignIn;
}

class SignIn : public QWidget
{
    Q_OBJECT

public:
    explicit SignIn(QWidget *parent = nullptr);
    ~SignIn();

private slots:
    void on_sign_up_pbn_clicked();

    void on_sign_in_pbn_clicked();

private:
    Ui::SignIn *ui;
};

#endif // SIGNIN_H
