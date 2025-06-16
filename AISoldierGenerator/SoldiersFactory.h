#pragma once
#include "SoldierObject.h"

class SoldiersFactory {
public:
    virtual Soldier* createSoldier() = 0;
    virtual ~SoldiersFactory();
};