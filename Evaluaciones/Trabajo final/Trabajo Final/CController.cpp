#include "CController.h"
CController::CController(int level, Graphics^g)
{
	actionExtra = false;
	timetwo = time(0);
	cont = 0;
	won = false;
	initialTime= time(0);
	points = 0;
	frecuency_extra = 0;
	auxR = g->VisibleClipBounds.Right;
	auxB = g->VisibleClipBounds.Bottom;
	auxT = g->VisibleClipBounds.Top;
	auxL = g->VisibleClipBounds.Left;
	vecobstacles = vector<MyObstacles*>();
	CArchivoTexto* obja = new CArchivoTexto();
	vector<vector<int>>datos = obja->LeerObstaculos("obs.txt");
	if (level == 1)
	{
		for (int i = 0; i < 22; i++)
		{
			vecobstacles.push_back(new MyObstacles(datos.at(i).at(0), datos.at(i).at(1), datos.at(i).at(2), datos.at(i).at(3)));
		}
	}
	else {
		for (int i = 23; i < 48; i++)
		{
			vecobstacles.push_back(new MyObstacles(datos.at(i).at(0), datos.at(i).at(1), datos.at(i).at(2), datos.at(i).at(3)));
		}
		}
}

CController::~CController(){
	while (allies.size())
	{
		vecobstacles.erase(vecobstacles.begin());
		delete allies.at(0);
	}
	while (people.size())
	{
		people.erase(people.begin());
		delete people.at(0);
	}
	while (agents.size())
	{
		agents.erase(agents.begin());
		delete people.at(0);
	}
	while (extras.size())
	{
		extras.erase(extras.begin());
		delete extras.at(0);
	}
	while (walls.size())
	{
		walls.erase(walls.begin());
		delete walls.at(0);
	}
	while (vecobstacles.size())
	{
		vecobstacles.erase(vecobstacles.begin());
		delete walls.at(0);
	}
}

void CController::Init(int timeLimit, int nAllies,int nPopulation, int nAgents,Graphics^ g, Bitmap^ LeaderImg, Bitmap^ AllyImg, Bitmap^ PersonImg, Bitmap^ AgenteImg, Bitmap^ ExtraImg, Bitmap^ WallImg, Bitmap^ PersonImg1, Bitmap^ PersonImg2, Bitmap^ PersonImg3)
{
	this->timeLimit = timeLimit;
	this->nAllies = nAllies;
	auxdx=0;
	auxdy = 0;
	createWalls(g, WallImg);
	createLeader(g, LeaderImg);
	createAgents(nAgents, g, AgenteImg);
	createPopulation(nPopulation, g, PersonImg);
	createExtras(g, ExtraImg, WallImg, auxR, auxL, auxB, auxT);
	//Reposision
	for (int i = 0; i < agents.size(); i++)
	{
		//Agente con leader
		do {
			leader->reposicionar(g, walls.at(0));
		} while (collision(leader->getRec(), agents.at(i)->getRec()));

	}
	for (int k = 0; k < vecobstacles.size(); k++)
	{
		//leader con obstaculos
		while (collision(leader->getRec(), vecobstacles[k]->getRectangle())) {
			k = 0;
			leader->reposicionar(g, walls[0]);
			while ((leader->getRec().X > vecobstacles.at(k)->getRectangle().X &&
				leader->getRec().X < vecobstacles.at(k)->getRectangle().X + vecobstacles.at(k)->getRectangle().Width) ||
				(leader->getRec().Y > vecobstacles.at(k)->getRectangle().Y &&
					leader->getRec().Y < vecobstacles.at(k)->getRectangle().Y + vecobstacles.at(k)->getRectangle().Height))
			{
				leader->reposicionar(g, walls.at(0));
			}
		}
	}
}


