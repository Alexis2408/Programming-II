#pragma once
#include "CMovementBase.h"
class CExtra :
    public CMovementBase
{
public:
    CExtra(int w,int h, Graphics^g);
    ~CExtra();
    void move(Graphics^ g, int level);
    void boom();
};

