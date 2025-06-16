#pragma once
#include "Grid.h"
#include "Player.h"
#include "HandleSoldiers.h"
#include "HandleProps.h"

class GameManager {
private:
	Player* players;
	Grid* grid;
	HandleSoldiers* handleSoldiers;
	HandleProps* handleProps;
	int numberOfPlayers;
	char isExit;
	bool turnEnded;

	int x1 = 0;
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;

	float distance = 0.0f;


public:
	GameManager();
	void CheckForProp();
	void createGrid();
	void createPlayers();
	void createArmy();
	void startAttack();
	void createProps();
	void moveSoldiers();
	~GameManager();
};