void CController::Run(Graphics^ g, Bitmap^ LeaderImg, Bitmap^ AllyImg, Bitmap^ PersonImg,
	Bitmap^ AgenteImg, Bitmap^ ExtraImg, Bitmap^ WallImg, Bitmap^ PersonImg1,
	Bitmap^ PersonImg2, Bitmap^ PersonImg3, Bitmap^ Clockimg, Bitmap^ AllyImgInfected,
	Bitmap^ PersonImgInfected, Bitmap^ PersonImg1Infected, Bitmap^ PersonImg2Infected,
	Bitmap^ PersonImg3Infected, int level)
{
	time_t currentTime = time(0);
	for (int i = 0; i < walls.size(); i++)
	{
		walls.at(i)->show(g, WallImg);
	}
	auxdx = leader->get_dx();
	auxdy = leader->get_dy();
	for (int i = 0; i < walls.size(); i++)
	{

		if (collision(leader->getfutrec(), walls.at(i)->getRec()))
		{
			leader->stop();
		}
	}
	if (collision(leader->getfutrec(), agents.at(0)->getRec()))
	{
		leader->stop();
	}
	for (int i = 0; i < vecobstacles.size(); i++)
	{
		if (collision(leader->getfutrec(), vecobstacles.at(i)->getRectangle()))
		{
			leader->stop();
		}
	}
	for (int i = 0; i < extras.size(); i++)
	{
		extras.at(i)->move(g, level);
		for (int j = 0; j < walls.size(); j++)
		{
			if (collision(extras.at(i)->getRec(), walls.at(j)->getRec()))
			{
				if (extras.at(i)->get_dy() < 0 && extras.at(i)->get_y() < g->VisibleClipBounds.Height / 2)
				{
					extras.at(i)->set_dy(extras.at(i)->get_dy() * -1);
					if (rand() % (2) + 1 == 1)
						extras.at(i)->set_dx(extras.at(i)->get_dx() * -1);
					break;
				}
				if (extras.at(i)->get_dx() > 0 && extras.at(i)->get_x() > g->VisibleClipBounds.Width / 2)
				{
					extras.at(i)->set_dx(extras.at(i)->get_dx() * -1);	break;
				}
				if (extras.at(i)->get_dy() > 0 && extras.at(i)->get_y() > g->VisibleClipBounds.Height / 2)
				{
					extras.at(i)->set_dy(extras.at(i)->get_dy() * -1);
					if (rand() % (2) + 1 == 1)
						extras.at(i)->set_dx(extras.at(i)->get_dx() * -1);
					break;
				}
				if (extras.at(i)->get_dx() < 0 && extras.at(i)->get_x() < g->VisibleClipBounds.Width / 2)
				{
					extras.at(i)->set_dx(extras.at(i)->get_dx() * -1);	break;
				}
			}
		}
		extras.at(i)->move(g, level);
		extras.at(i)->show(g, ExtraImg);
	}
	if (difftime(currentTime, timetwo) >= 8)
	{
		timetwo = time(0);
		actionExtra = !actionExtra;
	}
	if (actionExtra)
	{
		for (int i = 0; i < extras.size(); i++)
		{
			for (int j = 0; j < people.size(); j++)
			{
				if (collision(extras.at(i)->getRec(), people.at(j)->getRec()) && people.at(j)->get_infected() == false)
				{
					people.at(j)->set_infected(true);
					people.at(j)->add_clock(people.at(j)->get_x(), people.at(j)->get_y(), Clockimg->Width / 6, Clockimg->Height, g);
					if (level == 2)
					{
						for (int k = 0; k < 3; k++)
						{
							extras.at(i)->boom();
							extras.at(i)->show(g, ExtraImg);
						}
					}
					extras.erase(extras.begin() + i);
					break;
				}
			}
		}
	}
	leader->move(g);
	leader->show(g, LeaderImg);

	for (int i = 0; i < people.size(); i++)
	{
		if (collision(leader->getRec(),people.at(i)->getRec()) && people.at(i)->get_infected())
		{
			people.at(i)->delete_clock();
			people.at(i)->set_health(5000);
			people.at(i)->set_infected(false);
		}
	}
	
	for (int i = 0; i < allies.size(); i++)
	{
		allies.at(i)->move(g, people.at(allies.at(i)->get_pursued()));
		allies.at(i)->show(g, AllyImg);
		if (collision(allies.at(i)->getRec(), people.at(allies.at(i)->get_pursued())->getRec()))
		{
			if (allies.at(i)->get_help() == 2000)
			{
				allies.at(i)->add_clock(Clockimg->Width / 6, Clockimg->Height, g, people.at(allies.at(i)->get_pursued())->get_x() + people.at(allies.at(i)->get_pursued())->get_w(), people.at(allies.at(i)->get_pursued())->get_y() + 10);
			}
			allies.at(i)->set_help(allies.at(i)->get_help() - 100);
			allies.at(i)->get_clock()->showv2(g, Clockimg);
			if (allies.at(i)->get_help() == 0)//CURADA EXITOSA
			{
				people.erase(people.begin() + allies.at(i)->get_pursued());
				allies.erase(allies.begin() + i);
				leader->set_score(leader->get_score() + 10);
			}
		}
	}
	
	//Cambiar imagen habitantes
	for (int i = 0; i < people.size(); i++)
	{
		switch (people.at(i)->get_ethnicity())
		{
		case 1: people.at(i)->get_infected() ? people.at(i)->show(g, PersonImgInfected) :
			people.at(i)->show(g, PersonImg); break;
		case 2: people.at(i)->get_infected() ? people.at(i)->show(g, PersonImg1Infected) :
			people.at(i)->show(g, PersonImg1); break;
		case 3: people.at(i)->get_infected() ? people.at(i)->show(g, PersonImg2Infected) :
			people.at(i)->show(g, PersonImg2); break;
		case 4: people.at(i)->get_infected() ? people.at(i)->show(g, PersonImg3Infected) :
			people.at(i)->show(g, PersonImg3); break;
		default:
			break;
		}
		if (people.at(i)->get_infected())
		{
			people.at(i)->get_clock()->showv2(g, Clockimg);
			people.at(i)->set_health(people.at(i)->get_health() - 100);
			if (people.at(i)->get_health() <= 0)
			{
				//people.at(i)->delete_clock(); ////
				people.erase(people.begin() + i);
				leader->set_score(leader->get_score() - 3);
			}
		}
	}

	if (allies.size() > 0)
	{
		for (int i = 0; i < agents.size(); i++)
		{
			float distancia = 0.0;
			int posicion = 0;
			distancia = sqrt((pow((agents.at(i)->get_x() - allies.at(0)->get_x()), 2)) + (pow((agents.at(i)->get_y() - allies.at(0)->get_y()), 2)));
			for (int j = 1; j < allies.size(); j++)
			{
				if (sqrt((pow((agents.at(i)->get_x() - allies.at(j)->get_x()), 2)) + (pow((agents.at(i)->get_y() - allies.at(j)->get_y()), 2))) < distancia)
				{
					distancia = sqrt((pow((agents.at(i)->get_x() - allies.at(j)->get_x()), 2)) + (pow((agents.at(i)->get_y() - allies.at(j)->get_y()), 2)));
					posicion = j;
				}
			}
			for (int j = 0; j < walls.size(); j++)
			{
				if (collision(agents.at(i)->getRec(), walls.at(j)->getRec()))
				{
					agents.at(i)->changeDirection();
					break;
				}
			}
			for (int k = 0; k < vecobstacles.size(); k++)
			{
				if (collision(vecobstacles.at(k)->getRectangle(), agents.at(i)->getRec()))
				{
					agents.at(i)->changeDirection();
					break;
				}
			}
			if (collision(leader->getRec(), agents.at(i)->getfutrec()))
			{
				if (agents.at(i)->get_dy() < 0 && agents.at(i)->get_y() < g->VisibleClipBounds.Height / 2)
				{
					agents.at(i)->set_dy(agents.at(i)->get_dy() * -1);
					if (rand() % (2) + 1 == 1)
						agents.at(i)->set_dx(agents.at(i)->get_dx() * -1);

				}
				if (agents.at(i)->get_dx() > 0 && agents.at(i)->get_x() > g->VisibleClipBounds.Width / 2)
				{
					agents.at(i)->set_dx(agents.at(i)->get_dx() * -1);
				}
				if (agents.at(i)->get_dy() > 0 && agents.at(i)->get_y() > g->VisibleClipBounds.Height / 2)
				{
					agents.at(i)->set_dy(agents.at(i)->get_dy() * -1);
					if (rand() % (2) + 1 == 1)
						agents.at(i)->set_dx(agents.at(i)->get_dx() * -1);

				}
				if (agents.at(i)->get_dx() < 0 && agents.at(i)->get_x() < g->VisibleClipBounds.Width / 2)
				{
					agents.at(i)->set_dx(agents.at(i)->get_dx() * -1);
				}
				agents.at(i)->move(g, WallImg, nullptr, false);
				agents.at(i)->show(g, AgenteImg);
			}
			else
			{
				agents.at(i)->move(g, WallImg, allies.at(posicion), true);
				agents.at(i)->show(g, AgenteImg);
			}
			if (collision(agents.at(i)->getRec(), allies.at(posicion)->getRec()))
			{
				allies.erase(allies.begin() + posicion);
				leader->set_score(leader->get_score() - 5);
				break;
			}
			
		}
	}
	else
	{
		//Valida que el agente no se salga del frame cuando no persigue a ningún aliado
		for (int i = 0; i < agents.size(); i++)
		{
			
			for (int j = 0; j < walls.size(); j++)
			{
				if (collision(agents.at(i)->getRec(), walls.at(j)->getRec()))
				{
					agents.at(i)->changeDirection();	
					break;
				}
			}
			for (int j = 0; j < vecobstacles.size(); j++)
			{
				if (collision(vecobstacles.at(j)->getRectangle(), agents.at(i)->getRec()))
				{
					agents.at(i)->changeDirection();
					break;
				}
			}
			if (collision(leader->getRec(), agents.at(i)->getfutrec()))
			{
				if (agents.at(i)->get_dy() < 0 && agents.at(i)->get_y() < g->VisibleClipBounds.Height / 2)
				{
					agents.at(i)->set_dy(agents.at(i)->get_dy() * -1);
					if (rand() % (2) + 1 == 1)
						agents.at(i)->set_dx(agents.at(i)->get_dx() * -1);

				}
				if (agents.at(i)->get_dx() > 0 && agents.at(i)->get_x() > g->VisibleClipBounds.Width / 2)
				{
					agents.at(i)->set_dx(agents.at(i)->get_dx() * -1);
				}
				if (agents.at(i)->get_dy() > 0 && agents.at(i)->get_y() > g->VisibleClipBounds.Height / 2)
				{
					agents.at(i)->set_dy(agents.at(i)->get_dy() * -1);
					if (rand() % (2) + 1 == 1)
						agents.at(i)->set_dx(agents.at(i)->get_dx() * -1);

				}
				if (agents.at(i)->get_dx() < 0 && agents.at(i)->get_x() < g->VisibleClipBounds.Width / 2)
				{
					agents.at(i)->set_dx(agents.at(i)->get_dx() * -1);
				}
				agents.at(i)->move(g, WallImg, nullptr, false);
				agents.at(i)->show(g, AgenteImg);
				//	break;
			}
			else
			{
				agents.at(i)->move(g, WallImg, nullptr, false);
				agents.at(i)->show(g, AgenteImg);
			}
		}
	}
	frecuency_extra++;
	if (frecuency_extra > 100 && extras.size() < 3)
	{
		frecuency_extra = 0;
		CExtra* Extra = new CExtra((ExtraImg->Width / 4) * 1.0, (ExtraImg->Height / 4) * 1.0, g);
		Extra->reposicionar(g, walls.at(0));
		for (int k = 0; k < walls.size(); k++)
		{
			if (collision(Extra->getRec(), walls.at(k)->getRec()) || collision(Extra->getRec(), leader->getRec()))
			{
				Extra->set_x(rand() % ((auxR - WallImg->Width / 4 - Extra->get_w()) - (auxL + WallImg->Width / 4) + 1) - (auxL + WallImg->Width / 4));
				Extra->set_y(rand() % ((auxB - WallImg->Height / 4 - Extra->get_h()) - (auxT + WallImg->Height / 4) + 1) - (auxT + WallImg->Height / 4));
				k = 0;
			}
		}
		extras.push_back(Extra);
	}
	if (difftime(currentTime, initialTime) >= 1)
	{
		if (timeLimit > 0)
			timeLimit--;
	}
	if (cont >= nAllies && allies.size() == NULL)
	{
		timeLimit = 0;
	}
	if (get_score() >= 100)
		won = true;
}

