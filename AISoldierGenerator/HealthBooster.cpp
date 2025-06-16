#include <iostream>
#include "HealthBooster.h"
HealthBooster::HealthBooster() {
	_powerUpValue = 100;
	_isPowerUpUtilised = false;
	_propType = PropType::HealthBooster;
	_propName = "Health Booster";
}

HealthBooster:: ~HealthBooster()
{

}