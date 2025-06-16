#pragma once
#include "SoldierObject.h"
#include "Props.h"
class GreenBeret : public Soldier {
public:	GreenBeret();
	  void GetPowerUp(PropType propType, int propValue);
	  void Print();
	  ~GreenBeret();
};