void CController::checkCollisions()
{
}

bool CController::collision(Rectangle one, Rectangle two)
{
	return one.IntersectsWith(two);
}

void CController::moveLeader(char t)
{
	if (t == 'A')
	{
		leader->set_dx(-20);
		leader->set_dy(0);
	}
	if (t == 'S') 
	{
		leader->set_dy(15);
		leader->set_dx(0);
	}
	if (t == 'D')
	{
		leader->set_dx(20);
		leader->set_dy(0);
	}
	if (t == 'W')
	{
		leader->set_dy(-15);
		leader->set_dx(0);
	}
}

void CController::createWalls(Graphics^ g, Bitmap^ WallImg)
{
	for (int i = g->VisibleClipBounds.Top; i < g->VisibleClipBounds.Bottom; i += (WallImg->Height / 4))
	{
		for (int j = g->VisibleClipBounds.Left; j <= g->VisibleClipBounds.Right; j += (WallImg->Width / 4))
		{
			if (i == g->VisibleClipBounds.Top || i == g->VisibleClipBounds.Bottom - WallImg->Height / 4 || j == g->VisibleClipBounds.Left || j == g->VisibleClipBounds.Right - WallImg->Height / 4)
			{
				CWall* Wall = new CWall(WallImg->Width / 4, WallImg->Height / 4);
				Wall->set_x(j);
				Wall->set_y(i);
				Wall->set_idX(3);
				Wall->set_idY(2);
				walls.push_back(Wall);
			}

		}
	}
}

