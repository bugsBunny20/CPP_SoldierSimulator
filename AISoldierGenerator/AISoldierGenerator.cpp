#include <iostream>
#include "GameManager.h"

using namespace std;

int main()
{
    GameManager* gameManager = new GameManager();
    gameManager->createGrid();
    gameManager->createPlayers();
    gameManager->createArmy();
    gameManager->createProps();
    gameManager->startAttack();

    delete gameManager;

    return 0;
}