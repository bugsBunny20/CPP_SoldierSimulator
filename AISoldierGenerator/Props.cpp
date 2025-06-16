#include <iostream>
#include "Props.h"

void Props::SetIsPowerUpUtilised(bool poweUpUsed)
{
    _isPowerUpUtilised= poweUpUsed;
}

Props :: ~Props()
{
    std::cout << "Deleteing prop object" << std::endl;
}

int Props::GetPosX()
{
    return posX;
}

int Props::GetPosY()
{
    return posY;
}

PropType Props::GetPropType() {
    return _propType;
}

std::string Props::GetPropName()
{
    return _propName;
}

int Props::PowerUpValue()
{
    return _powerUpValue;
}

bool Props::GetIsPowerUpUtilised()
{
    return _isPowerUpUtilised;
}

void Props::SetPosition(int x, int y)
{
    posX = x;
    posY = y;
}
