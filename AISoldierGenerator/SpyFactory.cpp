#include <iostream>
#include "SoldiersFactory.h"
#include "SpyFactory.h"
#include "Spy.h"


Soldier* SpyFactory::createSoldier()
{
    return new Spy();
}
SpyFactory :: ~SpyFactory()
{

}
