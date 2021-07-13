#pragma once
#include "CMovementBase.h"
#include "CClock.h"
class CHabitant :
    public CMovementBase
{
private:
    int ethnicity;
    bool infected;
    CClock* clock;
    int health;
public:
    CHabitant(int w, int h, Graphics^ g);
    ~CHabitant();
    void move(Graphics^ g);
    void set_ethnicity(int nuevo);
    int get_ethnicity();
    void set_infected(bool New);
    int get_infected();
    void add_clock(int xc, int yc, int wc, int hc, Graphics^ g);
    void delete_clock();
    CClock* get_clock();
    void set_health(int New);
    int get_health();
};