void CController::createLeader(Graphics^ g, Bitmap^ LeaderImg)
{
	leader = new CLeader(LeaderImg->Width / 4, LeaderImg->Height / 4, g);
	leader->set_x(walls.at(0)->get_w() + rand() % 30);
	leader->set_y(walls.at(0)->get_h() + rand() % 30);
}

void CController::createAgents(int nAgents, Graphics^ g, Bitmap^ AgenteImg)
{
	for (int i = 0; i < nAgents; i++)
	{
		CAgent* Agent = new CAgent(AgenteImg->Width / 4, AgenteImg->Height / 4, g);
		for (int j = 0; j < walls.size(); j++)
		{
			if (collision(Agent->getRec(), walls.at(j)->getRec()))
			{
				Agent->set_x(rand() % ((int(g->VisibleClipBounds.Width) - walls.at(0)->get_w() * 2 - Agent->get_w() + 1)) + walls.at(0)->get_w());
				Agent->set_y(rand() % ((int(g->VisibleClipBounds.Height) - walls.at(0)->get_h() * 2 - Agent->get_h() + 1)) + walls.at(0)->get_h());
				j = 0;
			}
		}
		agents.push_back(Agent);
	}
	for (int i = 0; i < agents.size(); i++)
	{
		for (int j = 0; j < vecobstacles.size(); j++)
		{
			while (collision(agents.at(i)->getRec(), vecobstacles.at(j)->getRectangle()))
			{
				j = 0;
				agents.at(i)->reposicionar(g, walls.at(0));
				while ((agents.at(i)->getRec().X > vecobstacles.at(j)->getRectangle().X &&
					agents.at(i)->getRec().X < vecobstacles.at(j)->getRectangle().X + vecobstacles.at(j)->getRectangle().Width) ||
					(agents.at(i)->getRec().Y > vecobstacles.at(j)->getRectangle().Y &&
						agents.at(i)->getRec().Y < vecobstacles.at(j)->getRectangle().Y + vecobstacles.at(j)->getRectangle().Height))
				{
					agents.at(i)->reposicionar(g, walls.at(0));
				}
			}
		}
	}
}

