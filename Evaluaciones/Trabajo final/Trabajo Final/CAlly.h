#pragma once
#include "CHabitant.h"
#include "CMovementBase.h"
#include "CClock.h"
class CAlly :
    public CMovementBase
{
private:
    int movAuxdx, movAuxdy;
    int pursued, help;
    CClock* clock;
public:
    CAlly(int w, int h, Graphics^ g);
    ~CAlly();
    void move(Graphics^ g, CHabitant* habitant);
    int get_mAuxdx();
    int get_mAuxdy();
    void set_pursued(int New);
    int get_pursued();
    void set_help(int New);
    int get_help();
    void add_clock(int w, int h, Graphics^ g, int x, int y);
    CClock* get_clock();
};

