#ifndef PROFILE_H
#define PROFILE_H

#include <QMainWindow>
#include <QString>



namespace Ui {
class Profile;
}

class Profile : public QMainWindow
{
    Q_OBJECT

public:
    explicit Profile(QWidget *parent = nullptr);
    ~Profile();

private:
    Ui::Profile *ui;
};

#endif // PROFILE_H
