#pragma once
#include <string>
#include "SoldierObject.h"
#include "SFML/graphics.hpp"
#include <unordered_map>
#include "Props.h"

enum class Direction;

class Grid {
private :
	std::string** grid;
	int sizeX, sizeY, _windowSizeScale;
	sf::RenderWindow _battleField;
	int cellWidth;
//	std::unordered_map<Position, sf::RectangleShape*, PositionHasher> _gridCells;

public :
	void createGrid();
	int getSizeY();
	int getSizeX();
	Grid(int x, int y);
	void moveSoldier(Soldier* soldier, Direction direction);
	bool setSoldierOnGrid(int x, int y, Soldier* soldier);
	void loopGrid();
	void setGridCellColor(sf::Color,int x,int y);
	bool SetProps(int x, int y, Props* props);
	~Grid();
};