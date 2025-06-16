#pragma once
#include "SoldierObject.h"
#include "SoldiersFactory.h"

class SpyFactory : public SoldiersFactory {
public:
    Soldier* createSoldier() override;
    ~SpyFactory();
};