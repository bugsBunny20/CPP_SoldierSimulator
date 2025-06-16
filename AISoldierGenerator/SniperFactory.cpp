#include <iostream>
#include "SoldiersFactory.h"
#include "SniperFactory.h"
#include "Sniper.h"

Soldier* SniperFactory::createSoldier()
{
    return new Sniper();
}
SniperFactory :: ~SniperFactory()
{

}