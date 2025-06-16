#include <iostream>
#include <time.h>
#include "SoldiersFactory.h"
#include "SniperFactory.h"
#include "GreenBeretFactory.h"
#include "MarineFactory.h"
#include "SpyFactory.h"
#include "SoldierObject.h"
#include "HandleSoldiers.h"
#include "Grid.h"

HandleSoldiers::HandleSoldiers() {
	typeOfSoldiersAvailable = 4;
	sniperFactory = new SniperFactory();
	greenBeretFactory = new GreenBeretFactory();
	marineFactory = new MarineFactory();
	spyFactory = new SpyFactory();
}

void HandleSoldiers::createSoldiers(Soldier** army, int armyCount)
{
	
	srand(time(0));

	for (int j = 0; j < armyCount; j++)
	{
		int randomSeed = (rand() % typeOfSoldiersAvailable)+1;
		Soldier* soldier = NULL;
		switch (randomSeed)
		{
		case 1 :
			soldier = sniperFactory->createSoldier();
			break;
		case 2:
			soldier = greenBeretFactory->createSoldier();
			break;
		case 3:
			soldier = marineFactory->createSoldier();
			break;
		case 4:
			soldier = spyFactory->createSoldier();
			break;
		}
		if (soldier != NULL) 
		{
			army[j] = soldier;
		}
	}
}

void HandleSoldiers::setSoldiers(Grid* grid, Soldier** army, int minY, int armyCount)
{
	srand(time(0));
	bool isSoldierSet;
	
	for (int i = 0; i < armyCount; i++)
	{
		int posX = (rand() % grid->getSizeX()) + 1;
		int posY = (rand() % (grid->getSizeY()-minY)) + minY;
		isSoldierSet = grid->setSoldierOnGrid(posX, posY,army[i]);
		if (!isSoldierSet) 
		{
			i--;
		}
		else
		{
			std::cout << army[i]->GetSoldierName() << " set to : (" << posX << "," << posY << ")" << std::endl;
		}
	}
}

void HandleSoldiers::moveSoldier(Grid* grid, Soldier* soldier, int moveY, int direction)
{
	int oldPosX = soldier->GetPosX();
	int oldPosY = soldier->GetPosY();

	int posX = soldier->GetPosX();
	int posY = soldier->GetPosY();

	bool isNextCellEmpty;
	for (int i = 1; i < moveY; i++) 
	{
		posY +=i;
		isNextCellEmpty = grid->setSoldierOnGrid(posX, posY, soldier);
		if (!isNextCellEmpty)
		{
			break;
		}
	}
	std::cout << soldier->GetSoldierName() << " moved from (" << oldPosX << "," << oldPosY << ") to ( " << posX << "," << posY << ")" << std::endl;
}

void HandleSoldiers::deleteSoldiers(Soldier** army)
{
	delete sniperFactory;
	delete greenBeretFactory;
	delete marineFactory;
	delete spyFactory;
}