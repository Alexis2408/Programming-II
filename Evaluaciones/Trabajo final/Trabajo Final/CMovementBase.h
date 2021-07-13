#pragma once
#include<iostream>
using namespace System::Drawing;
class CMovementBase
{
protected:
	int x, y, dx, dy, w, h, idX, idY;
	float ezoom;
public:
	CMovementBase(int w, int h);
	CMovementBase(Graphics^ g,int w,int h);
	~CMovementBase();
	virtual void show(Graphics^ g, Bitmap^ bmp);
	virtual void move(Graphics^ g);
	void init(Graphics^ g, Bitmap^ bmp);
	void set_x(int New);
	void set_y(int New);
	void set_dx(int New);
	void set_dy(int New);
	void set_idX(int New);
	void set_idY(int New);
	int get_x();
	int get_y();
	int get_dx();
	int get_dy();
	int get_w();
	int get_h();
	int get_idX();
	int get_idY();
	void stop();
	void reposicionar(Graphics^g, CMovementBase * New);
	Rectangle getfutrec();
	Rectangle getRec();
};

