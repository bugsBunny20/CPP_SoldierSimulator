#pragma once
#include "SoldierObject.h"
#include "Props.h"
class Sniper : public Soldier {
public:	Sniper();
	  void GetPowerUp(PropType propType, int propValue);
	  void Print();
	  ~Sniper();
};