void CController::createPopulation(int nPopulation, Graphics^ g, Bitmap^ PersonImg)
{
	for (int i = 0; i < nPopulation; i++)
	{
		CHabitant* Person;
		int rand1 = rand() % (4) + 1;
		Person = new CHabitant(PersonImg->Width / 4, PersonImg->Height / 4, g);
		Person->set_ethnicity(rand1);
		Person->set_x(rand() % ((int(g->VisibleClipBounds.Width) - walls.at(0)->get_w() * 2 - Person->get_w() + 1)) + walls.at(0)->get_w());
		Person->set_y(rand() % ((int(g->VisibleClipBounds.Height) - walls.at(0)->get_h() * 2 - Person->get_h() + 1)) + walls.at(0)->get_h());
		people.push_back(Person);
	}
	for (int i = 0; i < people.size(); i++)
	{
		for (int j = 0; j < vecobstacles.size(); j++)
		{

			while (collision(people[i]->getRec(), vecobstacles[j]->getRectangle()))
			{
				j = 0;
				people[i]->reposicionar(g, walls[0]);
				for (int k = i + 1; k < people.size(); k++)
				{

					do {
						people[i]->reposicionar(g, walls[0]);
					} while (collision(people.at(i)->getRec(), people.at(k)->getRec()));
				}
				while ((people.at(i)->getRec().X > vecobstacles.at(j)->getRectangle().X &&
					people.at(i)->getRec().X < vecobstacles.at(j)->getRectangle().X + vecobstacles.at(j)->getRectangle().Width) ||
					(people.at(i)->getRec().Y > vecobstacles.at(j)->getRectangle().Y &&
						people.at(i)->getRec().Y < vecobstacles.at(j)->getRectangle().Y + vecobstacles.at(j)->getRectangle().Height))
				{
					people[i]->reposicionar(g, walls[0]);
					for (int k = i + 1; k < people.size(); k++)
					{

						do {
							people[i]->reposicionar(g, walls[0]);
						} while (collision(people.at(i)->getRec(), people.at(k)->getRec()));
					}
				}
			}
		}
	}
}

