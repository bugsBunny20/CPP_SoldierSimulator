#pragma once
#include "Props.h"

enum class PropType;

class PropsFactory {
public:
    Props* CreateProp(PropType propType);
    ~PropsFactory();
};