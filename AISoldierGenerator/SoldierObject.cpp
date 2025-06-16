#include <iostream>
#include "SoldierObject.h"
#include "Props.h"

Soldier :: ~Soldier()
{
    std::cout << "Deleteing soldier object" << std::endl;
}

int Soldier::GetPosX()
{
    return posX;
}

int Soldier::GetPosY()
{
    return posY;
}

bool Soldier::GetIsDead()
{
    return isDead;
}

int Soldier::GetMoveSpeed()
{
    return moveSpeed;
}

float Soldier::GetAttackRange()
{
    return attackRange;
}

std::string Soldier::GetSoldierName()
{
    return soldierName;
}

int Soldier::Attack()
{
    if (!isDead) {
        return damage;
    }
    else
    {
        return 0;
    }
}

void Soldier::TakeDamage(int damage)
{
    if (!isDead) {
        Health -= (damage- damageTakenBooster);
    }
    if (Health <= 0) {
        isDead = true;
    }
}

void Soldier::SetPosition(int x, int y)
{
    posX = x;
    posY = y;
}

void Soldier::MoveSoldier()
{
    posY += moveSpeed;
    SetPosition(posX, posY);
}

void Soldier::GetPowerUp(PropType propType, int propValue) {

}

void Soldier::Print()
{
}
