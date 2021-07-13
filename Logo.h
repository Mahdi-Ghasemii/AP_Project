#ifndef LOGO_H
#define LOGO_H

#include <QMainWindow>
#include <windows.h>

namespace Ui {
class Logo;
}

class Logo : public QMainWindow
{
    Q_OBJECT

public:
    explicit Logo(QWidget *parent = nullptr);
    ~Logo();

private:
    Ui::Logo *ui;
};

#endif // LOGO_H
