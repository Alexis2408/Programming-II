#pragma once
#include "CMovementBase.h"
class CClock :
    public CMovementBase
{
public:
    CClock(int w, int h, Graphics^ g);
    ~CClock();  
    void showv2(Graphics^ g, Bitmap^ img);
};