void CController::createExtras(Graphics^ g, Bitmap^ ExtraImg, Bitmap ^WallImg, int auxx, int aux2, int auyy, int auyy2)
{
	for (int i = 0; i < rand() % 5 + 1; i++)
	{
		CExtra* Extra = new CExtra((ExtraImg->Width / 4)*1 , (ExtraImg->Height / 4)*1, g);	
		Extra->set_x(rand() % ((auxx - WallImg->Width / 4 - Extra->get_w()) - (aux2 + WallImg->Width / 4) + 1) - (aux2 + WallImg->Width / 4));
		Extra->set_y(rand() % ((auyy - WallImg->Height / 4 - Extra->get_h()) - (auyy2 + WallImg->Height / 4) + 1) - (auyy2 + WallImg->Height / 4));
		for (int k = 0; k < walls.size(); k++)
		{
			if (collision(Extra->getRec(), walls.at(k)->getRec()) || collision(Extra->getRec(), leader->getRec()))
			{
					Extra->set_x(rand() % ((auxx - WallImg->Width / 4 - Extra->get_w()) - (aux2 + WallImg->Width / 4) + 1) - (aux2 + WallImg->Width / 4));
					Extra->set_y(rand() % ((auyy - WallImg->Height / 4 - Extra->get_h()) - (auyy2 + WallImg->Height / 4) + 1) - (auyy2 + WallImg->Height / 4));
					k = 0;
			}
		}
		extras.push_back(Extra);
	}
}

void CController::addAlly(Bitmap^ AllyImg, Graphics ^ g)
{
	if (cont < nAllies)
	{
		CAlly* Ally = new CAlly(AllyImg->Width / 4, AllyImg->Height / 4, g);
		Ally->set_x(rand() % ((int(g->VisibleClipBounds.Width) - walls.at(0)->get_w() * 2 + 1)) + walls.at(0)->get_w());
		Ally->set_y(rand() % ((int(g->VisibleClipBounds.Height) - walls.at(0)->get_h() * 2 + 1)) + walls.at(0)->get_h());
		float distance;
		distance = sqrt(pow((people.at(0)->get_x() - leader->get_x()), 2) + pow((people.at(0)->get_y() - leader->get_y()), 2));
		for (int i = 1; i < people.size(); i++)
		{
			if (sqrt(pow((people.at(i)->get_x() - leader->get_x()), 2) + pow((people.at(i)->get_y() - leader->get_y()), 2)) < distance)
			{
				distance = sqrt(pow((people.at(i)->get_x() - leader->get_x()), 2) + pow((people.at(i)->get_y() - leader->get_y()), 2));
				Ally->set_pursued(i);
			}
		}
		allies.push_back(Ally);
		cont++;
		/*for (int i = 0; i < allies.size(); i++)
		{
			for (int j = 0; j < vecobstacles.size(); j++)
			{
				if (collision(allies.at(i)->getRec(), vecobstacles.at(j)->getRectangle()))
				{
					j = 0;
					if ((allies.at(i)->getRec().X > vecobstacles.at(j)->getRectangle().X &&
						allies.at(i)->getRec().X < vecobstacles.at(j)->getRectangle().X + vecobstacles.at(j)->getRectangle().Width) ||
						(allies.at(i)->getRec().Y > vecobstacles.at(j)->getRectangle().Y &&
							allies.at(i)->getRec().Y < vecobstacles.at(j)->getRectangle().Y + vecobstacles.at(j)->getRectangle().Height))
					{
						allies.at(i)->reposicionar(g, walls.at(0));
					}
				}
			}
		}*/
	}
	
}

bool CController::getWon()
{
	return this->won;
}

int CController::getTime()
{
	return timeLimit;
}

int CController::get_score()
{
	if (leader->get_score() < 0)
		leader->set_score(0);
	return leader->get_score();
}
