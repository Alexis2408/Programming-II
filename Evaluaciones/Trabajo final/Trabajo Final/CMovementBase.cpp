#include "CMovementBase.h"
CMovementBase::CMovementBase(int w, int h)
{
	ezoom = 1.0;
	idX = idY = 0;
	this->w = w;
	this->h = h;
	dx = dy = 0;
}

CMovementBase::CMovementBase(Graphics^ g,int w,int h)
{
	int auxX = int(g->VisibleClipBounds.Width);
	int auxY = int(g->VisibleClipBounds.Height);
	this->w = w;
	this->h = h;
	ezoom = 1.0;
	x = rand() % ((auxX - w) + 1);
	y = rand() % ((auxY - h) + 1);
	idX = idY = dx = dy = 0;
}

CMovementBase::~CMovementBase()
{

}

void CMovementBase::show(Graphics^ g, Bitmap^ bmp)
{
	Rectangle sectionShow = Rectangle(w * idX, h * idY, w, h);
	Rectangle zoom = Rectangle(x, y, w*ezoom, h*ezoom);
	g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
}

void CMovementBase::move(Graphics^ g)
{

}

void CMovementBase::init(Graphics^ g, Bitmap^ bmp)
{
}

void CMovementBase::set_x(int New)
{
	this->x = New;
}

void CMovementBase::set_y(int New)
{
	this->y = New;
}

void CMovementBase::set_dx(int New)
{
	this->dx = New;
}

void CMovementBase::set_dy(int New)
{
	this->dy = New;
}

void CMovementBase::set_idX(int New)
{
	this->idX = New;
}

void CMovementBase::set_idY(int New)
{
	this->idY = New;
}

int CMovementBase::get_x()
{
	return this->x;
}

int CMovementBase::get_y()
{
	return this->y;
}

int CMovementBase::get_dx()
{
	return this->dx;
}

int CMovementBase::get_dy()
{
	return this->dy;
}

int CMovementBase::get_w()
{
	return this->w;
}

int CMovementBase::get_h()
{
	return this->h;
}

int CMovementBase::get_idX()
{
	return this->idX;
}

int CMovementBase::get_idY()
{
	return this->idY;
}

void CMovementBase::stop()
{
	dx = dy = 0;
}

void CMovementBase::reposicionar(Graphics^ g, CMovementBase* New)
{
	x=(rand() % ((int(g->VisibleClipBounds.Width) - New->get_w() * 2 - New->get_w() + 1)) + New->get_w());
	y=(rand() % ((int(g->VisibleClipBounds.Height) - New->get_h() * 2 - New->get_h() + 1)) + New->get_h());
}

Rectangle CMovementBase::getfutrec()
{
	int toleranciax = 30;
	int toleranciay = 15;
	return Rectangle(x + dx+toleranciax, y + dy+toleranciay,
		(w*ezoom )- (toleranciax * 2), (h*ezoom) - (toleranciay * 2));
}

Rectangle CMovementBase::getRec()
{
	return Rectangle(x,y,w*ezoom,h*ezoom);
}