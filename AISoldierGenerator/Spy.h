#pragma once
#include "SoldierObject.h"
#include "Props.h"
class Spy : public Soldier {
public:	Spy();
	  void GetPowerUp(PropType propType, int propValue);
	  void Print();
	  ~Spy();
};