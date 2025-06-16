#include <iostream>
#include "SoldiersFactory.h"
#include "MarineFactory.h"
#include "Marine.h"

Soldier* MarineFactory::createSoldier()
{
    return new Marine();
}
MarineFactory :: ~MarineFactory()
{

}
