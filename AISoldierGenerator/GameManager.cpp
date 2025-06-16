#include <iostream>
#include <string>
#include "GameManager.h"
#include "Grid.h"
#include "Player.h"
#include "HandleSoldiers.h"
#include "HandleProps.h"

GameManager::GameManager()
{
	isExit = 'N';
	turnEnded;

	x1 = 0;
	x2 = 0;
	y1 = 0;
	y2 = 0;

	distance = 0.0f;
	handleSoldiers = new HandleSoldiers();
	handleProps = new HandleProps();

}

void GameManager::createGrid()
{
	std::cout << "***** Creating Grid: *****" << std::endl;
	grid = new Grid(60, 60);
}

void GameManager::createPlayers()
{
	std::cout << "Enter Number of Players : " << std::endl;
	std::cin >> numberOfPlayers;
	std::cout << "***** Creating players: *****" << std::endl;
	players = new Player[numberOfPlayers];

	for (int i = 0; i < numberOfPlayers; i++) {
		int armyCount = 0;
		std::cout << "Enter Army Count for Player " << i+1 <<" : " << std::endl;
		std::cin >> armyCount;
		players[i].SetArmyCount(armyCount);
	}
}

void GameManager::createArmy()
{
	for (int i = 0; i < numberOfPlayers; i++)
	{
		std::cout << std::endl << "***** Creating army for player: " << i + 1 << " *****" << std::endl;
		handleSoldiers->createSoldiers(players[i].GetArmy(), players[i].GetArmyCount());
	}

	for (int i = 0; i < numberOfPlayers; i++)
	{
		std::cout << std::endl << "***** Setting army on grid for player: " << i + 1 << " *****" << std::endl;
		if (i % 2) 
		{
			handleSoldiers->setSoldiers(grid, players[i].GetArmy(), 0, players[i].GetArmyCount());
		}
		else
		{
			handleSoldiers->setSoldiers(grid, players[i].GetArmy(), grid->getSizeY() / 2, players[i].GetArmyCount());
		}
	}
}

void GameManager::startAttack()
{
	do
	{
		for (int i = 0; i < numberOfPlayers; i++)
		{
			std::cout << std::endl << "***** Player "<< i+1 <<" army attacking *****" << std::endl;
			int outerLoopCount{ 0 };
			int innerLoopCount{ 0 };
			Soldier** currentAttackers;
			Soldier** currentDiffenders;

			if (i==0) 
			{
				outerLoopCount = players[0].GetArmyCount();
				innerLoopCount = players[1].GetArmyCount();
				currentAttackers = players[0].GetArmy();
				currentDiffenders = players[1].GetArmy();
			}
			else 
			{
				outerLoopCount = players[1].GetArmyCount();
				innerLoopCount = players[0].GetArmyCount();
				currentAttackers = players[1].GetArmy();
				currentDiffenders = players[0].GetArmy();
			}

			for (int j = 0; j < outerLoopCount; j++)
			{
				Soldier* attackerSoldier = currentAttackers[j];
				if (!attackerSoldier->GetIsDead()) {
					for (int k = 0; k < innerLoopCount; k++)
					{
						Soldier* defenderSoldier = currentDiffenders[k];
						if (!defenderSoldier->GetIsDead())
						{
							x1 = attackerSoldier->GetPosX();
							y1 = attackerSoldier->GetPosY();

							x2 = defenderSoldier->GetPosX();
							y2 = defenderSoldier->GetPosY();

							distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
							if (attackerSoldier->GetAttackRange() >= distance) {
								int attackPower = attackerSoldier->Attack();
								defenderSoldier->TakeDamage(attackPower);

								std::cout << attackerSoldier->GetSoldierName() << " gave damage to " << defenderSoldier->GetSoldierName()<< " : " << attackPower << std::endl;
								turnEnded = true;
								break;
							}
						}
					}
					if (turnEnded) {
						turnEnded = false;
						break;
					}
				}
				
			}
			
		}

		moveSoldiers();
		std::cout << "\nDo you want to end the game ? Y/N : " << std::endl;
		std::cin >> isExit;
	} while (isExit != 'Y' && isExit != 'y');
}

void GameManager::createProps()
{
	std::cout << std::endl << "***** Creating and setting powerups: *****" << std::endl;
	handleProps->CreateProps();
	handleProps->SetProps(grid);
}

void GameManager::moveSoldiers()
{
	for (int i = 0; i < numberOfPlayers; i++) 
	{
		std::cout << std::endl << "***** Moving army for player: " << i + 1 << " *****" << std::endl;
		Soldier** army = players[i].GetArmy();
		int armyCount = players[i].GetArmyCount();
		int direction = i == 0 ? 1 : -1;
		for (int j = 0; j < armyCount; j++) 
		{
			int moveY = army[j]->GetMoveSpeed();
			handleSoldiers->moveSoldier(grid, army[j], moveY, direction);
		}
	}
	CheckForProp();
}

void GameManager::CheckForProp()
{
	for (int i = 0; i < numberOfPlayers; i++)
	{
		std::cout << std::endl << "***** Player " << i + 1 << " army checking for power ups *****" << std::endl;
		int armyCount = players[i].GetArmyCount();
		for (int j = 0; j < armyCount; j++)
		{
			Soldier* currentSoldier = players[i].GetSoldier(j);
			if (!currentSoldier->GetIsDead()) {
				int propCount = handleProps->GetPropsCount();
				for (int k = 0; k < propCount; k++)
				{
					Props* prop = handleProps->GetProp(k);
					if (!prop->GetIsPowerUpUtilised())
					{

						x1 = currentSoldier->GetPosX();
						y1 = currentSoldier->GetPosY();

						x2 = prop->GetPosX();
						y2 = prop->GetPosY();
						distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
						if (currentSoldier->GetAttackRange() >= distance)
						{
							prop->SetIsPowerUpUtilised(true);
							currentSoldier->GetPowerUp(prop->GetPropType(), prop->PowerUpValue());
							std::string propType = prop->GetPropName();
							std::string soldierType = currentSoldier->GetSoldierName();
							std::cout << "Player" << i + 1 << " " << soldierType << " got a power up : " << propType << std::endl;
							break;
						}
					}
				}
			}
		}
	}
}

GameManager::~GameManager()
{
	delete grid;
	delete[] players;
	delete handleSoldiers;
	delete handleProps;
}
