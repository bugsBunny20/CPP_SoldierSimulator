#include <iostream>
#include "GreenBeret.h"
GreenBeret::GreenBeret() {
	Health = 100.0f;
	attackRange = 30;
	moveSpeed = 5;
	damage = 80;
	damageTakenBooster = 0;
	soldierName = "Green Beret";
	Print();
}

void GreenBeret::GetPowerUp(PropType propType, int propValue)
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

void GreenBeret::Print() {
	std::cout << "Green Beret : (Health : " << Health << ") (Attack Range : " << attackRange << ") (Move Speed : " << moveSpeed
		<< ") (Damage : " << damage << ") (Armor booster : " << damageTakenBooster << ")" << std::endl;
}

GreenBeret:: ~GreenBeret()
{

}