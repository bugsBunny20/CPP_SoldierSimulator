#include <iostream>
#include "Marine.h"
Marine::Marine() {
	Health = 80.0f;
	attackRange = 50;
	moveSpeed = 10;
	damage = 60;
	damageTakenBooster = 0;
	soldierName = "Marine";
	Print();
}

void Marine::GetPowerUp(PropType propType, int propValue)
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

void Marine::Print() {
	std::cout << "Marine : (Health : " << Health << ") (Attack Range : " << attackRange << ") (Move Speed : " << moveSpeed
		<< ") (Damage : " << damage << ") (Armor booster : " << damageTakenBooster << ")" << std::endl;
}

Marine:: ~Marine()
{

}