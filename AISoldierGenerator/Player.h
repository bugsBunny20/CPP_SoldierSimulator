#pragma once
#include "HandleSoldiers.h"
#include "SoldierObject.h"
#include "SoldiersFactory.h"
#include "Grid.h"

class Player {
	HandleSoldiers handleSoldiers;
	int armyCount;
	Soldier** army;

public:
	Player();
	~Player();
	
	void SetSoldierPosition(Grid* grid,int minY);
	int GetArmyCount();
	Soldier* GetSoldier(int index);
	void SetArmyCount(int count);
	Soldier** GetArmy();
};