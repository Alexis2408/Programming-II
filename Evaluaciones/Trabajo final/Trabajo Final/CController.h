#pragma once
#include "CMovementBase.h"
#include "CAgent.h"
#include "CExtra.h"
#include "CHabitant.h"
#include "CAlly.h"
#include "CLeader.h"
#include "CWall.h"
#include "CClock.h"
#include"MyObstacles.h"
#include "CArchivoTexto.h"
#include <vector>
#include <math.h>
#include<ctime>
using namespace std;
class CController
{
private:
	CLeader* leader;
	vector<CAlly*> allies;
	vector<CHabitant*> people;
	vector<CAgent*> agents;
	vector<CExtra*> extras;
	vector<CWall*> walls;
	vector<CClock*> clocks;
	vector<MyObstacles*>vecobstacles;
	int cont, nAllies;
	int timeLimit;
	time_t initialTime;
	int auxdx, auxdy;
	int points;
	bool won;
	int frecuency_extra;
	int auxR;
	int auxB;
	int auxT;
	int auxL;
	bool actionExtra; 
	time_t timetwo;
public:
	CController(int level, Graphics^g);
	~CController();
	void Init(int timeLimit, int nAllies,int nPopulation, int nAgents, Graphics^ g, Bitmap^ LeaderImg,
		Bitmap^ AllyImg, Bitmap^ PersonImg, Bitmap^ AgenteImg, Bitmap^ ExtraImg, Bitmap^ WallImg, 
		Bitmap^ PersonImg1, Bitmap^ PersonImg2, Bitmap^ PersonImg3);
	void Run(Graphics^ g, Bitmap^ LeaderImg, Bitmap^ AllyImg, Bitmap^ PersonImg,
		Bitmap^ AgenteImg, Bitmap^ ExtraImg, Bitmap^ WallImg, Bitmap^ PersonImg1,
		Bitmap^ PersonImg2, Bitmap^ PersonImg3, Bitmap^ Clockimg, Bitmap^ AllyImgInfected,
		Bitmap^ PersonImgInfected, Bitmap^ PersonImg1Infected, Bitmap^ PersonImg2Infected, 
		Bitmap^ PersonImg3Infected, int level);
	void checkCollisions();
	bool collision(Rectangle one, Rectangle two);
	void moveLeader(char t);
	void createWalls(Graphics^ g, Bitmap^ WallImg);
	void createLeader(Graphics^ g, Bitmap^ LeaderImg);
	void createAgents(int nAgents, Graphics^ g, Bitmap^ AgenteImg);
	void createPopulation(int nPopulation, Graphics^ g, Bitmap^ PersonImg);
	void createExtras(Graphics^ g, Bitmap^ ExtraImg, Bitmap^ WallImg, int auxx, int aux2, int auyy, int auyy2);
	void addAlly(Bitmap^ AllyImg, Graphics ^ g);
	bool getWon();
	int getTime();
	int get_score();
};

