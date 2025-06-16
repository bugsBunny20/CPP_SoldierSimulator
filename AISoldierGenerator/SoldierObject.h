#pragma once
#include <string>
#include "Props.h"

class Soldier {
protected:
	float Health = 50.0f;
	int posX = 0;
	int posY = 0;
	float attackRange = 0;
	bool isDead = false;
	int moveSpeed = 1;
	int damage = 50;
	int damageTakenBooster = 0;
	std::string soldierName = "";


public:
	int GetPosX();
	int GetPosY();
	bool GetIsDead();
	int GetMoveSpeed();
	float GetAttackRange();
	std::string GetSoldierName();
	int Attack();
	void TakeDamage(int damage);
	void SetPosition(int x, int y);
	void MoveSoldier();
	virtual void GetPowerUp(PropType propType, int propValue);
	virtual void Print();
	virtual ~Soldier();
};