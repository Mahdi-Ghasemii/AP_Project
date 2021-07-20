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
    bool is_build;

public:
    Habitat();
    void set_capacity(int _capacity);
    int get_capacity();
    void set_stock_animal(int _stock_animal);
    int get_stock_animal();
    void set_level_habitat(int _level_habitat);
    int get_level_habitat();
    bool get_is_build();
    void set_is_build(bool _is_build);
};

#endif // HABITAT_H
