#include <iostream>
#include "AttackBooster.h"
AttackBooster::AttackBooster() {
	_powerUpValue = 30;
	_isPowerUpUtilised = false;
	_propType = PropType::AttackBooster;
	_propName = "Attack Booster";
}

AttackBooster:: ~AttackBooster()
{

}