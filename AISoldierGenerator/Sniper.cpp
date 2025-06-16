#include <iostream>
#include "Sniper.h"
Sniper::Sniper() {
	Health = 50.0f;
	attackRange = 150;
	moveSpeed = 2;
	damage = 100;
	damageTakenBooster = 0;
	soldierName = "Sniper";
	Print();
}

void Sniper::GetPowerUp(PropType propType, int propValue)
{
	switch (propType)
	{
	case PropType::HealthBooster:
		Health += propValue;;
	case PropType::ArmorBooster:
		damageTakenBooster = propValue;
	case PropType::AttackBooster:
		damage += propValue;
	}
}

void Sniper::Print() {
	std::cout << "Sniper : (Health : " << Health << ") (Attack Range : " << attackRange << ") (Move Speed : " << moveSpeed
		<< ") (Damage : " << damage << ") (Armor booster : " << damageTakenBooster << ")" << std::endl;
}

Sniper:: ~Sniper()
{

}

