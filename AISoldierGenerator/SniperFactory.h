#pragma once
#include "SoldierObject.h"
#include "SoldiersFactory.h"

class SniperFactory : public SoldiersFactory {
public:
    Soldier* createSoldier() override;
    ~SniperFactory();
};