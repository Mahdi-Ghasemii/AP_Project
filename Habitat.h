#ifndef HABITAT_H
#define HABITAT_H

#include <QMainWindow>
#include <string>
#include <time.h>
#include <Storage.h>
#include <list>
using namespace std;

namespace Ui {
class Habitat;
}

class Habitat : public QMainWindow
{
    Q_OBJECT

public:
    Habitat();
    void upgrade();
    void feedeing();
    void collect();
    void set_capacity(int _capacity);
    int get_capacity();
    void set_stock_animal(int _stock_animal);
    int get_stock_animal();
    void set_level_habitat(int _level_habitat);
    int get_level_habitat();
    void set_feed_time(time_t _feed_time);
    time_t get_feed_time();
    void set_type(string _type);


private:
    Ui::Habitat *ui;

    string type;
    int capacity;
    int stock_animal;
    int level_habitat;
    time_t feed_time;
};

#endif // HABITAT_H