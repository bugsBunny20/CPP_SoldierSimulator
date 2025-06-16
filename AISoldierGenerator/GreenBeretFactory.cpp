#include <iostream>
#include "SoldiersFactory.h"
#include "GreenBeretFactory.h"
#include "GreenBeret.h"

Soldier* GreenBeretFactory::createSoldier()
{
    return new GreenBeret();
}
GreenBeretFactory :: ~GreenBeretFactory()
{
   
}