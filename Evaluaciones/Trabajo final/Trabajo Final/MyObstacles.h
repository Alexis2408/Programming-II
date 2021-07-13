#pragma once
using namespace System::Drawing;
class MyObstacles
{
private:
	int x, y, width, heigth;
public:
	MyObstacles(int x, int y, int width,int heigth);
	~MyObstacles();
	void mostrar(Graphics^g);
	Rectangle getRectangle();
};

