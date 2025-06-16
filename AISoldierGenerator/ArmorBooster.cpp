#include <iostream>
#include "ArmorBooster.h"
ArmorBooster::ArmorBooster() {
	_powerUpValue = 20;
	_isPowerUpUtilised = false;
	_propType = PropType::ArmorBooster;
	_propName = "Armor Booster";
}

ArmorBooster:: ~ArmorBooster()
{

}