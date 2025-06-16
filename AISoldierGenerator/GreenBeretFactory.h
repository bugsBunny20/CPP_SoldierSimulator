#pragma once
#include "SoldierObject.h"
#include "SoldiersFactory.h"

class GreenBeretFactory : public SoldiersFactory {
public:
    Soldier* createSoldier() override;
    ~GreenBeretFactory();
};