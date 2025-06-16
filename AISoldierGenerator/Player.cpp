#include <iostream>
#include "HandleSoldiers.h"
#include "SoldierObject.h"
#include "SoldiersFactory.h"
#include "Player.h"
#include "Grid.h"

Player::Player() {
	handleSoldiers;
}

Player::~Player()
{
	for (int i = 0; i < armyCount; i++) 
	{
		delete army[i];
	}
	delete[] army;
}

void Player::SetSoldierPosition(Grid* grid,int minY) {
	handleSoldiers.setSoldiers(grid,army,minY,armyCount);
}

int Player::GetArmyCount()
{
	return armyCount;
}

Soldier* Player::GetSoldier(int index)
{
	if(index<armyCount)
		return army[index];
}

void Player::SetArmyCount(int count)
{
	armyCount = count;
	army = new Soldier * [armyCount];
}

Soldier** Player::GetArmy()
{
	return army;
}
