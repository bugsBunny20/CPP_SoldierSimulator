#pragma once
#include "SoldierObject.h"
#include "SoldiersFactory.h"
#include "Grid.h"


class HandleSoldiers {

private:
	   int typeOfSoldiersAvailable;
	   SoldiersFactory* sniperFactory;
	   SoldiersFactory* greenBeretFactory;
	   SoldiersFactory* marineFactory;
	   SoldiersFactory* spyFactory;

public:
	HandleSoldiers();
	void createSoldiers(Soldier** army,int armyCount);
	void setSoldiers(Grid* grid, Soldier** army, int minY, int armyCount);
	void moveSoldier(Grid* grid, Soldier* soldier, int moveY, int direction);
	void deleteSoldiers(Soldier** army);
};