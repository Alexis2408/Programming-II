#include "CHabitant.h"

CHabitant::CHabitant(int w, int h, Graphics^ g) : CMovementBase(g, w, h)
{
	infected = false;
	health = 5000;
}

CHabitant::~CHabitant()
{
	delete clock;
}

void CHabitant::move(Graphics^ g)
{
	idX++;
	if (idX == 4)
		idX = 0;
}

void CHabitant::set_ethnicity(int nuevo)
{
	this->ethnicity = nuevo;
}

int CHabitant::get_ethnicity()
{
	return this->ethnicity;
}

void CHabitant::set_infected(bool New)
{
	infected = New;
}

int CHabitant::get_infected()
{
	return infected;
}

void CHabitant::add_clock(int xc,int yc,int wc, int hc, Graphics^ g)
{
	clock = new CClock(wc, hc, g);
	clock->set_x(xc + w - 10);
	clock->set_y(yc+10);
}

void CHabitant::delete_clock()
{
	delete this->clock;
}

CClock* CHabitant::get_clock()
{
	return clock;
}

void CHabitant::set_health(int New)
{
	this->health = New;
}

int CHabitant::get_health()
{
	return this->health;
}

