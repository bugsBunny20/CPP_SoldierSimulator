#pragma once
#include "SoldierObject.h"
#include "SoldiersFactory.h"

class MarineFactory : public SoldiersFactory {
public:
    Soldier* createSoldier() override;
    ~MarineFactory();
};