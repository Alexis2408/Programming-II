#pragma once
#include "CMovementBase.h"
class CWall :
    public CMovementBase
{
private:
    int frecuence;
public:
    CWall(int w,int h);
    ~CWall();
    void show(Graphics^ g, Bitmap^ bmp);
};

