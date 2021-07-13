#pragma once
#include "CMovementBase.h"
using namespace std;
class CLeader:
    public CMovementBase
{
private:
    int score;
public:
    CLeader(int w, int h, Graphics^ g);
    ~CLeader();
    void move(Graphics^ g);
    void set_score(int New);
    int get_score();
};

