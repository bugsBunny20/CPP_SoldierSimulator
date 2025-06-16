#include <iostream>
#include "Spy.h"

Spy::Spy() {
	Health = 60.0f;
	attackRange = 20;
	moveSpeed = 1;
	damage = 70;
	damageTakenBooster = 0;
	soldierName = "Spy";
	Print();
}
void Spy::GetPowerUp(PropType propType, int propValue)
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

void Spy::Print() {
	std::cout << "Spy : (Health : " << Health << ") (Attack Range : " << attackRange << ") (Move Speed : " << moveSpeed
		<< ") (Damage : " << damage << ") (Armor booster : " << damageTakenBooster << ")" << std::endl;
}

Spy:: ~Spy()
{

}