#ifndef HABITAT_H
#define HABITAT_H

#include <string>
#include <time.h>
#include <Storage.h>
#include <list>
#include <QMessageBox>

using namespace std;

class Habitat
{
protected:
    int capacity;
    int stock_animal;
    int level_habitat;
    time_t feed_time;
    bool is_collected;

public:
    Habitat();
    void set_capacity(int _capacity);
    int get_capacity();
    void set_stock_animal(int _stock_animal);
    int get_stock_animal();
    void set_level_habitat(int _level_habitat);
    int get_level_habitat();
    void set_feed_time(time_t _feed_time);
    time_t get_feed_time();
};

#endif // HABITAT_H
