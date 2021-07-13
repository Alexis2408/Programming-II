#pragma once
#include "CMovementBase.h"
#include "CAlly.h"
class CAgent :
    public CMovementBase
{
private:
    int frequency;
public:
    CAgent(int w, int h, Graphics^ g);
    ~CAgent();
    void move(Graphics^ g, Bitmap^ WallImg, CAlly* ally, bool exist);
    void changeDirection();

};

