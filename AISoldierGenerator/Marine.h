#pragma once
#include "SoldierObject.h"
#include "Props.h"
class Marine : public Soldier {
public:Marine();
	  void GetPowerUp(PropType propType, int propValue);
	  void Print();
	  ~Marine();
};