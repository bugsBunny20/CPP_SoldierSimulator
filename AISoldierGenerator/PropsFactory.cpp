#include <iostream>
#include "PropsFactory.h"
#include "Props.h"
#include "HealthBooster.h"
#include "ArmorBooster.h"
#include "AttackBooster.h"

Props* PropsFactory::CreateProp(PropType propType) 
{
    switch (propType)
    {
    case PropType::HealthBooster:
        return new HealthBooster();
    case PropType::ArmorBooster:
        return new ArmorBooster();
    case PropType::AttackBooster:
        return new AttackBooster();
    default:
        return nullptr;
    }
}

PropsFactory :: ~PropsFactory()
{
    std::cout << "Deleteing props factory" << std::endl;
}
